#include "Subtraction_Operation_Command.hpp"


Subtraction_Operation::Subtraction_Operation(Subtraction* subtraction)
{
	this->_subtraction = subtraction;
}

int Subtraction_Operation::operationExecute(int secondOperation, int firstOperation) {
	return this->_subtraction->subtraction(secondOperation,firstOperation);
}