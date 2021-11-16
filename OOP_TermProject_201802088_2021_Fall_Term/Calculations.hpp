#ifndef _CALCULATIONS_H_
#define _CALCULATIONS_H_
#include<string>
#include "Operation_Command.hpp"
#include "Add_Operation_Command.hpp"
#include "Subtraction_Operation_Command.hpp"
#include "Multiplication_Operation_Command.hpp"
#include "Division_Operation_Command.hpp"

class Calculations {
private:
	int _result = 0;
	std::string _expr;
	Operation_Command* _calculations = nullptr;
public:
	
	Calculations(std::string expr) {}
	~Calculations() {}

	void setExpressions(std::string expr);
	void setResult(int result);
	int getResult();
	std::string getExpressions();

	void calculate();
};

#endif