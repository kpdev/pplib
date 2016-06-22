

#define DECLARE_MM(TypeName, Dimention, RetType, ...) \
typedef RetType (*TypeName)(__VA_ARGS__); \
extern TypeName TypeName##MM[][Dimention];

#define DEFINE_MM(TypeName, Dimention1, Dimention2) \
TypeName TypeName##MM[Dimention1][Dimention2];

