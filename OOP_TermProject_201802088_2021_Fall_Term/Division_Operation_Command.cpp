#include "Division_Operation_Command.hpp"


int Division_Operation::operationExecute(int secondOperand, int firstOperand) {
	if (firstOperand == 0) {
		throw std::logic_error("0���� ���� �� �����ϴ�.");
	}
	return secondOperand / firstOperand;
}