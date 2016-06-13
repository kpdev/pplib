#include <iostream>

int GetSpecNumAndIncrement(); // TODO: move to its own header

class ClassMarkRegistrar
{
public:
    typedef void(*Initializer)();

    explicit ClassMarkRegistrar(Initializer init, const char* regInfo = nullptr)
    {
        if (regInfo != nullptr) std::cout << regInfo << std::endl;
        init();
    }
};




