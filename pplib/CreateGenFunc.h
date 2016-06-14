

#define DECLARE_GEN_FUNC(TypeName, RetType, ...) \
typedef RetType (*TypeName)(__VA_ARGS__); \
extern TypeName TypeName##Array[];

#define DEFINE_GEN_FUNC(TypeName, Number) \
TypeName TypeName##Array[Number];


