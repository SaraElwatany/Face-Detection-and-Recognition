#include "clustering.h"

Clustering::Clustering()
{

}


/********************************************************************** K-MEANS **************************************************************************/


// Initialize K random centroids and their associated empty vector for pixels
void Clustering::InitializeCentroids(Mat originalImage, int k, vector<Scalar> &clustersCentroids, vector<vector<Point>> &Clusters)
{

    // Initialize random object
    RNG random(cv::getTickCount());

    for(int cluster =0; cluster<k; cluster++){

        // Get random pixel (Centroid)
        Point centroid;
        centroid.x = random.uniform(0, originalImage.cols);
        centroid.y = random.uniform(0, originalImage.rows);
        Scalar centroid_intensity = originalImage.at<Vec3b>(centroid.y, centroid.x);

        // Get intesities of centroid and save it
        Scalar centerK(centroid_intensity.val[0], centroid_intensity.val[1], centroid_intensity.val[2]);
        clustersCentroids.push_back(centerK);

        // Get vector for future associated pixel to each centroid
        vector<Point> ptCluster;
        Clusters.push_back(ptCluster);
    }

}






// Get the Euclidian Distance for pixels' intensities
double Clustering::GetEuclideanDistance(Scalar pixel, Scalar Centroid){

    // Get intensity difference
    double diffBlue = pixel.val[0] - Centroid[0];
    double diffGreen = pixel.val[1] - Centroid[1];
    double diffRed = pixel.val[2] - Centroid[2];

    //Get euclidian distance
    double euclidian_distance = sqrt(pow(diffBlue, 2) + pow(diffGreen,2) + pow(diffRed,2));

    return euclidian_distance;
}








// Compute the pixels for initial clusters
void Clustering::BuildClusters(Mat originalImage, int k, vector<Scalar> clustersCentroids, vector<vector<Point>> & Clusters)
{


    // For each pixel, find closest cluster
    for(int row = 0 ; row<originalImage.rows; row++){
        for(int col = 0; col<originalImage.cols; col++){


            double minDistance = INFINITY;
            int closestClusterIndex = 0;
            Scalar pixel = originalImage.at<Vec3b>(row,col);


            // Iterate through each cluster present
            for(int cluster = 0; cluster<k; cluster++){

                Scalar clusterPixel = clustersCentroids[cluster];   // Get the intensity of the associated Centroid of current cluster

                // Get Euclidean Distance between the centoid & current pixel
                double distance = GetEuclideanDistance(pixel, clusterPixel);

                // Update to closest cluster center
                if(distance < minDistance){

                    minDistance = distance;
                    closestClusterIndex = cluster;

                }
            }

            // Push pixel into associated cluster
            Clusters[closestClusterIndex].push_back(Point(col,row));

        }
    }

}








// Compute the new Centroids for each cluster
double Clustering::AdjustCentroids(Mat originalImage, int k, vector<Scalar> & clustersCentroids, vector<vector<Point>> Clusters, double & oldCentroid, double newCentroid){

    double diffChange;

    // Adjust cluster centroid to mean of associated cluster's pixels
    for(int cluster =0; cluster<k; cluster++){

        vector<Point> ptInCluster = Clusters[cluster];
        double newBlue = 0;
        double newGreen = 0;
        double newRed = 0;

        // Compute mean intensity values for the cluster for the associated 3 channels
        for(int i=0; i<ptInCluster.size(); i++){

            Scalar pixel = originalImage.at<Vec3b>(ptInCluster[i].y,ptInCluster[i].x);
            newBlue += pixel.val[0];
            newGreen += pixel.val[1];
            newRed += pixel.val[2];

        }

        newBlue /= ptInCluster.size();
        newGreen /= ptInCluster.size();
        newRed /= ptInCluster.size();

        //Assign new intensity to the cluster's centroid
        Scalar newPixel(newBlue, newGreen, newRed);
        clustersCentroids[cluster] = newPixel;

        //Compute distance between the old and new values
        newCentroid += GetEuclideanDistance(newPixel,clustersCentroids[cluster]);

    }


    newCentroid /= k;

    //get difference between previous iteration change
    diffChange = abs(oldCentroid - newCentroid);
    cout << "diffChange is: " << diffChange << endl;
    oldCentroid = newCentroid;

    return diffChange;

}







// Get the segmented image
Mat Clustering::PaintImage(Mat &segmentImage, int k, vector<vector<Point>> Clusters){

    srand(time(NULL));

    // Assign random color to each cluster
    for(int cluster=0; cluster<k; cluster++){

        vector<Point> ptInCluster = Clusters[cluster];
        // Get random colour for each cluster
        Scalar randomColor(rand() % 255,rand() % 255,rand() % 255);

        // For each pixel in cluster change color to fit cluster
        for(int indx=0; indx<ptInCluster.size(); indx++){

            Scalar pixelColor = segmentImage.at<Vec3b>(ptInCluster[indx]);
            pixelColor = randomColor;

            segmentImage.at<Vec3b>(ptInCluster[indx])[0] = pixelColor.val[0];
            segmentImage.at<Vec3b>(ptInCluster[indx])[1] = pixelColor.val[1];
            segmentImage.at<Vec3b>(ptInCluster[indx])[2] = pixelColor.val[2];
        }
    }

    return segmentImage;
}
