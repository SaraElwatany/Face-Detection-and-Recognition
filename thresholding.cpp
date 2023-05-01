#include "thresholding.h"

Thresholding::Thresholding()
{

}
int Thresholding:: optimalThresholding(Mat& image) {
    // Initialize clusters
    vector<int> cluster1 = {image.at<uchar>(0, 0), image.at<uchar>(0, image.cols-1), image.at<uchar>(image.rows-1, 0), image.at<uchar>(image.rows-1, image.cols-1)};
    vector<int> cluster2;
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            if ((i != 0 && j != 0 && i != image.rows-1 && j != image.cols-1) || (i == 0 && j == 0) || (i == 0 && j == image.cols-1) || (i == image.rows-1 && j == 0) || (i == image.rows-1 && j == image.cols-1))
                continue;
            cluster2.push_back(image.at<uchar>(i, j));
        }
    }

    // Compute initial threshold accorging to the 2 clusters mean
    int threshold = (static_cast<int>(round(mean(cluster1)[0])) + static_cast<int>(round(mean(cluster2)[0]))) / 2;

    // Iterate until convergence
    while (true) {
        // Assign pixels to clusters based on current threshold
        vector<int> newCluster1, newCluster2;
        for (int i = 0; i < image.rows; i++) {
            for (int j = 0; j < image.cols; j++) {
                if (image.at<uchar>(i, j) <= threshold)
                    newCluster1.push_back(image.at<uchar>(i, j));
                else
                    newCluster2.push_back(image.at<uchar>(i, j));
            }
        }

        // Compute new threshold and check for convergence
        int newThreshold = (static_cast<int>(round(mean(newCluster1)[0])) + static_cast<int>(round(mean(newCluster2)[0]))) / 2;
        if (abs(newThreshold - threshold) < 1e-6)
            break;
        else {
            threshold = newThreshold;
            cluster1 = newCluster1;
            cluster2 = newCluster2;
        }
    }

    // Return threshold value
    return threshold;
}
int Thresholding::otsuThresholding(Mat image)
{
    // initialize histogram array with zeros
    int hist[256] = { 0 };

    // calculate the histogram of the input image
    for (int y = 0; y < image.rows; y++)
    {
        for (int x = 0; x < image.cols; x++)
        {
            // get the intensity value of the pixel at (x,y)
            int intensity = static_cast<int>(image.at<uchar>(y, x));

            // increment the count for that intensity value in the histogram array
            hist[intensity]++;
        }
    }

    // calculate the total number of pixels in the image
    int total = image.rows * image.cols;

    // calculate the sum of intensity values multiplied by their respective counts
    double sum = 0;
    for (int i = 0; i < 256; i++)
    {
        sum += i * static_cast<double>(hist[i]);
    }

    // initialize variables for within-class variance, max variance, and threshold value
    double sumB = 0;
    int wB = 0;
    int wF = 0;
    double maxVar = 0;
    int threshold = 0;

    // loop over all possible intensity values to find optimal threshold
    for (int i = 0; i < 256; i++)
    {
        // add the count of the current intensity value to the count of background pixels
        wB += hist[i];
        if (wB == 0) continue;

        // calculate the count of foreground pixels
        wF = total - wB;
        if (wF == 0) break;

        // add the sum of intensity values multiplied by their respective counts to the sum for the background class
        sumB += i * static_cast<double>(hist[i]);

        // calculate the mean intensity values for background and foreground classes
        double mB = sumB / wB;
        double mF = (sum - sumB) / wF;

        // calculate the between-class variance
        double varBetween = static_cast<double>(wB) * static_cast<double>(wF) * (mB - mF) * (mB - mF);

        // update the threshold value if the between-class variance is higher than the current maximum
        if (varBetween > maxVar)
        {
            maxVar = varBetween;
            threshold = i;
        }
    }

    // return the optimal threshold value
    return threshold;
}


Mat Thresholding:: globalThresholding(Mat original,  double thresholdValue , int maxValue)
{
    Mat result = original.clone();
    for (int i = 0; i < original.rows; i++) {
        for (int j = 0; j < original.cols; j++) {
            if (original.at<uchar>(i, j) > thresholdValue) {
                result.at<uchar>(i, j) = maxValue;
            }
            else {
                result.at<uchar>(i, j) = 0;
            }
        }
    }

    return result;
}
Mat Thresholding:: localThresholding(Mat image, int blockSize, std::string thresholdMethod) {
    Mat result = image.clone();

    // Divide the image into blocks
    for (int i = 0; i < image.rows; i += blockSize) {
        for (int j = 0; j < image.cols; j += blockSize) {
            int blockHeight = std::min(blockSize, image.rows - i);
            int blockWidth = std::min(blockSize, image.cols - j);
            Mat subImage = image(cv::Range(i, i+blockHeight), cv::Range(j, j+blockWidth));

            // Apply thresholding to the block
            int localThreshold;
            if (thresholdMethod == "otsu") {
                localThreshold = otsuThresholding(subImage);
            } else if (thresholdMethod == "optimal") {
                localThreshold = optimalThresholding(subImage);
            } else {
                // Invalid threshold method specified
                return result;
            }
            threshold(subImage, subImage, localThreshold, 255, THRESH_BINARY);

            // Copy the thresholded block back to the result image
            subImage.copyTo(result(cv::Range(i, i+blockHeight), cv::Range(j, j+blockWidth)));
        }
    }

    return result;
}
