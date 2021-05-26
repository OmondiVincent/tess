#include <fstream>
#include <iostream>
#include <cstdlib>
#include "/home/alan/C++/Machine/core.cpp"
#include <opencv2/core/utils/trace.hpp>

using namespace cv;
using namespace cv::dnn;
using namespace std;

//namespace fs=std::fileystem;

static std::string CLASS[] = {"background", "aeroplane", "bicycle", "bird", "boat",
	"bottle", "bus", "car", "cat", "chair", "cow", "diningtable",
	"dog", "horse", "motorbike", "person", "pottedplant", "sheep",
	"sofa", "train", "tvmonitor"};

//std::string modelTxt = "/home/alan/data/MobileNetSSD_deploy.prototxt";
//std::string modelBin = "/home/alan/data/MobileNetSSD_deploy.caffemodel";

//template <class T> 

class Read_Frame
{
    private:
        cv::VideoCapture cap;
        std::string modelTxt;
        std::string modelBin;

    public:
        template <class T > Read_Frame(T txt);
        cv::dnn::Net load_model();

        void load_conf_();

};