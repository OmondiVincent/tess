#include "app_imp.cpp"
#include <thread>
#include <iostream>

int main()
{
    //Read_Frame fs("http://192.168.43.1:4747/mjpegfeed?1280x720");
    Read_Frame fs1(0);
    //Read_Frame fs1(0);
    //fs.load_conf_();
    //fs1.load_conf_();
    //std::thread j1(&Read_Frame::load_conf_, std::ref(fs));
    std::thread j2(&Read_Frame::load_conf_, std::ref(fs1));

    //j1.join();
    j2.join();

}