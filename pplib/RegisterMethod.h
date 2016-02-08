#include "MethodRegistrar.h"

#define REGISTER_METHOD(Container, Method, Mark, DebugInfo) \
    MethodRegistrar regMethod##Method(Container, Method, Mark, DebugInfo);


