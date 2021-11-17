#include "Addition_Operation_Command.hpp"


Addition_Operation::Addition_Operation(Addition* addition)
{
	this->_addition = addition;
}

int Addition_Operation::operationExecute (int secondeOperand, int firstOperand) {
	return this->_addition->add(secondeOperand, firstOperand);
}