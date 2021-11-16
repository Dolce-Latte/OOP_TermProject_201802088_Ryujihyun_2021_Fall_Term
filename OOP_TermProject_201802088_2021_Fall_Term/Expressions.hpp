#ifndef _EXPRESSIONS_H_
#define _EXPRESSIONS_H_
#include<iostream>
#include<string>
#include<stack>

class Expressions {
private:
	std::string _preExpr;
	std::string _postExpr;
public:
	void setPreExpressions(std::string preExpr);
	void setPostExpressions(std::string postExpr);
	std::string getPreExpressions();
	std::string getPostExpressions();

	void changeNumber();
	void inExprToPostExpr();
	void hexa(int& index, std::string& beforeExpr, std::string& afterExpr);
	void binary(int& index, std::string& beforeExpr, std::string& afterExpr);
	bool getPriority(char stackOperand, char currOperand);
};

#endif