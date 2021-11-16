#include<iostream>
#include<string>
#include "Facade.hpp"

Facade::Facade(std::string expr) {
	this->_expressions = new Expressions(expr);
	this->_calculations = new Calculations(expr);
	this->_expr = expr;
}

Facade::~Facade() {}

void Facade::operationExpr() {
	this->_expressions->changeNumber();
	this->_expressions->inExprToPostExpr();
	this->_expr = this->_expressions->getExpressions();
}

void Facade::operationCalc() {
	this->_calculations->calculate();
	std::cout << this->_calculations->getResult() << std::endl;
}