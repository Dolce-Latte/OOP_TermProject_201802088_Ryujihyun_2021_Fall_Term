#ifndef _MULTIPLICATION_OPERATION_COMMAND_H
#define _MULTIPLICATION_OPERATION_COMMAND_H

#include "Operation_Command.hpp"

class Multiplication_Operation : public Operation_Command {
public:
	int operationExecute(int secondOperand, int firstOperand);
};

#endif