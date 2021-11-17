#ifndef _FACADE_CALCULATOR_H_
#define _FACADE_CALCULATOR_H_
#include "Expressions.hpp"
#include "Calculations.hpp"

class Facade {
private:
	Expressions* _expressions = nullptr;
	Calculations* _calculations = nullptr;
	std::string _expr;
public:
	Facade(std::string expr);
	~Facade();

	void operationExpr();
	void operationCalc();
};

#endif