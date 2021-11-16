#ifndef _DIVISION_OPERATION_STRATEGY_H
#define _DIVISION_OPERATION_STRATEGY_H

#include "Operation_Strategy.hpp"
#include<iostream>

class Division_Operation : public Operation_Strategy {
public:
	~Division_Operation();
	int operationExecute(int secondOperand, int firstOperand);
};

#endif