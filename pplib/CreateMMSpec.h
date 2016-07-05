
#ifndef CREATE_MM_SPEC_HEADER_GUARD
#define CREATE_MM_SPEC_HEADER_GUARD

#define CREATE_MM_SPEC(MethodName, BaseType, Type1, Type2, GetMark1, GetMark2, MethodImpl) \
template<typename ... ArgsT> \
void MethodName(BaseType &f1, BaseType &f2, ArgsT ...args) \
{ \
	if(f1.mark == GetMark1() && f2.mark == GetMark2()) { \
		MethodImpl(static_cast<Type1&>(f1), static_cast<Type2&>(f2), args...); \
	} \
	else { \
		cout << #MethodName ": Incorrect convertion one of parameters" << endl; \
		throw; \
	} \
}


#define BEGIN_REG_MM(ArrayName) \
namespace { \
	class ArrayName##Register { \
	public: \
		ArrayName##Register(const char * regInfo = nullptr) { \
			if (regInfo != nullptr) cout << regInfo << endl; \
			auto& _array_alias = ArrayName;

#define REG_MM_SPEC(SpecName, GetMark1, GetMark2) \
			_array_alias[GetMark1()][GetMark2()] = SpecName; \
			cout << "    multimethodFunc[" << GetMark1() << "][" << GetMark2() << "] = " #SpecName << endl;

#define END_REG_MM(OptionalMessage) \
		} \
	} \
	pplib_mm_reg##__COUNTER__(OptionalMessage); \
}

#endif // CREATE_MM_SPEC_HEADER_GUARD
