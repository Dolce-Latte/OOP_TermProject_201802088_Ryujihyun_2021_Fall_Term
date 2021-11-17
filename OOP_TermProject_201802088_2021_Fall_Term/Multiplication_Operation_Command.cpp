#include "Multiplication_Operation_Command.hpp"


Multiplication_Operation::Multiplication_Operation(Multiplication* multiplication)
{
	this->_multiplication = multiplication;
}

int Multiplication_Operation::operationExecute(int secondOperand, int firstOperand) {
	return this->_multiplication->multiplication(secondOperand, firstOperand);
}
