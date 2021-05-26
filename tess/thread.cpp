#include <thread>
#include <iostream>

void mult(int x){
    for(int i=0; i<x; i++){
        std::cout << i << " "<< "thread id"<< std::this_thread::get_id() <<std::endl;
    }
}

int main()
{
    std::thread t1(mult, 3);
    std::thread t2(mult, 4);
    t1.join();
    t2.detach();
    int num = std::thread::hardware_concurrency();
    std::cout << num << std::endl;

    if(t2.joinable()){
        t2.join();
    }
    else{
        std::cout << "Thread not joinable" << std::endl;
    }


}