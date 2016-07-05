#ifndef METHOD_REGISTRAR_HEADER_GUARD
#define METHOD_REGISTRAR_HEADER_GUARD

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
        if (info != nullptr) { 
			std::cout << info << "\n\tindex: " << index << '\n'; 
		}

        container[index] = method;
    }
};

#endif // METHOD_REGISTRAR_HEADER_GUARD

