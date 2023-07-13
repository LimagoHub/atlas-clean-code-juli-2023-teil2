#include <iostream>
#include <algorithm>
#include <memory>

class Translator {
public:
    virtual auto translate(std::string message)->std::string = 0;
};

class ToUpperTranslator : public Translator {
public:
    auto translate(std::string message) -> std::string override {
        std::transform(message.begin(),message.end(),message.begin(),::toupper);
        return message;
    }
};

class ToLowerTranslator : public Translator {
public:
    auto translate(std::string message) -> std::string override {
        std::transform(message.begin(),message.end(),message.begin(),::tolower);
        return message;
    }
};

class Demo {
    std::unique_ptr<Translator> translator;

public:
    explicit Demo(std::unique_ptr<Translator>  translator) : translator(std::move(translator)) {}

    auto go() -> void {
        std::string s = "Hallo Welt";
        auto a = translator->translate(s);
        std::cout << a << std::endl;
    }
};


std::unique_ptr<Translator> createTranslator(bool upper = true);



int main() {

    std::unique_ptr<Translator> translator = createTranslator(false);


    Demo demo{std::move(translator)};
    demo.go();

    return 0;
}


std::unique_ptr<Translator> createTranslator(bool upper) {
    std::unique_ptr<Translator> translator;

    if(upper)
        translator = std::make_unique<ToUpperTranslator>();
    else
        translator = std::make_unique<ToLowerTranslator>();

    return translator;
}