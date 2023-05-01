#ifndef THRESHOLDING_H
#define THRESHOLDING_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <cmath>

using namespace cv;
using namespace std;

class Thresholding
{
public:
    Thresholding();
    int optimalThresholding(Mat& image);
    int otsuThresholding( Mat image);
    Mat globalThresholding(Mat original,  double thresholdValue , int maxValue);
    Mat localThresholding(Mat image, int blockSize, std::string thresholdMethod);
};

#endif // THRESHOLDING_H
