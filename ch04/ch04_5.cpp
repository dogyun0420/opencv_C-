#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#include "ch04_5.hpp"

void time_inverse()
{
    Mat src = imread ("lena.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }
    
    Mat dst(src.rows, src.cols, src. type());
    
    TickMeter tm;
    tm.start();
    for (int j = 0; j < src.rows; j++) {
        for (int i = 0; i < src.cols; i++) {
            dst.at<uchar>(j, i) = 255 - src.at<uchar>(j, i);
        }
    }
    
    tm.stop();
    cout << " Image inverse took " << tm.getTimeMilli() << "ms." << endl;
}

int main()
{
    time_inverse();
}
