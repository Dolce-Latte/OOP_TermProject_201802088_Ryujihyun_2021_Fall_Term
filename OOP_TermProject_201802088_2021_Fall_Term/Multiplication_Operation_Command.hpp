#ifndef _MULTIPLICATION_OPERATION_COMMAND_H
#define _MULTIPLICATION_OPERATION_COMMAND_H

#include "Operation_Command.hpp"
#include "Multiplication.hpp"

class Multiplication_Operation : public Operation_Command {
private:
	Multiplication* _multiplication;
public:
	Multiplication_Operation(Multiplication* multiplication);
	int operationExecute(int secondOperand, int firstOperand);
};

#endif