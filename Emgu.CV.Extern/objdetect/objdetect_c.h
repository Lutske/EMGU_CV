//----------------------------------------------------------------------------
//
//  Copyright (C) 2004-2013 by EMGU. All rights reserved.
//
//----------------------------------------------------------------------------

#pragma once
#ifndef EMGU_OBJDETECT_C_H
#define EMGU_OBJDETECT_C_H

#include "opencv2/core/core_c.h"
#include "opencv2/objdetect/objdetect.hpp"
//#include "opencv2/objdetect/objdetect_c.h"
#include "vectors_c.h"

CVAPI(void) CvHOGDescriptorPeopleDetectorCreate(CvSeq* seq);

CVAPI(cv::HOGDescriptor*) CvHOGDescriptorCreateDefault();

CVAPI(cv::HOGDescriptor*) CvHOGDescriptorCreate(
   cv::Size* _winSize, 
   cv::Size* _blockSize, 
   cv::Size* _blockStride,
   cv::Size* _cellSize, 
   int _nbins, 
   int _derivAperture, 
   double _winSigma,
   int _histogramNormType, 
   double _L2HysThreshold, 
   bool _gammaCorrection);

CVAPI(void) CvHOGSetSVMDetector(cv::HOGDescriptor* descriptor, std::vector<float>* vector);

CVAPI(void) CvHOGDescriptorRelease(cv::HOGDescriptor* descriptor);

CVAPI(void) CvHOGDescriptorDetectMultiScale(
   cv::HOGDescriptor* descriptor, 
   CvArr* img, 
   CvSeq* foundLocations,
   double hitThreshold, 
   CvSize winStride,
   CvSize padding, 
   double scale,
   double finalThreshold, 
   bool useMeanshiftGrouping);

CVAPI(void) CvHOGDescriptorCompute(
    cv::HOGDescriptor *descriptor,
    CvArr *img, 
    std::vector<float> *descriptors,
    CvSize winStride,
    CvSize padding,
    CvSeq* locationSeq);


/*
CVAPI(void) cvHOGDescriptorDetect(
   cv::HOGDescriptor* descriptor, 
   CvArr* img, 
   CvSeq* foundLocations,
   double hitThreshold, 
   CvSize winStride,
   CvSize padding)
{
   cvClearSeq(foundLocations);

   std::vector<cv::Point> hits;
   cv::Mat mat = cv::cvarrToMat(img);
   descriptor->detect(mat, hits, hitThreshold, winStride, padding);
   cvSeqPushMulti(foundLocations, &hits.front(), hits.size());
}*/

CVAPI(unsigned int) CvHOGDescriptorGetDescriptorSize(cv::HOGDescriptor* descriptor);


CVAPI(cv::CascadeClassifier*) CvCascadeClassifierCreate(char* fileName);
CVAPI(void) CvCascadeClassifierRelease(cv::CascadeClassifier** classifier);
CVAPI(void) CvCascadeClassifierDetectMultiScale( 
   cv::CascadeClassifier* classifier,
   const IplImage* image,
   CvSeq* objects,
   double scaleFactor,
   int minNeighbors, int flags,
   CvSize minSize,
   CvSize maxSize); 

/*
//ERFilter
CVAPI(cv::ERFilter*) CvERFilterNM1Create();
CVAPI(cv::ERFilter*) CvERFilterNM2Create();
CVAPI(void) CvERFilterRelease(cv::ERFilter** filter);
CVAPI(void) CvERFilterRun(cv::ERFilter* filter, CvArr* image, std::vector<cv::ERStat>* regions);

//----------------------------------------------------------------------------
//
//  Vector of ERStat
//
//----------------------------------------------------------------------------
CVAPI(std::vector<cv::ERStat>*) VectorOfERStatCreate();

CVAPI(std::vector<cv::ERStat>*) VectorOfERStatCreateSize(int size);

CVAPI(int) VectorOfERStatGetSize(std::vector<cv::ERStat>* v);

CVAPI(void) VectorOfERStatClear(std::vector<cv::ERStat>* v);

CVAPI(void) VectorOfERStatRelease(std::vector<cv::ERStat>* v);

CVAPI(void) VectorOfERStatCopyData(std::vector<cv::ERStat>* v, cv::ERStat* data);

CVAPI(cv::ERStat*) VectorOfERStatGetStartAddress(std::vector<cv::ERStat>* v);
*/


#endif