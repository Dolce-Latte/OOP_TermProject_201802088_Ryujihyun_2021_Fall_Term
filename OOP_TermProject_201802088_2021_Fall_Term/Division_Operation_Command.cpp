#include "Division_Operation_Command.hpp"


int Division_Operation::operationExecute(int secondOperand, int firstOperand) {
	if (firstOperand == 0) {
		throw std::logic_error("0으로 나눌 수 없습니다.");
	}
	return secondOperand / firstOperand;
}