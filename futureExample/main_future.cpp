#include <iostream>
#include <future>
#include <thread>

int main()
{
    // future from a packaged_task
    std::packaged_task<int()> task([]{ std::chrono::milliseconds timespan(4000);
        std::this_thread::sleep_for(timespan);
        return 7; }); // wrap the function
    std::future<int> f1 = task.get_future();  // get a future
    std::thread t(std::move(task)); // launch on a thread

    std::cout << "Waiting..." << std::flush;
    f1.wait();

    std::cout << "Done!\nResults are: "
              << f1.get() << '\n';
    t.join();
}