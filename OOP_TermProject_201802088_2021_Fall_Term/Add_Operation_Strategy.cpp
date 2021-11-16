#include "Add_Operation_Command.hpp"

Add_Operation::~Add_Operation(){}

int Add_Operation::operationExecute (int secondeOperand, int firstOperand) {
	return secondeOperand + firstOperand;
}