#ifndef FEATUREMATCHING_H
#define FEATUREMATCHING_H


#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <vector>

using namespace std;
using namespace cv;


class FeatureMatching
{
public:
    FeatureMatching();
    double sum_of_squared_differences(const vector<double>& desc_image1,const vector<double>& desc_image2);
    vector <DMatch> match_features(Mat descriptor1, Mat descriptor2, double threshold);
};

#endif // FEATUREMATCHING_H
