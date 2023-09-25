#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


#include "ch05_ilne.hpp"

void drawLines()
{
    Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));
    
    line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));
    line(img, Point(50, 100), Point(200, 100), Scalar(255, 0, 255), 3);
    line(img, Point(50, 150), Point(200, 150), Scalar(255, 0, 0), 10);
    
    line(img, Point(250, 50), Point(350, 100), Scalar(0, 0, 255), 1, LINE_4);
    line(img, Point(250, 50), Point(350, 120), Scalar(255, 0, 255), 1, LINE_8);
    line(img, Point(250, 50), Point(350, 140), Scalar(255, 0, 0), 1, LINE_AA);
    
    arrowedLine(img, Point(50, 200), Point(150, 200), Scalar(0, 0, 255), 1);
    arrowedLine(img, Point(50, 250), Point(350, 250), Scalar(255, 0, 255), 1);
    arrowedLine(img, Point(50, 300), Point(350, 300), Scalar(255, 0, 0), 1, LINE_8, 0, 0.05);
    
    drawMarker(img, Point(50, 350), Scalar(0, 0, 255), MARKER_CROSS);
    drawMarker(img, Point(100, 350), Scalar(0, 0, 255), MARKER_TILTED_CROSS);
    drawMarker(img, Point(150, 350), Scalar(0, 0, 255), MARKER_STAR);
    drawMarker(img, Point(200, 350), Scalar(0, 0, 255), MARKER_DIAMOND);
    drawMarker(img, Point(250, 350), Scalar(0, 0, 255), MARKER_SQUARE);
    drawMarker(img, Point(300, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_UP);
    drawMarker(img, Point(350, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_DOWN);
    
    imshow("img", img);
    waitKey(0);
    
    destroyAllWindows();
}

void drawPolys()
{
    Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));
    
    rectangle(img, Rect(50, 50, 100, 50), Scalar(0, 0, 255), 2);
    rectangle(img, Rect(50, 150, 100, 50), Scalar(0, 0, 128), -1);
    
    circle(img, Point(300, 120), 30, Scalar(255, 255, 0), -1, LINE_AA);
    circle(img, Point(300, 120), 60, Scalar(255, 0, 0), 3, LINE_AA);
    
    ellipse(img, Point(120, 300), Size(60, 30), 20, 0, 270, Scalar(225, 255, 0), -1, LINE_AA);
    ellipse(img, Point(120, 300), Size(100, 50), 20, 0, 360, Scalar(0, 255, 0), 2, LINE_AA);
    
    vector<Point> pts;
    pts.push_back(Point(250, 250)); pts.push_back(Point(300, 250));
    pts.push_back(Point(300, 300)); pts.push_back(Point(350, 300));
    pts.push_back(Point(350, 350)); pts.push_back(Point(250, 350));
    polylines(img, pts, true, Scalar(255, 0, 255), 2);
    
    imshow("img", img);
    waitKey(0);
    
    destroyAllWindows();
}

int main()
{
    //drawLines();
    drawPolys();
}
