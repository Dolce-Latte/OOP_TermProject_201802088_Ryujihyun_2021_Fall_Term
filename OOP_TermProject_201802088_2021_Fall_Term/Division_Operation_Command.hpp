#ifndef _DIVISION_OPERATION_COMMAND_H
#define _DIVISION_OPERATION_COMMAND_H

#include "Operation_Command.hpp"
#include "Division.hpp"

class Division_Operation : public Operation_Command {
private:
	Division* _division;
public:
	Division_Operation(Division* division);
	int operationExecute(int secondOperand, int firstOperand);
};

#endif