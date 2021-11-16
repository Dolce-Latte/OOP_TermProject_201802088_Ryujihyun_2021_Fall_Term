#ifndef _SUBTRACTION_OPERATION_STRATEGY_H_
#define _SUBTRACTION_OPERATION_STRATEGY_H_

#include "Operation_Command.hpp"
#include<iostream>

class Subtraction_Operation : public Operation_Command {
public:
	~Subtraction_Operation();
	int operationExecute(int secondOperand, int firstOperand);
};
#endif