
#ifndef CREATE_SPECIALIZATION_DECORATOR_HEADER_GUARD
#define CREATE_SPECIALIZATION_DECORATOR_HEADER_GUARD

#define CREATE_SPECIALIZATION_DECORATOR(Name, BaseName, GeneralizationName , AddFieldType, AddFieldName) \
    struct Name : BaseName { \
        AddFieldType AddFieldName; \
        BaseName* GeneralizationName; \
    }; \
	int GetRegMark##Name();

#endif // CREATE_SPECIALIZATION_DECORATOR_HEADER_GUARD

