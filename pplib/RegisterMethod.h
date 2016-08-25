
#ifndef REGISTER_METHOD_HEADER_GUARD
#define REGISTER_METHOD_HEADER_GUARD

#include "MethodRegistrar.h"

#define REGISTER_METHOD(Container, Method, Mark, DebugInfo) \
    MethodRegistrar regMethod##Method(Container, Method, Mark, DebugInfo);


#define REGISTER_METHOD_WITH_CHECK_RET_PTR(Container, Method, GenMark, DebugInfo, FileMark, RetType) \
namespace { \
	RetType* __Inner_Check_##Method ( int file_mark ) { \
		if (file_mark == FileMark) { \
			auto ptr = Method(); \
			return ptr; \
		} \
		return nullptr; \
	} \
	REGISTER_METHOD(Container, __Inner_Check_##Method, GenMark, DebugInfo); \
}

#define REGISTER_METHOD_WITH_CHECK(Container, Method, GenMark, DebugInfo, DerivedClass, BaseClass, ...) \
namespace { \
	template <typename ... ArgsT> \
	void __Inner_Check_##Method (  BaseClass& bc, ArgsT ... args ) { \
		if ( bc.mark == GenMark ) { \
			Method( static_cast<DerivedClass&>(bc), args... ); \
		} \
		else { \
			cerr << #Method << ": incorrect convertion from " \
				<< #BaseClass << " to " << #DerivedClass << '\n'; \
			throw; \
		} \
	} \
	auto __Inner_Check_##Method##FncToPass = __Inner_Check_##Method<__VA_ARGS__>; \
	REGISTER_METHOD(Container, __Inner_Check_##Method##FncToPass, GenMark, DebugInfo); \
}

#endif // REGISTER_METHOD_HEADER_GUARD

