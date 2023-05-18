#ifndef ROC_H
#define ROC_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;



struct roc_data{

    double threshold;
    vector<int> true_positive_counts;
    vector<int> true_negative_counts;
    vector<int> false_positive_counts;
    vector<int> false_negative_counts;
};


class ROC
{


public:
    ROC();
    roc_data calculate_roc_curve_total(vector<vector<double>> predictions, vector<string> labels, int n_points);
    void draw_roc_curve(Mat& img, roc_data roc_curve);

};

#endif // ROC_H


