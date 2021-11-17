#ifndef _CALCULATIONS_H_
#define _CALCULATIONS_H_
#include<string>
#include<stack>
#include "Operation_Command.hpp"
#include "Addition_Operation_Command.hpp"
#include "Subtraction_Operation_Command.hpp"
#include "Multiplication_Operation_Command.hpp"
#include "Division_Operation_Command.hpp"

class Calculations {
private:
	int _result = 0;
	std::string _expr;
	Operation_Command* _calculations = nullptr;
public:

	void setExpressions(std::string expr);
	void setResult(int result);
	int getResult();
	std::string getExpressions();

	void calculate();
};

#endif