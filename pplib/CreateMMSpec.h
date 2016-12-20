
#ifndef CREATE_MM_SPEC_HEADER_GUARD
#define CREATE_MM_SPEC_HEADER_GUARD

#include "RegisterMethod.h"


#define CREATE_MM_SPEC(MethodName, Type1, Type2, MethodImpl) \
using BaseType = Type1::base_type; \
static_assert(std::is_same<BaseType, Type2::base_type>::value, "Basic types must be the same"); \
template<typename ... ArgsT> \
void MethodName(BaseType &f1, BaseType &f2, ArgsT ...args) \
{ \
	if(f1.mark == GET_REG_MARK_METHOD(Type1) && f2.mark == GET_REG_MARK_METHOD(Type2)) { \
		MethodImpl(static_cast<Type1&>(f1), static_cast<Type2&>(f2), args...); \
	} \
	else { \
		cout << #MethodName ": Incorrect convertion one of parameters" << endl; \
		throw; \
	} \
}


#define BEGIN_REG_MM(ArrayName) \
namespace { \
	class ArrayName##MMArray##Register { \
	public: \
		ArrayName##MMArray##Register(const char * regInfo = nullptr) { \
			if (regInfo != nullptr) cout << regInfo << endl; \
			auto& _array_alias = ArrayName##MMArray;

#define REG_MM_SPEC(SpecName, Type1, Type2) \
			_array_alias[GET_REG_MARK_METHOD(Type1)][GET_REG_MARK_METHOD(Type2)] = SpecName; \
			cout << "    multimethodFunc[" << GET_REG_MARK_METHOD(Type1) << "][" << GET_REG_MARK_METHOD(Type2) << "] = " #SpecName << endl;

#define END_REG_MM(OptionalMessage) \
		} \
	} \
	pplib_mm_reg##__COUNTER__(OptionalMessage); \
}

#endif // CREATE_MM_SPEC_HEADER_GUARD
