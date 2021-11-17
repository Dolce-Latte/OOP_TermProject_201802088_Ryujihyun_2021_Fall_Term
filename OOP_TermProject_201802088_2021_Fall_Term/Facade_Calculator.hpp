#ifndef _FACADE_CALCULATOR_H_
#define _FACADE_CALCULATOR_H_
#include "Expressions.hpp"
#include "Calculations.hpp"

class Facade_Calculator {
private:
	Expressions* _expressions = nullptr;
	Calculations* _calculations = nullptr;
	std::string _expr;
public:
	Facade_Calculator(std::string expr);
	~Facade_Calculator();

	void operationExpr();
	void operationCalc();
};

#endif