#ifndef _FACADE_CALCULATOR_H_
#define _FACADE_CALCULATOR_H_
#include "Expressions.hpp"
#include "Calculations.hpp"

class Facade_Caculator {
private:
	Expressions* _expressions = nullptr;
	Calculations* _calculations = nullptr;
	std::string _expr;
public:
	Facade_Caculator(std::string expr);
	
	void operationExpr();
	void operationCalc();
};

#endif