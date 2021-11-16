#ifndef _MULTIPLICATION_OPERATION_STRATEGY_H
#define _MULTIPLICATION_OPERATION_STRATEGY_H

#include "Operation_Strategy.hpp"
#include<iostream>

class Multiplication_Operation : public Operation_Strategy {
public:
	~Multiplication_Operation();
	int operationExecute(int secondOperand, int firstOperand);
};

#endif