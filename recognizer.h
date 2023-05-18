#ifndef RECOGNIZER_H
#define RECOGNIZER_H

#include <iostream>


#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"



using namespace std;
using namespace cv;




class Recognizer {


public:

    Recognizer(Mat _testImg, Mat _avgVec, Mat _eigenVec, Mat _facesInEigen, vector<string>& _loadedFacesID);
    void prepareFace(Mat _testImg);
    void projectFace(Mat testVec, Mat _avgVec, Mat _eigenVec);
    std::pair<std::string, double> recognize(Mat testPrjFace, Mat _facesInEigen, vector<string>& _loadedFacesID);
    std::pair<std::string, double>prepareAndRecognize(Mat _testImg, Mat _avgVec, Mat _eigenVec, Mat _facesInEigen, vector<string>& _loadedFacesID);


private:

    Mat testVec;
    Mat testPrjFace;
    string closestFaceID = "None";
    string prevId = closestFaceID;
    long double closestFaceDist = 3100;   // 3500 50  500   80000


};


#endif // RECOGNIZER_H
