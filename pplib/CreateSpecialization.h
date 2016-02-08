

#define CREATE_SPECIALIZATION(Name, BaseName, SpecName) \
    struct Name : BaseName { \
        SpecName r; \
    };



