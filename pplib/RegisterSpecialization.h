
#ifndef REGISTER_SPECIALIZATION_HEADER_GUARD
#define REGISTER_SPECIALIZATION_HEADER_GUARD

#include "ClassMarkRegistrar.h"

#define REGISTER_SPECIALIZATION_OLD_VERSION(SpecName, IncrFunc, DebugInfo) \
    namespace \
    { \
        void InitRegMark##SpecName() \
        { \
            regMark##SpecName = IncrFunc(); \
        } \
        ClassMarkRegistrar reg##SpecName(InitRegMark##SpecName, DebugInfo); \
    }

#define REGISTER_SPECIALIZATION(GenName, SpecName, DebugInfo) \
    namespace \
    { \
        void InitRegMark##SpecName() \
        { \
            regMark##SpecName = GetSpecNumAndIncrement##GenName(); \
			if (DebugInfo != nullptr) { \
				cout << "   regMark: " << regMark##SpecName << endl; \
			} \
        } \
        ClassMarkRegistrar reg##SpecName(InitRegMark##SpecName, DebugInfo); \
    }

#endif // REGISTER_SPECIALIZATION_HEADER_GUARD

