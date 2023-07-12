#include <iostream>
#include <climits>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>

#define MAX_SIZE INT_MAX/4

class Demo {
public:
    auto run()-> void {
        std::vector<int> data(MAX_SIZE);
        auto start = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < MAX_SIZE ;++i) {
            data.at(i) = rand();
        }
        auto ende = std::chrono::high_resolution_clock::now();
        std::cout << std::endl << "Zeit: " << std::chrono::duration_cast<std::chrono::milliseconds>(ende-start).count() << " ms" << std::endl;
    }
};


auto main() ->int{

    Demo demo;
    demo.run();
    return 0;
}
