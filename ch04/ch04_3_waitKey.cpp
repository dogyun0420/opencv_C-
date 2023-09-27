#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#include "ch04_3_waitKey.hpp"

void eventKey()
{
    Mat img = imread("lena.bmp");
    
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return ;
    }
    
    namedWindow ("img");
    imshow ("img", img);
    
    while (true) {
        int keycode = waitKey();
        
        if (keycode =='i' || keycode =='I'){
            img = ~img;
            imshow("img",
            img);
        }
        else if (keycode == 27 || keycode == 'q' || keycode == 'Q'){
            break;
        }
    }
    return;
    
}

void on_level_change(int pos, void* userdata)
{
    Mat img = *(Mat*)userdata;
    
    img.setTo(pos * 16);
    imshow("image", img);
}



void m_img(){
    Mat img = Mat::zeros(400, 400, CV_8UC1);
    
    namedWindow("imagr");
    createTrackbar ("level", "image", 0, 16, on_level_change, (void*)&img);
    imshow("image", img);
    waitKey(0);
    
    return;
                    
}
int main()
{
    m_img();
    //eventKey();
}
