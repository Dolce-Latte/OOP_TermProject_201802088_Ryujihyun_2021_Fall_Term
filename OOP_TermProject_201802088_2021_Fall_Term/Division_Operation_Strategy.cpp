#include "Division_Operation_Strategy.hpp"

Division_Operation::~Division_Operation() {}

int Division_Operation::operationExecute(int secondOperand, int firstOperand) {
	if (firstOperand == 0) {
		//string e = "0으로 나눌수 없습니다.";
		throw "0으로 나눌수 없습니다.";
	}
	return secondOperand / firstOperand;
}