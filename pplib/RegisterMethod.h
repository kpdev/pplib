
#ifndef REGISTER_METHOD_HEADER_GUARD
#define REGISTER_METHOD_HEADER_GUARD

#include "MethodRegistrar.h"

#define REGISTER_METHOD(Container, Method, Mark, DebugInfo) \
    MethodRegistrar regMethod##Method(Container, Method, Mark, DebugInfo);

#define REGISTER_METHOD_WITH_CHECK_RET_PTR(Container, Method, GenMark, DebugInfo, FileMark, RetType) \
	RetType* __Inner_Check_##Method ( int file_mark ) { \
		if (file_mark == FileMark) { \
			auto ptr = Method(); \
			return ptr; \
		} \
		return nullptr; \
	} \
	REGISTER_METHOD(Container, __Inner_Check_##Method, GenMark, DebugInfo);

#endif // REGISTER_METHOD_HEADER_GUARD

