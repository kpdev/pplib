#include <iostream>

class MethodRegistrar
{
public:
    template<typename TMethod>
    MethodRegistrar(
            TMethod container[], 
            TMethod method, 
            int index,
            const char* info = nullptr)
    {
        if (info != nullptr) std::cout << info << '\n';
        container[index] = method;
    }
};


