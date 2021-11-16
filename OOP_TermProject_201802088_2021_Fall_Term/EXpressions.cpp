#include"Expressions.hpp"

Expressions::Expressions(std::string expr) : _expr(expr) {}

Expressions::~Expressions() {}

void Expressions::setExpressions(std::string expr) {
	this->_expr = expr;
}

std::string Expressions::getExpressions() {
	return this->_expr;
}

void Expressions::changeNumber() {
	std::string _preExpr = this->getExpressions();
	std::string _postExpr;
	int _length = _preExpr.length();

	for (int i = 0; (i < _length) && (_preExpr[i] != NULL); i++) {
		char _stringToken = _preExpr[i];
		if (isdigit(_stringToken)) {
			if (_stringToken == '0') {
				if (_preExpr[i + 1] == 'x') {
					hexa(i, _preExpr, _postExpr);
				}
				else if (_preExpr[i + 1] == 'b') {
					binary(i, _preExpr, _postExpr);
				}
				else { _postExpr += _stringToken; }
			}
			else{ _postExpr += _stringToken; }
		}
		else{ _postExpr += _stringToken; }
	}
	this->setExpressions(_postExpr);
	return;
}

void Expressions::inExprToPostExpr() {
	std::string _preExpr = this->getExpressions();
	std::string _postExpr;
	std::stack<char> _charStack;
	int PF = 0, NF = 0, OF = 0; //Parenthesis, Number, Operator flag

	for (int i = 0; _preExpr[i] != NULL; i++) {
		char _currToken = _preExpr[i];
		char _postToken = _preExpr[i + 1];

		if (isdigit(_currToken)) {
			_postExpr += _currToken;
			if (!isdigit(_postToken)) {
				_postExpr += " ";
				NF++;
			}
		}
		else if (_currToken == '(') {
			_charStack.push(_currToken);
			PF++;
		}
		else if (_currToken == '*' || _currToken == '+' || _currToken == '-' || _currToken == '/') {
			if (_postToken == '*' || _postToken == '+' || _postToken == '-' || _postToken == '/') {
				throw "잘못된 수식입력!!";
			}
			else {
				if (_charStack.empty()) {
					_charStack.push(_currToken);
					OF++;
				}
				else {
					char _stackToken = _charStack.top();
					if (getPriority(_stackToken, _currToken)) {
						_postExpr += _charStack.top();
						_postExpr += " ";
						_charStack.pop();
					}
					_charStack.push(_currToken);
					OF++;
				}
			}
		}
		else if (_currToken == ')') {
			int _stackToken = _charStack.top();
			_charStack.pop();
			while (_stackToken != '(') {
				_postExpr += _stackToken;
				_postExpr += " ";
				_stackToken = _charStack.top();
				_charStack.pop();
			}
			PF--;
		}
		else {
			throw "알 수 없는 입력!!";
		}
	}
	if ((PF != 0) || (NF == OF)) {
		throw "괄호 또는 숫자, 수식 입력이 잘못되었습니다!!";
	}
	while (!_charStack.empty()) {
		int _stackToken = _charStack.top();
		_charStack.pop();
		if (_stackToken != '(') { _postExpr += _stackToken; }
	}
	this->setExpressions(_postExpr);
	return;
}

void Expressions::hexa(int& index, std::string& beforeExpr, std::string& afterExpr) {
	int _length = beforeExpr.length();
	int _tmpIndex;
	int _hexNum = 0;
	std::string _tmpExpr;
	for (_tmpIndex = index + 2; (_tmpIndex < _length) && (isdigit(beforeExpr[_tmpIndex]) || islower(beforeExpr[_tmpIndex])); _tmpIndex++) {
		_tmpExpr += beforeExpr[_tmpIndex];
	}
	_hexNum = stoi(_tmpExpr, nullptr, 16);
	afterExpr += std::to_string(_hexNum);
	index = _tmpIndex - 1;
	return;
}

void Expressions::binary(int& index, std::string& beforeExpr, std::string& afterExpr) {
	int _length = beforeExpr.length();
	int _tmpIndex;
	int _binNum = 0;
	std::string _tmpExpr;
	for (_tmpIndex = index + 2; (_tmpIndex < _length) && (isdigit(beforeExpr[_tmpIndex])); _tmpIndex++) {
		_tmpExpr += beforeExpr[_tmpIndex];
	}
	_binNum = stoi(_tmpExpr,nullptr,2);
	afterExpr += std::to_string(_binNum);
	index = _tmpIndex - 1;
	return;
}

bool Expressions::getPriority(char stackOperand, char currOperand) {
	if (stackOperand == '(') { return false; }
	if (currOperand == '+' || currOperand == '-') { return true; }
	else {
		if (stackOperand == '*' || stackOperand == '/') { return true; }
		else { return false; }
	}
	return false;
}