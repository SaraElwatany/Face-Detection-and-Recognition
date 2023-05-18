QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0





SOURCES += \
    MeanShift.cpp \
    RegionGrowing.cpp \
    activecontour.cpp \
    clustering.cpp \
    detector.cpp \
    featurematching.cpp \
    filters.cpp \
    frequency.cpp \
    harris_operator.cpp \
    histograms.cpp \
    hough.cpp \
    main.cpp \
    mainwindow.cpp \
    mypca.cpp \
    readdata.cpp \
    recognizer.cpp \
    roc.cpp \
    sift.cpp \
    thresholding.cpp \
    writedata.cpp

HEADERS += \
    MeanShift.h \
    RegionGrowing.h \
    activecontour.h \
    clustering.h \
    detector.h \
    featurematching.h \
    filters.h \
    frequency.h \
    harris_operator.h \
    histograms.h \
    hough.h \
    mainwindow.h \
    mypca.h \
    readdata.h \
    recognizer.h \
    roc.h \
    sift.h \
    thresholding.h \
    writedata.h

FORMS += \
    mainwindow.ui





#INCLUDEPATH += D:\OpenCV\opencv\release\lib
#LIBS += D:\OpenCV\opencv\release\bin -libopencv_calib3d470 -lopencv_core470.dll -lopencv_imgproc470.dll -lopencv_imgcodecs470.dll -lopencv_video470.dll -lopencv_videoio470.dll -lopencv_dnn470.dll



#### Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



INCLUDEPATH += D:\OpenCV\opencv\release\install\include


win32: LIBS += -LD:/OpenCV/opencv/release/lib/ -llibopencv_calib3d470.dll

INCLUDEPATH += D:/OpenCV/opencv/release/include
DEPENDPATH += D:/OpenCV/opencv/release/include


win32: LIBS += -LD:/OpenCV/opencv/release/lib/ -llibopencv_core470.dll

INCLUDEPATH += D:/OpenCV/opencv/release/include
DEPENDPATH += D:/OpenCV/opencv/release/include



win32: LIBS += -LD:/OpenCV/opencv/release/lib/ -llibopencv_highgui470.dll

INCLUDEPATH += D:/OpenCV/opencv/release/include
DEPENDPATH += D:/OpenCV/opencv/release/include


win32: LIBS += -LD:/OpenCV/opencv/release/lib/ -llibopencv_imgcodecs470.dll

INCLUDEPATH += D:/OpenCV/opencv/release/include
DEPENDPATH += D:/OpenCV/opencv/release/include


win32: LIBS += -LD:/OpenCV/opencv/release/lib/ -llibopencv_imgproc470.dll

INCLUDEPATH += D:/OpenCV/opencv/release/include
DEPENDPATH += D:/OpenCV/opencv/release/include


win32: LIBS += -LD:/OpenCV/opencv/release/lib/ -llibopencv_features2d470.dll

INCLUDEPATH += D:/OpenCV/opencv/release/include
DEPENDPATH += D:/OpenCV/opencv/release/include


win32: LIBS += -LD:/OpenCV/opencv/release/lib/ -llibopencv_objdetect470.dll

INCLUDEPATH += D:/OpenCV/opencv/release/include
DEPENDPATH += D:/OpenCV/opencv/release/include




#INCLUDEPATH +=C:\Users\hp\Downloads\opencv\release\include

#LIBS += C:\Users\hp\Downloads\opencv\release\bin\libopencv_core460.dll
#LIBS += C:\Users\hp\Downloads\opencv\release\bin\libopencv_highgui460.dll
#LIBS += C:\Users\hp\Downloads\opencv\release\bin\libopencv_imgcodecs460.dll
#LIBS += C:\Users\hp\Downloads\opencv\release\bin\libopencv_imgproc460.dll
#LIBS += C:\Users\hp\Downloads\opencv\release\bin\libopencv_calib3d460.dll
#LIBS += C:\Users\hp\Downloads\opencv\release\bin\libopencv_features2d460.dll




#INCLUDEPATH += D:\opencv\opencv\release\install\include
#LIBS += D:\opencv\opencv\release\bin\libopencv_core460.dll
#LIBS += D:\opencv\opencv\release\bin\libopencv_highgui460.dll
#LIBS += D:\opencv\opencv\release\bin\libopencv_imgcodecs460.dll
#LIBS += D:\opencv\opencv\release\bin\libopencv_imgproc460.dll
#LIBS += D:\opencv\opencv\release\bin\libopencv_calib3d460.dll
#LIBS +=  D:\opencv\opencv\release\bin\libopencv_features2d460.dll



