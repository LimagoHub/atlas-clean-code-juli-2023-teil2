#include <iostream>
#include <thread>
#include <vector>

class ThreadDemo {

    size_t threaddCount{3};
    std::vector<std::thread> threadHolder;

    auto worker(int start)->void {
        std::cout << "Worker " << start << std::endl;
    }

    void initializeThreads() {
        threadHolder.reserve(threaddCount);
    }

    void startWorker() {
        for (int i = 0; i < threaddCount; ++i) {
            threadHolder.emplace_back(&ThreadDemo::worker, this, i);
        }
    }

    void joinThreads() {
        for( auto & t : threadHolder)
            t.join();
    }
public:
    ThreadDemo() {}




    auto go() -> void {
        initializeThreads();
        startWorker();
        joinThreads();
    }
};

int main() {
    ThreadDemo demo;
    demo.go();
    return 0;
}
