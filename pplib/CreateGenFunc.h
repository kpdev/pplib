
#ifndef CREATE_GEN_FUNC_HEADER_GUARD
#define CREATE_GEN_FUNC_HEADER_GUARD


#define DECLARE_GEN_FUNC(TypeName, RetType, ...) \
typedef RetType (*TypeName##Func)(__VA_ARGS__); \
extern TypeName##Func TypeName##FuncArray[]; \
RetType TypeName( __VA_ARGS__ );


#define DEFINE_GEN_FUNC(TypeName, Number) \
TypeName TypeName##Array[Number];


#endif // CREATE_GEN_FUNC_HEADER_GUARD

