# Face Detection and Recognition

# Abstract

The above repository includes our work from the previous tasks of Computer Vision Course (Noising Image, Denoising Image with several types of filters, Edge Detection, Image Normalization, Image Equalization, Histogram plotting, Cumulative Curve plotting, Low & High pass frequency domain filters, Hybrid Images, Line, Circle & Ellipse Detection, Active Contours using greedy algorithm), Harris Corner Detection, SIFT algorithm, SSD , NCC, various image thresholding techniques & clustering.

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


## faces folder
- Contains the images we used as our training samples in our project but for our privacy we removed it.


## haarcascade folder
- Contains the models we used for face detection.


## Data folder
- Contains the files we used for our model to write and read data.


## list folder
- Contains the paths to our data samples (images) present in the "faces" folder.



## Report in pdf format
- Task5_Report


## Snapshots from our work

- Face Detection
![2023-06-14](https://github.com/SaraElwatany/Face-Detection-and-Recognition/assets/93448764/c66ba332-4cf2-4d9e-8855-42deec3390c3)

- Face Recognition
![2023-06-14 (2)](https://github.com/SaraElwatany/Face-Detection-and-Recognition/assets/93448764/10b5cf12-6ab1-40e9-85fd-21cbc305147b)

- Face Recognition
![2023-06-14 (1)](https://github.com/SaraElwatany/Face-Detection-and-Recognition/assets/93448764/e8b1cb3a-073d-4f10-a7b7-04d569f5f86d)



## Note
- To run the project you will have to change the paths of the "faces", "data", "list" & "haarcascade" folders present in the various source & header files to match your own path.

  

## Used Papers:
1. [https://people.eecs.berkeley.edu/~malik/cs294/lowe-ijcv04.pdf](https://www.researchgate.net/publication/281446070_Face_Recognition_Using_Eigenfaces)
2. https://www.researchgate.net/figure/ROC-curve-for-face-recognition_fig28_331906233


