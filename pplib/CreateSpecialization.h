
#ifndef CREATE_SPECIALIZATION_HEADER_GUARD
#define CREATE_SPECIALIZATION_HEADER_GUARD

#define CREATE_SPECIALIZATION(Name, BaseName, SpecName) \
    struct Name : BaseName { \
        using base_type = BaseName; \
        SpecName _spec; \
    }; \
	int GetRegMark##Name();


#endif // CREATE_SPECIALIZATION_HEADER_GUARD

