#ifndef _DIVISION_OPERATION_STRATEGY_H
#define _DIVISION_OPERATION_STRATEGY_H

#include "Operation_Command.hpp"
#include<iostream>

class Division_Operation : public Operation_Command {
public:
	~Division_Operation();
	int operationExecute(int secondOperand, int firstOperand);
};

#endif