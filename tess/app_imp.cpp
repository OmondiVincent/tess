#include "app_Int.h"
#include <chrono>
#include <thread>


/*Read_Frame::Read_Frame(){
    Read_Frame::modelTxt = "/home/alan/data/MobileNetSSD_deploy.prototxt";
    Read_Frame::modelBin = "/home/alan/data/MobileNetSSD_deploy.caffemodel";
}*/

template <class T> Read_Frame::Read_Frame(T txt): cap(txt), 
                    modelTxt("/home/alan/data/MobileNetSSD_deploy.prototxt"),
                     modelBin("/home/alan/data/MobileNetSSD_deploy.caffemodel"){
                std::cout << "Loading  default configuration" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));

}

cv::dnn::Net Read_Frame::load_model(){
    cv::dnn::Net net = dnn::readNetFromCaffe(modelTxt, modelBin);
    if (net.empty()){
        std::cerr << "Can't load network by using the following files: " << std::endl;
        std::cerr << "prototxt:   " << modelTxt << std::endl;
        std::cerr << "caffemodel: " << modelBin << std::endl;
        exit(-1);
    }
    else{
        return net;
    }
}

void Read_Frame::load_conf_(){
    Process_video one;
    Process_frame frame;
    CV_TRACE_FUNCTION();

    //Read_Frame::cap.open(0);
    //("http://192.168.43.1:4747/mjpegfeed?1280x720", cv::CAP_FFMPEG);
    //Read_Frame::cap.set(cv::CAP_PROP_BUFFERSIZE, 1);
    //Read_Frame::cap.set(cv::CAP_PROP_FPS, 15);

    for(;;){
        cv::Mat img;
        Read_Frame::cap >> img;
        
        cv::dnn::Net net = load_model();

        cv::Mat inputBlob = blobFromImage(img, 0.007843, Size(300,300), Scalar(127.5, 127.5, 127.5), false);

        net.setInput(inputBlob, "data");
        cv::Mat detection = net.forward("detection_out");
        cv::Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

        ostringstream ss;
        float confidenceThreshold = 0.2;

        for (int i = 0; i < detectionMat.rows; i++){
            float confidence = detectionMat.at<float>(i, 2);

            if (confidence > confidenceThreshold){
                int idx = static_cast<int>(detectionMat.at<float>(i, 1));
                int xLeftBottom = static_cast<int>(detectionMat.at<float>(i, 3) * img.cols);
                int yLeftBottom = static_cast<int>(detectionMat.at<float>(i, 4) * img.rows);
                int xRightTop = static_cast<int>(detectionMat.at<float>(i, 5) * img.cols);
                int yRightTop = static_cast<int>(detectionMat.at<float>(i, 6) * img.rows);

                cv::Rect object((int)xLeftBottom, (int)yLeftBottom,
                            (int)(xRightTop - xLeftBottom),
                            (int)(yRightTop - yLeftBottom));

                rectangle(img, object, Scalar(0, 255, 0), 2);

                cout << CLASS[idx] << ": " << confidence << endl;

                ss.str("");
                ss << confidence;
                string conf(ss.str());
                string label = CLASS[idx] + ": " + conf;
                int baseLine = 0;
                Size labelSize = cv::getTextSize(label, FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
                cv::putText(img, label, cv::Point(xLeftBottom, yLeftBottom),
                        FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0,0,0));
                if (CLASS[idx]=="person"){
                    cv::Rect object = one.conf(img);
                    cv::rectangle(img, object, cv::Scalar(255, 0, 0), 2, 8, 0);
                }
            }
        }
        frame.show(img, 1);
    }
}