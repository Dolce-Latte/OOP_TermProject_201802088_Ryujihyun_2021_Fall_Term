#ifndef _EXPRESSIONS_H_
#define _EXPRESSIONS_H_
#include<string>
#include<stack>

class Expressions {
private:
	std::string _expr;
public:

	Expressions(std::string expr){}
	~Expressions() {}
	void setExpressions(std::string expr);
	std::string getExpressions();

	void changeNumber();
	void inExprToPostExpr();
	void hexa(int& index, std::string& beforeExpr, std::string& afterExpr);
	void binary(int& index, std::string& beforeExpr, std::string& afterExpr);
	bool getPriority(char stackOperand, char currOperand);
};

#endif