

#ifndef CREATE_REG_MARK_METHOD_HEADER_GUARD
#define CREATE_REG_MARK_METHOD_HEADER_GUARD

#define CREATE_REG_MARK_METHOD(SpecName) \
    namespace { \
        int regMark##SpecName = -1; \
	} \
    int GetRegMark##SpecName() \
    { \
        return regMark##SpecName; \
    }


#endif // CREATE_REG_MARK_METHOD_HEADER_GUARD

