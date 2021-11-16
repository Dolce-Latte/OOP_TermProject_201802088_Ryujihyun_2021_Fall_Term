#ifndef _OPERATION_STRATEGY_H_
#define _OPERATION_STRATEGY_H_

class Operation_Command {
public:
	
	//Destructor
	virtual ~Operation_Command(void) = 0;
	
	//Execute method to be implement in all subclasses
	virtual int operationExecute(int secondOperand, int firstOperand) = 0;
};


#endif