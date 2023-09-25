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

int main()
{
    
    //MatCless();
    //Matcopy();
    //ScalarOp();
    camera_in();
    return 0;
}

