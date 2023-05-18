#include "readdata.h"





ReadData::ReadData()
{

}






// Read the Id for each person in the data set & the path of his/her image from the text file
void ReadData::readList(string& filePath, vector<string>& facesPath, vector<string>& facesID)
{

    ifstream file(filePath.c_str(), ifstream::in);

    if (!file) {

        cout << "Fail to open file" << endl;
        exit(0);
    }

    string line, path, id;

    while (getline(file, line)) {

        stringstream lines(line);
        getline(lines, id, ';');
        getline(lines, path);

        path.erase(remove(path.begin(), path.end(), '\r'), path.end());
        path.erase(remove(path.begin(), path.end(), '\n'), path.end());
        path.erase(remove(path.begin(), path.end(), ' '), path.end());

        facesPath.push_back(path);
        facesID.push_back(id);

    }

}









// Read faces in eigenspace that has been trained
Mat ReadData::GetSamples(int no_samples, vector<string>& faceID)
{

    Mat faces = Mat::zeros(no_samples, no_samples, CV_32FC1);
    string path = "C:/Users/saraa/OneDrive/Desktop/Computer Vision - Task 5/Face-Detection-Recognition/FRG/data/facesdata.txt";
    ifstream readFaces(path.c_str(), ifstream::in);

    if (!readFaces) {
        cout << "Fail to open file" << endl;
    }

    string line, id;
    faceID.clear();

    for (int face = 0; face < no_samples; face++) {

        getline(readFaces, line);
        stringstream lines(line);
        getline(lines, id, ':');        // Get the ID of that face (separated from the image data with -> : )
        faceID.push_back(id);

        for (int pixel = 0; pixel < no_samples; pixel++) {

            string data;
            getline(lines, data, ' ');      // Each pixel of that face is separated from the other with space (for the same person)
            faces.col(face).at<float>(pixel) = atof(data.c_str());

        }

    }

    readFaces.close();

    return faces;

}









// Read average face of all faces
Mat ReadData::GetMean()
{

    Mat mean = Mat::zeros(10000, 1, CV_32FC1);   // 10000x1 Matrix to store the mean of the features (10000)
    string path = "C:/Users/saraa/OneDrive/Desktop/Computer Vision - Task 5/Face-Detection-Recognition/FRG/data/mean.txt";
    ifstream readMean(path.c_str(), ifstream::in);

    if (!readMean) {
        cout << "Fail to open file" << endl;
    }

    string line;

    for (int col = 0; col < 1; col++) {

        getline(readMean, line);
        stringstream lines(line);

        for (int row = 0; row < mean.rows; row++) {

            string data;
            getline(lines, data, ' ');
            mean.col(col).at<float>(row) = atof(data.c_str());
        }

    }

    readMean.close();

    return mean;
}










// Read eigenvector for each data sample/image (stored as matrix, where each vector is present as a row in that matrix)
Mat ReadData::GetEigenVectors(int no_samples)
{

    Mat eigen = Mat::zeros(no_samples, 10000, CV_32FC1);       // Matrix to store the values of the eigen vectors
    string path = "C:/Users/saraa/OneDrive/Desktop/Computer Vision - Task 5/Face-Detection-Recognition/FRG/data/eigen.txt";
    ifstream readEigen(path.c_str(), ifstream::in);

    if (!readEigen) {

        cout << "Fail to open file" << endl;
    }

    string line;

    for (int row = 0; row < no_samples; row++) {     // row == vector

        getline(readEigen, line);
        stringstream lines(line);

        for (int col = 0; col < eigen.cols; col++) {

            string data;
            getline(lines, data, ' ');
            eigen.at<float>(row,col) = atof(data.c_str());

        }

    }

    readEigen.close();      // close file

    return eigen;
}
