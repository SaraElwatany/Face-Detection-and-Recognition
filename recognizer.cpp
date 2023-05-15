#include "recognizer.h"



Recognizer::Recognizer(Mat _testImg, Mat _avgVec, Mat _eigenVec, Mat _facesInEigen, vector<string>& _loadedFacesID) {
    prepareAndRecognize(_testImg, _avgVec, _eigenVec, _facesInEigen, _loadedFacesID);
}




std::pair<std::string, double> Recognizer::prepareAndRecognize(Mat _testImg, Mat _avgVec, Mat _eigenVec, Mat _facesInEigen, vector<string>& _loadedFacesID) {
    _testImg.convertTo(_testImg, CV_32FC1);
    _testImg.reshape(0, _testImg.rows * _testImg.cols).copyTo(testVec);

    Mat tmpData;
    subtract(testVec, _avgVec, tmpData);
    testPrjFace = _eigenVec * tmpData;

    std::string closestFaceID = "";
    double closestFaceDist = std::numeric_limits<double>::max();

    for (int i = 0; i < _loadedFacesID.size(); i++) {
        Mat src1 = _facesInEigen.col(i);
        Mat src2 = testPrjFace;

        double dist = norm(src1, src2, NORM_L2);

        if (dist < closestFaceDist) {
            closestFaceDist = dist;
            closestFaceID = _loadedFacesID[i];
        }
    }

    return std::make_pair(closestFaceID, closestFaceDist);
}

