#include "Division_Operation_Command.hpp"


int Division_Operation::operationExecute(int secondOperand, int firstOperand) {
	if (firstOperand == 0) {
		//string e = "0���� ������ �����ϴ�.";
		throw "0���� ������ �����ϴ�.";
	}
	return secondOperand / firstOperand;
}