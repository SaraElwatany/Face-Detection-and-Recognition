# Face Detection and Recognition

# Image Thresholding & Clustering

The above repository includes our work from the previous tasks (Noising Image, Denoising Image with several types of filters, Edge Detection, Image Normalization, Image Equalization, Histogram plotting, Cumulative Curve plotting, Low & High pass frequency domain filters, Hybrid Images, Line, Circle & Ellipse Detection, Active Contours using greedy algorithm), Harris Corner Detection, SIFT algorithm, SSD , NCC

## Previous files
- Filters.h
- Frequency.h
- Histograms.h
- Filters.cpp (various smoothing and edge detection filters implementation)
- Frequency.cpp (frequency domain filters and hybrid images implementation)
- Histograms.cpp (image normalization, image equalization, histogram, cumulative curve plotting)
- Hough.h
- ActiveContour.h
- Hough.cpp (includes the line, circle and ellipse detection functions)
- ActiveContour.cpp (includes the implementation of the object contouring along with the chain code)
- harris_operator.h
- harris_operator.cpp (Implementation of Harris operator for feature extraction)
- Sift.h
- Sift.cpp (Implementation of SIFT algorithm along with Execution time)
- featurematching.h
- featurematching.cpp (Matching of features using SSD & Cross Correlations)
- clustering.h
- clustering.cpp (Implementation of the k-means & agglomerative clustering for images)
- thresholding.h
- thresholding.cpp (Implementation of Optimal , Otsu & Spectral thresholding techniques)
- regiongrowing.h
- regiongrowing.cpp (Implementation of Region Growing thresholding)

## Added files
- detector.h
- detector.cpp (Implementation of the Face Detection)
- recognizer.h
- recognizer.cpp (Implementation of the Face Recognition)
- writedata.h
- writedata.cpp (Writing the parameters needed for our model)
- readdata.h
- readdata.cpp (Reading the parameters needed for our model)
- roc.h
- roc.cpp (Implementation of the ROC Curve)




## UI files
- MainWindow.h
- MainWindow.cpp


## Images folder
- Contains the images we used as samples in our project


## Report in pdf format
- Task5_Report


## Snapshots from our work

- Face Detection
![image](https://user-images.githubusercontent.com/93448764/236069187-94105445-c7a8-410f-a4d0-d3b67a61c6b6.png)

- Face Recognition
![image](https://user-images.githubusercontent.com/93448764/236069248-6b9149ff-bac9-458f-9012-dcc3851440ba.png)

- Face Recognition
![image](https://user-images.githubusercontent.com/93448764/236069482-2bed19c5-5e24-40bc-bd03-32377979bf3b.png)




## Used Papers:
1. [https://people.eecs.berkeley.edu/~malik/cs294/lowe-ijcv04.pdf](https://www.researchgate.net/publication/281446070_Face_Recognition_Using_Eigenfaces)
2. [https://www.researchgate.net/publication/342449462_Image_Segmentation_using_K-means_Clustering](https://www.researchgate.net/figure/ROC-curve-for-face-recognition_fig28_331906233)https://www.researchgate.net/figure/ROC-curve-for-face-recognition_fig28_331906233


