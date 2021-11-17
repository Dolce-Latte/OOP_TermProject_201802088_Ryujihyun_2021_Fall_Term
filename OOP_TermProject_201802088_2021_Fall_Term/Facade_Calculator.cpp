#include "Facade_Calculator.hpp"

Facade_Calculator::Facade_Calculator(std::string expr) {
	this->_expressions = new Expressions();
	this->_calculations = new Calculations();
	this->_expr = expr;
}

Facade_Calculator::~Facade_Calculator() {}

void Facade_Calculator::operationExpr() {
	this->_expressions->setPreExpressions(this->_expr);
	this->_expressions->changeNumber();
	this->_expressions->inExprToPostExpr();
	this->_expr = this->_expressions->getPostExpressions();
}

void Facade_Calculator::operationCalc() {
	this->_calculations->setExpressions(this->_expr);
	this->_calculations->calculate();
	std::cout << this->_calculations->getResult() << std::endl << std::endl;
}