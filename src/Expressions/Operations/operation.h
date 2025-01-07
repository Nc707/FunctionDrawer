#pragma once
#include "../expression.h"

template <typename Type>
class Operation: public Expression<Type>{
public:	
    static int getArity();
};