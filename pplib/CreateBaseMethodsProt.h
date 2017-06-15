#pragma once

#define FUNC_TES(FuncName, RetType, BaseType, ...)\
RetType FuncName(BaseType&, __VA_ARGS__);

#define FUNC_TEST_NO_PARAMS(FuncName, RetType,BaseType) \
RetType FuncName(BaseType&);
