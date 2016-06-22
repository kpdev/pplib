#define CREATE_SPECIALIZATION_DECORATOR(Name, BaseName, GeneralizationName , AddFieldType, AddFieldName) \
    struct Name : BaseName { \
        AddFieldType AddFieldName; \
        BaseName* GeneralizationName; \
    }; \
	int GetRegMark##Name();
