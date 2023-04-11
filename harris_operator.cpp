#include "harris_operator.h"

harris_operator::harris_operator()
{

}

//int window_size = 3;
//const double alpha = 0.04;
//const double threshold_level = 0.01;

void harris_operator:: nonMaxSuppression(Mat& response, int window_size)
{
    int r = window_size / 2;
    Mat_<float>::iterator it = response.begin<float>() + r * response.cols + r;
    Mat_<float>::iterator end = response.end<float>() - r * response.cols - r;
    while (it != end)
    {
        float val = *it;
        if (val > 0)
        {
            Mat_<float>::iterator it1 = it - r * response.cols - r;
            Mat_<float>::iterator it2 = it + r * response.cols + r;
            for (; it1 <= it2; it1 += response.cols)
            {
                for (int j = -r; j <= r; ++j, ++it1)
                {
                    if (*it1 > val)
                    {
                        val = 0;
                        break;
                    }
                }
                if (val == 0)
                    break;
            }
            *it = val;
        }
        ++it;
    }
}

Mat harris_operator:: convertToGray(Mat img) {
    Mat gray;
    if (img.channels() == 3) {
        cvtColor(img, gray, COLOR_BGR2GRAY);
    }
    else {
        gray = img.clone();
    }
    return gray;
}


Mat harris_operator:: harrisCorner(Mat gray,int window_size ,double alpha) {
    Mat R(gray.size(), CV_64F);
    Mat Ix, Iy;
    Sobel(gray, Ix, CV_64F, 1, 0, 3);
    Sobel(gray, Iy, CV_64F, 0, 1, 3);
    Mat Ix2, Iy2, IxIy;
    Ix2 = Ix.mul(Ix);
    Iy2 = Iy.mul(Iy);
    IxIy = Ix.mul(Iy);
    Mat Ix2_sum, Iy2_sum, IxIy_sum;
    Mat kernel(window_size, window_size, CV_64F, 1);
    filter2D(Ix2, Ix2_sum, CV_64F, kernel);
    filter2D(Iy2, Iy2_sum, CV_64F, kernel);
    filter2D(IxIy, IxIy_sum, CV_64F, kernel);
    double A, B, C, d, t;
    for (int i = 0; i < gray.rows; i++) {
        for (int j = 0; j < gray.cols; j++) {
            A = Ix2_sum.at<double>(i, j);
            B = IxIy_sum.at<double>(i, j);
            C = Iy2_sum.at<double>(i, j);
            d = A * C - B * B;
            t = A + C;
            R.at<double>(i, j) = d - alpha * t * t;
        }
    }
    nonMaxSuppression(R, window_size);
        return R;
}



void harris_operator::setThreshold(Mat& R,double threshold_level) {
    double R_max;
    minMaxLoc(R, NULL, &R_max, NULL, NULL);
    double threshold = threshold_level * R_max;
    for (int i = 0; i < R.rows; i++) {
        for (int j = 0; j < R.cols; j++) {
            if (R.at<double>(i, j) < threshold) {
                R.at<double>(i, j) = 0;
            }
        }
    }
    return;
}

void harris_operator:: getLocalMax(Mat R, Mat& localMax) {
    Mat dilated;
    dilate(R, dilated, Mat());
    compare(R, dilated, localMax, CMP_EQ);
    localMax = localMax - 255 + (dilated > 0);
    return;
}

Mat  harris_operator:: drawPointsToImg(Mat img, Mat localMax) {
    localMax.convertTo(localMax, CV_64F);
    for (int i = 0; i < localMax.rows; i++) {
        for (int j = 0; j < localMax.cols; j++) {
            if (localMax.at<double>(i, j) != 0) {
                Point p = Point(j, i);
                 circle(img, p, 1, Scalar(0,0,255),1, 1, 0);
            }
        }
    }
    return img;
}
