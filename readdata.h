#ifndef READDATA_H
#define READDATA_H


#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


#include "opencv2/core.hpp"


using namespace std;
using namespace cv;


class ReadData
{


public:
    ReadData();
    void readList(string& filePath, vector<string>& facesPath, vector<string>& facesID);
    Mat GetSamples(int no_samples, vector<string>& faceID);
    Mat GetMean();
    Mat GetEigenVectors(int no_samples);


};

#endif // READDATA_H
