#pragma once

#define FUNC_TES(FuncName, RetType, BaseType, ...)\
RetType FuncName(BaseType&, __VA_ARGS__);
