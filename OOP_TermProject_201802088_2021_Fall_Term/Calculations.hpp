#ifndef _CALCULATIONS_H_
#define _CALCULATIONS_H_
#include<string>
#include<stack>
#include "Calculate_Command.hpp"

class Calculations {
private:
	int _result = 0;
	std::string _expr;
	Addition_Operation* _opAdd = new Addition_Operation(new Addition);
	Subtraction_Operation* _opSub = new Subtraction_Operation(new Subtraction);
	Multiplication_Operation* _opMul = new Multiplication_Operation(new Multiplication);
	Division_Operation* _opDiv = new Division_Operation(new Division);
	Calculate_Command* _calCommand = new Calculate_Command();
public:

	void setExpressions(std::string expr);
	void setResult(int result);
	int getResult();
	std::string getExpressions();

	void calculate();
};

#endif