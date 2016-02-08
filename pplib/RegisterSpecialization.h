#include "ClassMarkRegistrar.h"


#define REGISTER_SPECIALIZATION(SpecName, IncrFunc, DebugInfo) \
    namespace \
    { \
        void InitRegMark##SpecName() \
        { \
            regMark##SpecName = IncrFunc(); \
        } \
        ClassMarkRegistrar reg##SpecName(InitRegMark##SpecName, DebugInfo); \
    }


