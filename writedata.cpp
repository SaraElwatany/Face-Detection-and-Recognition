#include "writedata.h"




// Write all necessary test data as text files (Mean, Facesdata, EigenVectors, ProjectedFaces)
WriteData::WriteData(MyPCA PCA, vector<string> &FacesID)
{

    project(PCA);   // The empty constructor will load the text file that has ID & path for each image & perform PCA on them & store the value by default
    writeTrainFacesData(FacesID);
    writeMean(PCA.getAverage());
    writeEigen(PCA.getEigenvectors());

}






// Get the projection of the eigen faces on the eigen vectors
Mat WriteData::project(MyPCA PCA)
{


    Mat facesMatrix = PCA.getFacesMatrix();               // Get Matrix containing all faces as columns
    Mat mean = PCA.getAverage();                         // Get the mean of this matrix
    Mat eigen_Vector = PCA.getEigenvectors();           // Get the eigen vectors

    //cout << "Write Class"<< facesMatrix.size() << endl;

    int number_Samples = facesMatrix.cols;          // Total number of images in the dataset
    ProjectedFaces.create(facesMatrix.rows, number_Samples, CV_32FC1);   // trainFacesInEigen.create(number_Samples, number_Samples, CV_32FC1);


    for (int face = 0; face < number_Samples; face++) {

        Mat temp;           // Temporary matrix to hold the result of subtraction
        Mat projection = ProjectedFaces.col(face);
        subtract(facesMatrix.col(face), mean, temp);
        projection = eigen_Vector * temp;
        ProjectedFaces.col(face) = projection;

    }

    //cout << ProjectedFaces.col(0).size() <<endl;
    return ProjectedFaces;
}







// Create text file containing the projection of each sample on the eigen vectors of the covariance matrix
void WriteData::writeTrainFacesData(vector<string> FacesID)
{

    string path = "C:/Users/saraa/OneDrive/Desktop/FaceRecognition_PCA-master/FRG/data/facesdata.txt";
    ofstream writeFaceFile(path.c_str(), ofstream::out | ofstream::trunc);

    if (!writeFaceFile) {
        cout << "Fail to open file" << endl;
    }


    for (int face = 0; face < FacesID.size(); face++) {

        // writeFaceFile << face + 1 << "#";
        writeFaceFile << FacesID[face] << ":";

        for (int row = 0; row < ProjectedFaces.rows; row++) {

            writeFaceFile << ProjectedFaces.col(face).at<float>(row);
            writeFaceFile << " ";  // Seperate each element in the projection vector for each sample by a space in the text file

        }

        writeFaceFile << "\n";      // Take new line for each new sample in the dataset
    }

    writeFaceFile.close();          // Close the text file
}







// Create text file containing the average (mean) vector of the combined matrix
void WriteData::writeMean(Mat mean)
{

    string path = "C:/Users/saraa/OneDrive/Desktop/FaceRecognition_PCA-master/FRG/data/mean.txt";
    ofstream writeMeanFile(path.c_str(), ofstream::out | ofstream::trunc);

    if (!writeMeanFile) {
        cout << "Fail to open file" << endl;
    }


    for (int row = 0; row < mean.rows; row++) {

        writeMeanFile << mean.at<float>(row);
        writeMeanFile << " ";       // Seperate each element in the mean vector by a space in the text file
    }

    writeMeanFile.close();              // Close the text file
}








// Create text file containing the eigen vectors of the covariance matrix
void WriteData::writeEigen(Mat eigen_Vectors)
{

    string path = "C:/Users/saraa/OneDrive/Desktop/FaceRecognition_PCA-master/FRG/data/eigen.txt";
    ofstream writeEigenFile(path.c_str(), ofstream::out | ofstream::trunc);

    if (!writeEigenFile) {
        cout << "Fail to open file" << endl;
    }



    for (int vector = 0; vector < eigen_Vectors.rows; vector++) {

        for (int element = 0; element < eigen_Vectors.cols; element++) {

            writeEigenFile << eigen_Vectors.row(vector).at<float>(element);
            writeEigenFile << " "; // Seperate each element in the eigen vector by a space in the text file

        }

        writeEigenFile << "\n";   // Take new line for each eigen vector of the covariance matrix
    }

    writeEigenFile.close();   // Close the text file
}
