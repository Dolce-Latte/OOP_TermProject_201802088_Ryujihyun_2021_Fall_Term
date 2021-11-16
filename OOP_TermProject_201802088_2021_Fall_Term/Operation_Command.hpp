#ifndef _OPERATION_COMMAND_H_
#define _OPERATION_COMMAND_H_
#include<iostream>

class Operation_Command {
public:
	
	//Execute method to be implement in all subclasses
	virtual int operationExecute(int secondOperand, int firstOperand) = 0;
};


#endif