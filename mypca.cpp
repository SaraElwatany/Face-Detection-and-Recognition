#include "mypca.h"




MyPCA::MyPCA(vector<string>& _facesPath)
{
    init(_facesPath);
}





void MyPCA::init(vector<string>& _facesPath)
{


    // Getting input image size
    Mat sampleImg = imread(_facesPath[1], 0);
    imgSize = sampleImg.rows * sampleImg.cols;  // Get the total number of pixels (Dimension of Features)

    // Merging matrix
    // Flatten each image to one column & combine them to one matrix
    int col = int(_facesPath.size());
    allFacesMatrix.create(imgSize, col, CV_32FC1);     // Create an empty matrix with no of rows equal to the no of pixels of sample image in the data set & columns equal to the number of images in the data set

    for (int i = 0; i < col; i++) {

        Mat tmpMatrix = allFacesMatrix.col(i);
        Mat tmpImg;
        Mat im = imread(_facesPath[i], 0);  // Load grayscale image from data set (channel set to 0)
        im.convertTo(tmpImg, CV_32FC1);

        tmpImg.reshape(0, im.cols * im.rows).copyTo(tmpMatrix);
        //tmpImg.reshape(1, 1).copyTo(tmpMatrix);          // Convert to 1D matrix (Flatten the image) **** (imgSize, 1) (1, imgSize)
        allFacesMatrix.col(i)  = tmpMatrix;
    }



    //  Getting average vector
    Mat face;
    reduce(allFacesMatrix, avgVector, 1, REDUCE_AVG);
    // Subtract matrix
    allFacesMatrix.copyTo(subFacesMatrix);

    for (int i = 0; i < subFacesMatrix.cols; i++) {

        subtract(subFacesMatrix.col(i), avgVector, subFacesMatrix.col(i));
    }
    //getting Best EigenVectors
    Mat covarMatrix = (subFacesMatrix.t()) * subFacesMatrix;        // Create covariance matrix (multiply the transpose with the faces matrix)

    // Get all eigenvalues and eigenvectors from covariance matrix
    Mat EigenValues, EigenVectors;
    eigen(covarMatrix, EigenValues, EigenVectors);

    eigenVector = EigenVectors * (subFacesMatrix.t());          // Get original eigen vectors before reduction (original dimension of N^2 x 1)
    // Normalize the eigen vectors
    for(int i = 0; i < eigenVector.rows; i++ )
    {
        Mat tempVec = eigenVector.row(i);
        normalize(tempVec, tempVec);
    }


}



Mat MyPCA::getFacesMatrix()
{
    return allFacesMatrix;
}



Mat MyPCA::getAverage()
{
    return avgVector;
}



Mat MyPCA::getEigenvectors()
{
    return eigenVector;
}
