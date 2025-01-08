#pragma once
#include "../expression.h"

namespace ArithmeticPoints{
namespace Expressions{
template <typename Type>
class Operation: public Expression<Type>{
public:	
    static int getArity();
};
}
}