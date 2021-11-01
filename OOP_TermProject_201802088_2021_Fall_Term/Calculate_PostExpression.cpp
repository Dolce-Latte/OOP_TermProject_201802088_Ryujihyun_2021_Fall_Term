#include "Calculate_PostExpression.h"

int calculatePostFix(char* postExpression) {
	stack<int> intStack;

	int operand;
	for (int i = 0; postExpression[i] != NULL; i++) {
		char token = postExpression[i];
		operand = 0;

		if (token == ' ')
			continue;

		if ('0' <= token && token <= '9') {
			operand = token - '0';
			token = postExpression[++i];
			while ('0' <= token && token <= '9') {
				operand = operand * 10 + (token - '0');
				token = postExpression[++i];
			}
			i--;
		}
		else {

			int rightOperand = intStack.top();
			intStack.pop();

			int leftOperand = intStack.top();
			intStack.pop();

			switch (token) {
			case '+': {
				operand = leftOperand + rightOperand;
				break;
			}
			case '-': {
				operand = leftOperand - rightOperand;
				break;
			}
			case '*': {
				operand = leftOperand * rightOperand;
				break;
			}
			case '/': {
				operand = leftOperand / rightOperand;
				break;
			}
			}
		}
		intStack.push(operand);
	}
	int result = intStack.top();
	intStack.pop();
	return result;
}