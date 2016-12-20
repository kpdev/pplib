
#ifndef REGISTER_METHOD_HEADER_GUARD
#define REGISTER_METHOD_HEADER_GUARD

#include <type_traits>
#include "MethodRegistrar.h"

#define GET_REG_MARK_METHOD(Type) \
  GetRegMark##Type()

#define REGISTER_METHOD(Container, Method, Mark, DebugInfo) \
    MethodRegistrar regMethod##Method(Container, Method, Mark, DebugInfo);


#define REGISTER_METHOD_WITH_CHECK_RET_PTR(Container, Method, DerivedClass, DebugInfo, FileMark, RetType) \
namespace { \
	RetType * __Inner_Check_##Method ( int file_mark ) { \
		if (file_mark == FileMark) { \
			auto ptr = Method(); \
			return ptr; \
		} \
		return nullptr; \
	} \
	REGISTER_METHOD(Container##FuncArray, __Inner_Check_##Method, GET_REG_MARK_METHOD(DerivedClass), DebugInfo); \
}

#define REGISTER_METHOD_WITH_CHECK(Container, Method, DebugInfo, DerivedClass, ...) \
using BaseClass = DerivedClass::base_type; \
namespace { \
	template <typename ... ArgsT> \
	void __Inner_Check_##Method (  BaseClass& bc, ArgsT ... args ) { \
		if ( bc.mark == GET_REG_MARK_METHOD(DerivedClass) ) { \
			Method( static_cast<DerivedClass&>(bc), args... ); \
		} \
		else { \
			cerr << #Method << ": incorrect convertion to" \
				<< #DerivedClass << '\n'; \
			throw; \
		} \
	} \
	auto __Inner_Check_##Method##FncToPass = __Inner_Check_##Method<__VA_ARGS__>; \
	REGISTER_METHOD(Container##FuncArray, __Inner_Check_##Method##FncToPass, GET_REG_MARK_METHOD(DerivedClass), DebugInfo); \
}

#endif // REGISTER_METHOD_HEADER_GUARD

