#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#include "ch04_1.hpp"


void camera_in()
{
    VideoCapture cap(0);
    
    if (!cap.isOpened()){
        cerr << "Camera open failde" << endl;
        return;
    }
    
    cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
    
    Mat frame, inversed;
    while (true) {
        cap >> frame;
        if (frame.empty())
            break;
        
        inversed = ~frame;
        
        imshow("frame", frame);
        imshow("inversed", inversed);
        
        if(waitKey(10) == 27)
            break;
        
    }
    
    destroyAllWindows();
}

void camera_in_video_out()
{
    VideoCapture cap(0);
    
    if (!cap.isOpened()){
        cerr << "Camera open failed!" << endl;
        return;
    }
    
    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(CAP_PROP_FPS);
    
    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
    int delay = cvRound(1000 / fps);
    
    VideoWriter outputVideo("output.avi", fourcc, fps, Size(w,h));
    
    if (!outputVideo.isOpened()){
        cout << "File open failde!" << endl;
        return;
    }
    
    Mat frame, inversed;
    while (true) {
        cap >> frame;
        if (frame.empty())
            break;
        inversed = ~frame;
        outputVideo << inversed;
        
        imshow("frame", frame);
        imshow("inversed", inversed);
        
        if (waitKey(delay) == 27)
            break;
    }
    destroyAllWindows();
    
}
int main()
{
    
    //MatCless();
    //Matcopy();
    //ScalarOp();
    //camera_in();
    camera_in_video_out();
    return 0;
}

