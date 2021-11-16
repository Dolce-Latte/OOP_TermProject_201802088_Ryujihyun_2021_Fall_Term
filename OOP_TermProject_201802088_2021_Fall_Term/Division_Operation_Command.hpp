#ifndef _DIVISION_OPERATION_COMMAND_H
#define _DIVISION_OPERATION_COMMAND_H

#include "Operation_Command.hpp"

class Division_Operation : public Operation_Command {
public:
	int operationExecute(int secondOperand, int firstOperand);
};

#endif