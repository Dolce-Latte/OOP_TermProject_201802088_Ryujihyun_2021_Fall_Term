#include "Subtraction_Operation_Command.hpp"

Subtraction_Operation::~Subtraction_Operation() {}

int Subtraction_Operation::operationExecute(int secondOperation, int firstOperation) {
	return secondOperation - firstOperation;
}