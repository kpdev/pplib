#include <memory>

#define DECLARE_MM(TypeName, Dimention, BaseType, ...) \
typedef void (*TypeName)(BaseType&, BaseType&, __VA_ARGS__); \
extern TypeName TypeName##MMArray[][Dimention]; \
 \
template<typename ...ArgsT> \
void TypeName##MM(BaseType &p1, BaseType &p2, ArgsT ...args) \
{ \
	(TypeName##MMArray[p1.mark][p2.mark])( p1, p2, std::forward<ArgsT>(args)... ); \
}

#define DEFINE_MM(TypeName, Dimention) \
TypeName TypeName##MM##Array[Dimention][Dimention]; \
 

