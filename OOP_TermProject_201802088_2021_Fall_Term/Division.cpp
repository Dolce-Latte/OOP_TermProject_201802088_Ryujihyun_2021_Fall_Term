#include "Division.hpp"

int Division::division(int secondOperand, int firstOperand) {
	if (firstOperand == 0) {
		throw std::logic_error("0���� ������ �����ϴ�!!");
	}

	return secondOperand / firstOperand;
}