#include "detector.h"




Detector::Detector()
{

    String face_cascadePath = "C:/Users/saraa/OneDrive/Desktop/Computer Vision - Task 5/Face-Detection-Recognition/FRG/haarcascade/haarcascade_frontalface_default.xml";

    if ( !face_cascade.load(face_cascadePath) )
        cout << "ERROR: Can not open file" << endl;

}







//
Mat Detector::GetFace(Mat &inputImage, Mat &toTest) {


    Mat frameGray;

    toTest = Mat::zeros(480, 480, inputImage.type());

    for (int i = 0; i < toTest.cols; i++) {

        inputImage.col(80 + i).copyTo(toTest.col(i));
    }

    // Convert the image to grayscale and normalize histogram:
    resize(toTest, toTest, Size(240, 240));
    cvtColor(toTest, frameGray, COLOR_BGR2GRAY);
    Mat toReturn;
    frameGray.copyTo(toReturn);
    // cout << toTest.size() << endl;
    equalizeHist(frameGray, frameGray);

    vector<Rect> facesRec;


    face_cascade.detectMultiScale( frameGray, facesRec, 1.1, 5, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );   // Detect faces
    // cout << "faces: " << facesRec.size() << endl;


    if (facesRec.size() >= 1){

        rectangle(toTest, facesRec[0], Scalar( 255, 0, 255 ), 1);

        Mat faceROI = toReturn(facesRec[0]);    // Copy found face bounded by rectangle
        // cout << "ROI SIZE " << faceROI.size() << endl;
        faceROI.copyTo(faceToTest);
        resize(faceToTest, faceToTest, Size(100,100));   // Resize found face
        faceFlag = 1;

    }

    facesRec.clear();

    return faceToTest;
}

