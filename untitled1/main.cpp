#include <iostream>

class Mult {
public:
    virtual auto mult (unsigned a , unsigned b) -> unsigned long = 0;
};

class MultOptimierer : public Mult {
    Mult &m;

public:
    explicit MultOptimierer(Mult &mult) : m(mult) {}
    unsigned long mult (unsigned a , unsigned b) override{

        if(a >  b)
            return m.mult(b,a);
        return m.mult(a,b);
    }
};

class MultImpl : public Mult{

public:
    unsigned long mult (unsigned a , unsigned b) override{
        unsigned long result= 0;

        for (int i = 0; i < a; ++i) {
            result += b;
        }
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
