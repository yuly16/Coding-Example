#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <vector>

std::mutex mutex;
std::condition_variable cv;
std::vector<int> vec;

void Consume() {
    std::unique_lock<std::mutex> lock(mutex);
    cv.wait(lock);
    std::cout << "consume " << vec.size() << "\n";
}

void Produce() {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::unique_lock<std::mutex> lock(mutex);
    vec.push_back(1);
    cv.notify_all();
    std::cout << "produce \n";
}

// 正常运行的一个程序。
int main() {
    std::thread t(Consume);
    Produce();
    t.join();
    return 0;
}