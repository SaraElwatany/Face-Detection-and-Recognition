#include "detector.h"




// Load training dataset
Detector::Detector()
{

    String face_cascadePath = "C:/Users/saraa/OneDrive/Desktop/FaceRecognition_PCA-master/FRG/haarcascade/haarcascade_frontalface_default.xml";

    if ( !face_cascade.load(face_cascadePath) )
        cout << "ERROR: Can not open file" << endl;

}







// Detect Faces
Mat Detector::GetFace(Mat &inputImage, Mat &toTest) {


    Mat Gray;

    toTest = Mat::zeros(480, 480, inputImage.type());

    for (int i = 0; i < toTest.cols; i++) {

        inputImage.col(80 + i).copyTo(toTest.col(i));
    }


    // Convert the image to grayscale and normalize histogram:
    resize(toTest, toTest, Size(240, 240));
    cvtColor(toTest, Gray, COLOR_BGR2GRAY);
    Mat toReturn;
    Gray.copyTo(toReturn);
    equalizeHist(Gray, Gray);

    vector<Rect> facesRec;


    face_cascade.detectMultiScale(Gray, facesRec, 1.1, 5, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );   // Detect faces
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
