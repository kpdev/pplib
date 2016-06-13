

#define CREATE_GENERALIZATION(Name) \
struct Name { \
    int mark; \
}; \
int GetSpecNumAndIncrement##Name();

#define DEFINE_GENERALIZATION_METHOD(Name) \
namespace { \
    int specNumber = 0; \
} \
int GetSpecNumAndIncrement##Name() { \
    return specNumber++; \
}
