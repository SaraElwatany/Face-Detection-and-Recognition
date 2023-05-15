#ifndef MY_PCA_H
#define MY_PCA_H


#include <iostream>
#include <vector>
#include <float.h>



#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"



using namespace std;
using namespace cv;



class MyPCA {

public:

    MyPCA(vector<string>& _facesPath);
    Mat getFacesMatrix();
    Mat getAverage();
    Mat getEigenvectors();
    void init(vector<string>& _facesPath);


private:

    int imgSize = -1;       // Dimension of features
    int imgRows = -1;       // No of rows of image
    Mat allFacesMatrix;
    Mat avgVector;
    Mat subFacesMatrix;
    Mat eigenVector;
};

#endif // MYPCA_H
