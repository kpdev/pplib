
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


