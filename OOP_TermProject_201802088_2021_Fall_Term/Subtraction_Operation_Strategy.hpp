#ifndef _SUBTRACTION_OPERATION_STRATEGY_H_
#define _SUBTRACTION_OPERATION_STRATEGY_H_

#include "Operation_Strategy.hpp"
#include<iostream>

class Subtraction_Operation : public Operation_Strategy {
public:
	~Subtraction_Operation();
	int operationExecute(int secondOperand, int firstOperand);
};
#endif