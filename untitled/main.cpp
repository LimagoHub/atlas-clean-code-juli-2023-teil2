#include <iostream>
#include <string>
#include <memory>
class Auto {
public:
    Auto(int a) {
        std::cout << "Konstruktor von Auto"<< std::endl;
    }

    virtual ~Auto() {
        std::cout << "Destruktor von Auto"<< std::endl;
    }

    auto bar()->void {
        std::cout << "Funktion bar von Auto" << std::endl;
    }

};


auto source() -> std::unique_ptr<Auto> {
    std::unique_ptr<Auto> result = std::make_unique<Auto>(1);
    return result;
}

auto sink(std::unique_ptr<Auto> ptr)-> std::unique_ptr<Auto> {
    ptr->bar();
    return ptr;
}

int main() {

    std::unique_ptr<Auto> myPtr = source();

    myPtr = sink(std::move(myPtr));

    return 0;
}
