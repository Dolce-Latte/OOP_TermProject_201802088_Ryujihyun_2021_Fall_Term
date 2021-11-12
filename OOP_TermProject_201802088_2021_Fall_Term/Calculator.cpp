#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Command {
public:
	virtual ~Command(){};
	virtual int calculationExecute(int secondOperand, int firstOperand) = 0;
};

class Addition_Command : public Command {
public:
	int calculationExecute(int secondOperand, int firstOperand) override {
		return secondOperand + firstOperand;
	}
};

class Subtraction_Command : public Command {
public:
	int calculationExecute(int secondOperand, int firstOperand) override {
		return secondOperand - firstOperand;
	}
};

class Multiplication_Command : public Command {
public:
	int calculationExecute(int secondOperand, int firstOperand) override {
		return secondOperand * firstOperand;
	}
};

class Division_Command : public Command {
public:
	int calculationExecute(int secondOperand, int firstOperand) override {
		if (firstOperand == 0) {
			string e = "0으로 나눌수 없습니다.";
			throw e;
		}
		return secondOperand / firstOperand;
	}
};

class Calculations {
private:
	int result = 0;
	string expressions;
	Command* cal_Command = nullptr;
public:

	void setExpressions(string expressions) {
		this->expressions = expressions;
	}

	void setResult(int result) {
		this->result = result;
	}

	int getResult() {
		return result;
	}
	string getExpressions() {
		return expressions;
	}

	void calculate();
};

void Calculations::calculate() {
	string str = this->getExpressions();
	int answer;
	stack<int> intStack;

	for (int i = 0; str[i] != NULL; i++) {
		char token = str[i];
		answer = 0;

		if (token == ' ') { continue; }
		if ('0' <= token && token <= '9') {
			answer = token - '0';
			token = str[++i];
			while ('0' <= token && token <= '9') {
				answer = answer * 10 + (token - '0');
				token = str[++i];
			}
		}
		else {
			int firstOperand = intStack.top();
			intStack.pop();
			int secondOperand = intStack.top();
			intStack.pop();

			switch (token) {
			case '+':
				cal_Command = new Addition_Command();
				answer = cal_Command->calculationExecute(secondOperand, firstOperand);
				break;
			case '-':
				cal_Command = new Subtraction_Command();
				answer = cal_Command->calculationExecute(secondOperand, firstOperand);
				break;
			case '*':
				cal_Command = new Multiplication_Command();
				answer = cal_Command->calculationExecute(secondOperand, firstOperand);
				break;
			case '/':
				cal_Command = new Division_Command();
				answer = cal_Command->calculationExecute(secondOperand, firstOperand);
				break;
			}
		}
		intStack.push(answer);
	}
	answer = intStack.top();
	intStack.pop();
	this->setResult(answer);
	delete cal_Command;
	return;
}
class Expressions {
private:
	string postExpressions;
	string inExpressions;
public:

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
	int countParenthesis = 0;
	int NF = 0, OF = 0;

	for (int i = 0; inExpressions[i] != NULL; i++) {
		char currentToken = inExpressions[i];
		char postToken = inExpressions[i + 1];

		if (isdigit(currentToken)) {
			postFix += currentToken;
			if (!isdigit(postToken)) {
				postFix += " ";
				NF++;
			}
		}
		else if (currentToken == '(') {
			charStack.push(currentToken);
			countParenthesis++;
		}
		else if (currentToken == '*' || currentToken == '+' || currentToken == '/' || currentToken == '-') {
			if (postToken == '+' || postToken == '-' || postToken == '*' || postToken == '/') {
				string e = "잘못된 수식입력입니다.";
				throw e;
			}
			else{
				if (charStack.empty()) { 
					charStack.push(currentToken);
					OF++;
				}
				else {
					char stackToken = charStack.top();
					if (getPriority(stackToken, currentToken)) {
						postFix += charStack.top();
						postFix += " ";
						charStack.pop();
					}
					charStack.push(currentToken);
					OF++;
				}
			}
		}
		else if (currentToken == ')') {
			int stackToken = charStack.top();
			charStack.pop();
			while (stackToken != '(') {
				postFix += stackToken;
				postFix += " ";
				stackToken = charStack.top();
				charStack.pop();
			}
			countParenthesis--;
		}
		else {
			string e = "잘못된 수식입력입니다.";
			throw e;
		}
	}
	if ((countParenthesis != 0) || (NF == OF)) {
		string e = "잘못된 수식입력입니다.";
		throw e;
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
	for (j = index + 2; (j < len) && ((isdigit(before[j])) || ('a' <= before[j] && before[j] <= 'f')); j++) {
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
	for (j = index + 2; (j < len) && (isdigit(before[j])); j++) {
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

class Calculator {
private:
	Expressions* expressions;
	Calculations* calculations;
	string str_;
public:
	Calculator(string expr){
		this->expressions = new Expressions();
		this->calculations = new Calculations();
		this->str_ = expr;
	}

	void operation();
};

void Calculator::operation() {
	string numerical_;
	expressions->setInExpressions(str_);
	expressions->changeNumberInExpr();
	expressions->inFixToPostFix();
	numerical_ = expressions->getPostExpressions();
	calculations->setExpressions(numerical_);
	calculations->calculate();
	cout << calculations->getResult() << endl;
	
}
int main() {
	
	string input;
	Calculator* calculator;
	while (true) {
		cout << "수식을 입력하세요.(종료 : QUIT)" << endl;
		getline(cin, input);

		if (input == "QUIT") {
			break;
		}
		calculator = new Calculator(input);

		try {
			calculator->operation();
		}
		catch (string e) {
			cout << e << endl;
		}
		catch (...) {
			cout << "알 수 없는 오류" << endl;
		}
	}
	
	/*string expressions;
	cin >> expressions;
	Calculator* calculator = new Calculator(expressions);
	try {
		calculator->operation();
	}
	catch (string e) {
		cout << e << endl;
	}*/
	
	
	

	return 0;
}
