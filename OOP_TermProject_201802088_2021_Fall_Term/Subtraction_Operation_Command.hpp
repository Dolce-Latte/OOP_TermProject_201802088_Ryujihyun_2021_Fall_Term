#ifndef _SUBTRACTION_OPERATION_COMMAND_H_
#define _SUBTRACTION_OPERATION_COMMAND_H_

#include "Operation_Command.hpp"

class Subtraction_Operation : public Operation_Command {
public:
	int operationExecute(int secondOperand, int firstOperand);
};
#endif