#ifndef _CALCULATIONS_H_
#define _CALCULATIONS_H_
#include<string>
#include<stack>
#include "Calculate_Command.hpp"

class Calculations {
private:
	int _result = 0;
	std::string _expr;
	Addition* _add = new Addition();
	Addition_Operation* _opAdd = new Addition_Operation(_add);
	Subtraction* _subtraction = new Subtraction();
	Subtraction_Operation* _opSub = new Subtraction_Operation(_subtraction);
	Multiplication* _multiple = new Multiplication();
	Multiplication_Operation* _opMul = new Multiplication_Operation(_multiple);
	Division* _div = new Division();
	Division_Operation* _opDiv = new Division_Operation(_div);
	Calculate_Command* _calCommand = new Calculate_Command();
public:

	void setExpressions(std::string expr);
	void setResult(int result);
	int getResult();
	std::string getExpressions();

	void calculate();
};

#endif