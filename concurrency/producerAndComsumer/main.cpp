#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>

#define NUM_PRODUCER 10
#define NUM_CONSUMER 10
#define MAX_GOODS 100
int goods;
std::condition_variable cv;
std::mutex m;

[[noreturn]] void producer() {
    while(true) {
        {
            std::unique_lock<std::mutex> lk(m);
            cv.wait(lk, [] { return goods < MAX_GOODS; });
            goods += 1;
            std::cout << "produce a good. remain: " << goods << std::endl;
            cv.notify_all();
        }
//        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

}

[[noreturn]] void consumer() {
    while(true) {
        {
            std::unique_lock<std::mutex> lk(m);
            cv.wait(lk, [] { return goods > 0; });
            goods -= 1;
            std::cout << "consume a good. remain: " << goods << std::endl;
            cv.notify_all();
        }
//        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

}


int main() {    
    goods = 0;
    std::thread p[NUM_PRODUCER], c[NUM_CONSUMER];
    for(auto & i : p) {
        i = std::thread(producer);
    }
    for(auto & i : c) {
        i = std::thread(consumer);
    }
    for(auto & i : p) {
        i.join();
    }
    for(auto & i : c) {
        i.join();
    }
}