#ifndef _ADD_OPERATION_STRATEGY_H_
#define _ADD_OPERATION_STRATEGY_H_

#include "Operation_Strategy.hpp"
#include<iostream>

class Add_Operation : public Operation_Strategy {
public:
	~Add_Operation();
	int operationExecute(int secondOperand, int firstOperand);
};

#endif