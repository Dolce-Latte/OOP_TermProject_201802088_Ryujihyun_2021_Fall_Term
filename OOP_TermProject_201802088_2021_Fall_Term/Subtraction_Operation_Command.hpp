#ifndef _SUBTRACTION_OPERATION_COMMAND_H_
#define _SUBTRACTION_OPERATION_COMMAND_H_

#include "Operation_Command.hpp"
#include "Subtraction.hpp"

class Subtraction_Operation : public Operation_Command {
private:
	Subtraction* _subtraction;
public:
	Subtraction_Operation(Subtraction* subtraction);
	int operationExecute(int secondOperand, int firstOperand);
};
#endif