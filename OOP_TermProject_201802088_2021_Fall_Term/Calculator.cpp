#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Expressions {
private:
	string postExpressions;
	string inExpressions;
	int answer = 0;
public:
	Expressions(string inExpressions) {
		this->inExpressions = inExpressions;
	}

	~Expressions() {};

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

	void inFixToPostFix(string inExpressions);
	bool getPriority(char stackOperand, char currentOperand);
};

void Expressions::inFixToPostFix(string inExpressions)
{
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
	Expressions* expressions;


}