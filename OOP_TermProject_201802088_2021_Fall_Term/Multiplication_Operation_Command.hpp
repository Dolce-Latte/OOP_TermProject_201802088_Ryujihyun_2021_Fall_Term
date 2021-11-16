#ifndef _MULTIPLICATION_OPERATION_STRATEGY_H
#define _MULTIPLICATION_OPERATION_STRATEGY_H

#include "Operation_Command.hpp"
#include<iostream>

class Multiplication_Operation : public Operation_Command {
public:
	~Multiplication_Operation();
	int operationExecute(int secondOperand, int firstOperand);
};

#endif