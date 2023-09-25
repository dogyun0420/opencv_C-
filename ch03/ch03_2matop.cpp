#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//#include "ch03_2matop.hpp"

void MatCless(){
    Mat img1;
    
    Mat img2(480, 640, CV_8UC1);    //unsigned Char, 1채널 그레이
    Mat img3(480, 640, CV_8UC3);    //unsigned Char, 3채널 컬러
    
    Mat img4(Size(680, 480), CV_8UC3);   //Size(W, H)
    
    Mat img5(480, 640, CV_8UC3, Scalar(128));   //initial values, 128
    Mat img6(480, 640, CV_8UC3, Scalar(0, 0, 225));     //initial values RED (B, G, R)
}

void Matcopy(){
    Mat img1 = imread("lena.bmp");
    //얕은 복사
    Mat img2 = img1;
    Mat img3;
    img3 = img1;
    //깊은 복사
    Mat img4 = img1.clone();
    
    Mat img5;
    img1.copyTo(img5);
    
    img1.setTo(Scalar(0, 255, 255));
    imshow("img1", img1);
    imshow("img2", img2);
    imshow("img3", img3);
    imshow("img4", img4);
    imshow("img5", img5);
}

void ScalarOp(){
    Scalar gray = 128;
    cout << "gray : " << gray << endl;
    
    Scalar yellow(0, 255, 255);
    cout << "Yellow : " << yellow << endl;
    
    Mat img1(256, 256, CV_8UC3, yellow);
    
    for ( int i = 0; i < 4; i++)
        cout << yellow[i] << endl;
}
int main()
{
    
    //MatCless();
    //Matcopy();
    //ScalarOp();
    return 0;
}
