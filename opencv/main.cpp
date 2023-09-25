#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main1()
{
    cout << "Hello OpenCV" << CV_VERSION << std::endl;
    
    Mat img;
    img = imread("lena.bmp");
    
    if (img.empty()){
        cerr<< "Imege load faliled!"<< std::endl;
        return -1;
    }
    
    namedWindow("Image");
    imshow("Image", img);
    
    moveWindow("Image", 500, 100);
    
    
    cv::waitKey(0);
    return 0;
}
