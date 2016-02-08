
#define CREATE_REG_MARK_METHOD(SpecName) \
    namespace { \
        int regMark##SpecName = -1; \
        int GetRegMark##SpecName() \
        { \
            return regMark##SpecName; \
        } \
    }


