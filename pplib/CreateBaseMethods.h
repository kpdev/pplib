#ifndef CREATE_BASE_METHODS_HEADER_GUARD
#define CREATE_BASE_METHODS_HEADER_GUARD



#define INIT_v2(TypeName) \
template <typename TypeName, typename ... TArgs> \
void Init(TypeName& generalizationName, TArgs ... args) \
{ \
  generalizationName.mark = GetRegMark##TypeName(); \
  auto& c = generalizationName._spec; \
  Init(c, args...); \
}

#define INIT(TypeName, SpecName, ...) \
void Init(TypeName& generalizationName, ...) { \
    generalizationName.mark = GetRegMark##TypeName(); \
    SpecName& c = generalizationName._spec; \
    Init(c, __VA_ARGS__); \
} 

#define CREATE(TypeName) \
TypeName* Create##TypeName() { \
    TypeName* object = new TypeName; \
    Init(*object, 0); \
    return object; \
} 

#define CREATEANDINIT(TypeName,  ...) \
TypeName* Create##TypeName##AndInit(...) { \
    TypeName* object = Create##TypeName(); \
    Init(*object, __VA_ARGS__); \
    return object; \
}

#define IN(TypeName, SpecName) \
void In(TypeName& generalizationName, ifstream &ifst) { \
    SpecName& c = generalizationName._spec; \
    In(ifst, c); \
}

#define OUT(TypeName, SpecName) \
void Out(TypeName& generalizationName, ofstream &ifst) { \
    SpecName& c = generalizationName._spec; \
    Out(ifst, c); \
}

#define DELETE(TypeName) \
void Delete##TypeName(TypeName& object) { \
    delete &object; \
}

#endif 