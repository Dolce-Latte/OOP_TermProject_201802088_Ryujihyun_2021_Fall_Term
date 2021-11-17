#include "Division.hpp"

int Division::division(int secondOperand, int firstOperand) {
	if (firstOperand == 0) {
		throw std::logic_error("0으로 나눌수 없습니다!!");
	}

	return secondOperand / firstOperand;
}