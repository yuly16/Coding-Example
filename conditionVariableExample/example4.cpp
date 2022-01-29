#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <vector>

std::mutex mutex;
std::condition_variable cv;
std::vector<int> vec;
bool ready;
void Consume() {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::unique_lock<std::mutex> lock(mutex);
    cv.wait(lock, []{return ready;});
    std::cout << "consume " << vec.size() << "\n";
}

void Produce() {
    std::unique_lock<std::mutex> lock(mutex);
    vec.push_back(1);
    ready = true;
    cv.notify_all();
    std::cout << "produce \n";
}
//为了解决example3出现的问题，这里在cv处加上了一个while条件判断
int main() {
    ready = false;
    std::thread t(Consume);
    Produce();
    t.join();
    return 0;
}