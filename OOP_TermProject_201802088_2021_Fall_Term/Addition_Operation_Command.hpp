#ifndef _ADDITION_OPERATION_COMMAND_H_
#define _ADDITION_OPERATION_COMMAND_H_

#include "Operation_Command.hpp"
#include "Addition.hpp"

class Addition_Operation : public Operation_Command {
private:
	Addition* _addition;
public:
	Addition_Operation(Addition* addition);
	int operationExecute(int secondOperand, int firstOperand);
};

#endif