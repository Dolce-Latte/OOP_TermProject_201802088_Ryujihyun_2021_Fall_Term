#include "Facade_Calculator.hpp"

Facade::Facade(std::string expr) {
	this->_expressions = new Expressions();
	this->_calculations = new Calculations();
	this->_expr = expr;
}

Facade::~Facade() {}

void Facade::operationExpr() {
	this->_expressions->setPreExpressions(this->_expr);
	this->_expressions->changeNumber();
	this->_expressions->inExprToPostExpr();
	this->_expr = this->_expressions->getPostExpressions();
}

void Facade::operationCalc() {
	this->_calculations->setExpressions(this->_expr);
	this->_calculations->calculate();
	std::cout << this->_calculations->getResult() << std::endl << std::endl;
}