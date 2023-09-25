#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#include "ch03_1.hpp"
void PointOp(){
    Point pt1;
    pt1.x = 5;
    pt1.y = 10;
    
    Point pt2(10, 30);
    
    Point pt3 = pt1 + pt2;
    Point pt4 = pt1 *2;
    int d1 = pt1.dot(pt2);
    bool b1 = (pt1 == pt2);
    
    cout << "pt1 : " << pt1 << endl;
    cout << "pt2 : " << pt2 << endl;
    cout << "pt3 : " << pt3 << endl;
    cout << "pt4 : " << pt4 << endl;
    cout << "d1 : " << d1 << endl;
    cout << "b1 : " << b1 << endl;
}

void SizeOp(){
    Size sz1, sz2(10, 20);
    sz1.width = 5;
    sz1.height = 10;
    
    Size sz3 = sz1 + sz2;
    Size sz4 = sz1 * 2;
    int area1 = sz4.area();
    
    cout << "sz3 : " << sz3 << endl;
    cout << "sz4 : " << sz4 << endl;
}

void RectOP(){
    Rect rc1;
    Rect rc2(10, 10, 60, 40);
    
    Rect rc3 = rc1 +Size(50, 40);
    Rect rc4 = rc2 + Point(10, 10);
    
    Rect rc5 = rc3 & rc4;
    Rect rc6 = rc3 | rc4;
    
    cout << "rc5 : " << rc5 << endl;
    cout << "rc6 : " << rc6 << endl;
}

void RotatedOP(){
    RotatedRect rr1(Point2f(40, 30), Size2f(40, 20), 30.f);
    Point2f pts[4];
    rr1.points(pts);
    
    Rect br = rr1.boundingRect();
    
}

void RangeOP(){
    Range r1(0,10);
    
}
int main1()
{
    PointOp();
    SizeOp();
    RectOP();
    return 0;
}
