#ifndef WRITE_DATA
#define WRITE_DATA

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include "mypca.h"


using namespace std;
using namespace cv;


class WriteData {

public:

    WriteData(MyPCA PCA, vector<string>& FacesID);
    Mat project(MyPCA PCA);
    void writeTrainFacesData(vector<string>FacesID);
    void writeMean(Mat mean);
    void writeEigen(Mat eigen_Vectors);



private:

    Mat ProjectedFaces;
    int number_Samples;

};

#endif // WRITEDATA_H
