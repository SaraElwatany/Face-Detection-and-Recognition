#ifndef DETECTOR_H
#define	DETECTOR_H

#include <string>
#include <iostream>


#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"


using namespace std;
using namespace cv;


class Detector {


public:
    Detector();
    Mat GetFace(Mat &inputImage, Mat &toTest);


private:
    CascadeClassifier face_cascade;
    bool faceFlag = 0;
    Mat faceToTest;

};

#endif // DETECTOR_H
