#include "Calculations.hpp"
#include<iostream>
#include<stack>
Calculations::Calculations(std::string expr) : _expr(expr) {}

Calculations::~Calculations() {}

void Calculations::setExpressions(std::string expr) {
	this->_expr = expr;
}

void Calculations::setResult(int result) {
	this->_result = result;
}

int Calculations::getResult() {
	return this->_result;
}

std::string Calculations::getExpressions() {
	return this->_expr;
}

void Calculations::calculate() {
	std::string _calExpr = this->getExpressions();
	int _answer = 0;
	std::stack<int> _intStack;

	for (int i = 0; _calExpr[i] != NULL; i++) {
		char _charToken = _calExpr[i];

		if (_charToken == ' ') { continue; }
		if (isdigit(_charToken)) {
			_answer = _charToken - '0';
			_charToken = _calExpr[++i];
			while (isdigit(_charToken)) {
				_answer = _answer * 10 + (_charToken - '0');
				_charToken = _calExpr[++i];
			}
		}
		else {
			int _firstOperand = _intStack.top();
			_intStack.pop();
			int _secondOperand = _intStack.top();
			_intStack.pop();

			switch (_charToken) {
			case'+':
				_calculations = new Add_Operation();
				_answer = _calculations->operationExecute(_secondOperand, _firstOperand);
				break;
			case'-':
				_calculations = new Subtraction_Operation();
				_answer = _calculations->operationExecute(_secondOperand, _firstOperand);
				break;
			case'*':
				_calculations = new Multiplication_Operation();
				_answer = _calculations->operationExecute(_secondOperand, _firstOperand);
				break;
			case'/':
				_calculations = new Division_Operation();
				_answer = _calculations->operationExecute(_secondOperand, _firstOperand);
				break;
			}
		}
		_intStack.push(_answer);
	}
	_answer = _intStack.top();
	_intStack.pop();
	this->setResult(_answer);
	delete _calculations;
	return;
}