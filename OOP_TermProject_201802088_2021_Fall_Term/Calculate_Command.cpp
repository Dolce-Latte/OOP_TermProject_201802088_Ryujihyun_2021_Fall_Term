#include "Calculate_Command.hpp"

void Calculate_Command::setCommand(Operation_Command* opCommand)
{
	this->_opCommand = opCommand;
}

int Calculate_Command::run(int secondOperand, int firstOperand) {
	return this->_opCommand->operationExecute(secondOperand, firstOperand);
}
