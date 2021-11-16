#include"Expressions.hpp"

void Expressions::setPreExpressions(std::string preExpr) {
	this->_preExpr = preExpr;
}

void Expressions::setPostExpressions(std::string postExpr) {
	this->_postExpr = postExpr;
}
std::string Expressions::getPreExpressions() {
	return this->_preExpr;
}

std::string Expressions::getPostExpressions() {
	return this->_postExpr;
}

void Expressions::changeNumber() {
	std::string _oldExpr = this->getPreExpressions();
	std::string _newExpr;
	int _length = _oldExpr.length();

	for (int i = 0; (i < _length) && (_oldExpr[i] != NULL); i++) {
		char _stringToken = _oldExpr[i];
		if (isdigit(_stringToken)) {
			if (_stringToken == '0') {
				if (_oldExpr[i + 1] == 'x') {
					hexa(i, _oldExpr, _newExpr);
				}
				else if (_preExpr[i + 1] == 'b') {
					binary(i, _oldExpr, _newExpr);
				}
				else { _newExpr += _stringToken; }
			}
			else{ _newExpr += _stringToken; }
		}
		else{ _newExpr += _stringToken; }
	}
	this->setPostExpressions(_newExpr);
	return;
}

void Expressions::inExprToPostExpr() {
	std::string _oldExpr = this->getPreExpressions();
	std::string _newExpr;
	std::stack<char> _charStack;
	int PF = 0, NF = 0, OF = 0; //Parenthesis, Number, Operator flag

	for (int i = 0; _oldExpr[i] != NULL; i++) {
		char _currToken = _oldExpr[i];
		char _postToken = _oldExpr[i + 1];

		if (isdigit(_currToken)) {
			_newExpr += _currToken;
			if (!isdigit(_postToken)) {
				_newExpr += " ";
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
						_newExpr += _charStack.top();
						_newExpr += " ";
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
				_newExpr += _stackToken;
				_newExpr += " ";
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
		if (_stackToken != '(') { _newExpr += _stackToken; }
	}
	this->setPostExpressions(_newExpr);
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