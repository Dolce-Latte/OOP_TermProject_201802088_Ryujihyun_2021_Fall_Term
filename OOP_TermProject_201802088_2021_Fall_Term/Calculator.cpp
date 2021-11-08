#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Command {
public:
	virtual int calculationExecute(int firstOperand, int secondOperand) = 0;
};

class Addition_Command : public Command {
public:
	Addition_Command()
};

class Calculator {
private:
	Expressions* expressions;
	stack<int> intStack;
	int result = 0;
public:
	
};

class Calculations {
private:
	int result;
	string expressions;
public:
	Calculations(string expressions, int result) {
		setExpressions(expressions);
		setResult(result);
	}

	void setResult(int result) {
		this->result = result;
	}
	void setExpressions(string expressions) {
		this->expressions = expressions;
	}

	int getResult() {
		return result;
	}
	string getExpressions() {
		return expressions;
	}

	int calculate();
};

int Calculations::calculate() {
	string str = this->getExpressions();
	int answer = this->getResult();
	stack<int> intStack;

	for (int i = 0; str[i] != NULL; i++) {
		char token = str[i];
		answer = 0;

		if (token == ' ') { continue; }
		if ('0' <= token && token <= '9') {
			answer = answer * 10 + (token - '0');
			token = str[++i];
		}
		else {
			int firstOperand = intStack.top();
			intStack.pop();
			int secondOperand = intStack.top();
			intStack.pop();

			switch (token) {

			}
		}
	}
}
class Expressions {
private:
	string postExpressions;
	string inExpressions;
public:
	Expressions(string inExpressions) {
		setInExpressions(inExpressions);
	}

	void setInExpressions(string inExpressions) {
		this->inExpressions = inExpressions;
	}
	void setPostExpressions(string postExpressions) {
		this->postExpressions = postExpressions;
	}

	string getInExpressions() {
		return inExpressions;
	}
	string getPostExpressions() {
		return postExpressions;
	}
	
	void changeNumberInExpr();
	void inFixToPostFix();
	void hexaDecimal(int& index, string& before, string& after);
	void binary(int& index, string& before, string& after);
	bool getPriority(char stackOperand, char currentOperand);
};

void Expressions::changeNumberInExpr()
{
	string str = this->getInExpressions();
	int len = str.length();
	string nStr;

	for (int i = 0; (i < len) && (str[i] != NULL); i++) {
		char token = str[i];
		if ('0' <= token && token <= '9') {
			if (token == '0') {
				if (str[i + 1] == 'x') {
					hexaDecimal(i, str, nStr);
				}
				else if (str[i + 1] == 'b') {
					binary(i, str, nStr);
				}
				else { nStr += token; }
			}
			else { nStr += token; }
		}
		else { nStr += token; }
	}
	setInExpressions(nStr);
	return;
}

void Expressions::inFixToPostFix()
{	
	string str = this->getInExpressions();
	stack<char> charStack;
	string postFix;

	for (int i = 0; inExpressions[i] != NULL; i++) {
		char token = inExpressions[i];

		if ('0' <= token && token <= '9') {
			postFix += token;
			if ('0' > inExpressions[i + 1] || inExpressions[i + 1] > '9') {
				postFix += " ";
			}
		}
		else if (token == '(') { charStack.push(token); }
		else if (token == '*') {
			if (charStack.empty()) { charStack.push(token); }
			else {
				char stackToken = charStack.top();
				if (getPriority(stackToken, token)) {
					postFix += charStack.top();
					postFix += " ";
					charStack.pop();
				}
				charStack.push(token);
			}
		}
		else if (token == '/') {
			if (charStack.empty()) { charStack.push(token); }
			else {
				char stackToken = charStack.top();
				if (getPriority(stackToken, token)) {
					postFix += charStack.top();
					postFix += " ";
					charStack.pop();
				}
				charStack.push(token);
			}
		}
		else if (token == '+') {
			if (charStack.empty()) { charStack.push(token); }
			else {
				char stackToken = charStack.top();
				if (getPriority(stackToken, token)) {
					postFix += charStack.top();
					postFix += " ";
					charStack.pop();
				}
				charStack.push(token);
			}
		}
		else if (token == '-') {
			if (charStack.empty()) { charStack.push(token); }
			else {
				char stackToken = charStack.top();
				if (getPriority(stackToken, token)) {
					postFix += charStack.top();
					postFix += " ";
					charStack.pop();
				}
				charStack.push(token);
			}
		}
		else if (token == ')') {
			int stackToken = charStack.top();
			charStack.pop();
			while (stackToken != '(') {
				postFix += stackToken;
				postFix += " ";
				stackToken = charStack.top();
				charStack.pop();
			}
		}
		else;
	}
	while (!charStack.empty()) {
		int stackToken = charStack.top();
		charStack.pop();
		if (stackToken != '(') { postFix += stackToken; }
	}
	setPostExpressions(postFix);
	return;
}

void Expressions::hexaDecimal(int& index, string& before, string& after)
{
	int len = before.length();
	int j;
	int hex = 0;
	string tmp;
	for (j = index + 2; (j < len) && (('0' <= before[j] && before[j] <= '9') || ('a' <= before[j] && before[j] <= 'f')); j++) {
		tmp += before[j];
	}
	hex = stoi(tmp, nullptr, 16);
	after += to_string(hex);
	index = j - 1;
	return;
}

void Expressions::binary(int& index, string& before, string& after)
{
	int len = before.length();
	int j;
	int bin = 0;
	string tmp;
	for (j = index + 2; (j < len) && ('0' <= before[j] && before[j] <= '1'); j++) {
		tmp += before[j];
	}
	bin = stoi(tmp, nullptr, 2);
	after += to_string(bin);
	index = j - 1;
	return;
}

bool Expressions::getPriority(char stackOperand, char currentOperand)
{
	if (stackOperand == '(') { return false; }
	if (currentOperand == '+' || currentOperand == '-') { return true; }
	else {
		if (stackOperand == '*' || stackOperand == '/') { return true; }
		else { return false; }
	}
	return false;
}

int main() {
	string exp;
	string re;
	cin >> exp;
	Expressions* expressions = new Expressions(exp);
	expressions->changeNumberInExpr();
	expressions->inFixToPostFix();
	cout << expressions->getPostExpressions() << endl;

	return 0;
}