#ifndef _ADD_OPERATION_COMMAND_H_
#define _ADD_OPERATION_COMMAND_H_

#include "Operation_Command.hpp"

class Add_Operation : public Operation_Command {
public:
	int operationExecute(int secondOperand, int firstOperand);
};

#endif