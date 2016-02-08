#include <iostream>

int GetSpecNumAndIncrement(); // TODO: move to its own header

class ClassMarkRegistrar
{
public:
    typedef void(*Initializer)();

    explicit ClassMarkRegistrar(Initializer init, const char* regInfo = nullptr)
    {
        init();
        if (regInfo != nullptr) std::cout << regInfo << std::endl;
    }
};




