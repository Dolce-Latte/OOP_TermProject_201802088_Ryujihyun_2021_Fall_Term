#include "Division_Operation_Command.hpp"


Division_Operation::Division_Operation(Division* division)
{
	this->_division = division;
}

int Division_Operation::operationExecute(int secondOperand, int firstOperand) {
	return this->_division->division(secondOperand, firstOperand);
}