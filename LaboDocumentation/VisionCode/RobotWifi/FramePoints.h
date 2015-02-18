//
//  FramePoints.h
//  VeldAfbakenen
//
//  Created by Jeroen Provoost on 6/03/14.
//  Copyright (c) 2014 Jeroen Provoost. All rights reserved.
//

#ifndef __VeldAfbakenen__FramePoints__
#define __VeldAfbakenen__FramePoints__

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include "Line.h"

using namespace std;
using namespace cv;
class FramePoints{
    
public:
    FramePoints(void);
    ~FramePoints(void);
    
    void setLijn1(Line lijn);
    void setLijn2(Line lijn);
    void setLijn3(Line lijn);
    void setLijn4(Line lijn);
    
    Line getLijn1(void);
    Line getLijn2(void);
    Line getLijn3(void);
    Line getLijn4(void);
    
    void setMat(Mat fr);
    Mat getMat(void);
private:
    Mat frame;
    Line lijn1;
    Line lijn2;
    Line lijn3;
    Line lijn4;
};


#endif /* defined(__VeldAfbakenen__FramePoints__) */
