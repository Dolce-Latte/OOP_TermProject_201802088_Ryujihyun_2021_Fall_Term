#include "InFix_To_PostFix.h"
void in_To_Post(char* inExpression, char* postExpression) {
	stack<char> charStack;

	int index = 0;
	for (int i = 0; inExpression[i] != NULL; i++) {
		char token = inExpression[i];

		if (token == ' ')
			continue;

		if ('0' <= token && token <= '9') {
			postExpression[index++] = token;

			if (inExpression[i + 1] == NULL) {
				postExpression[index++] = ' ';
			}
			else if ('0' > inExpression[i + 1] || inExpression[i + 1] > '9') {
				postExpression[index++] = ' ';
			}
			continue;
		}

		if (token == '(') {
			charStack.push(token);
		}

		if (token == '*') {
			if (charStack.empty()) {
				charStack.push(token);
			}
			else {
				char buffer = charStack.top();
				if (getOrder(buffer, token)) {
					postExpression[index++] = charStack.top();
					charStack.pop();
					postExpression[index++] = ' ';
				}
				charStack.push(token);
			}
		}
		if (token == '/') {
			if (charStack.empty()) {
				charStack.push(token);
			}
			else {
				char buffer = charStack.top();
				if (getOrder(buffer, token)) {
					postExpression[index++] = charStack.top();
					charStack.pop();
					postExpression[index++] = ' ';
				}
				charStack.push(token);
			}
		}
		if (token == '+') {
			if (charStack.empty()) {
				charStack.push(token);
			}
			else {
				char buffer = charStack.top();
				if (getOrder(buffer, token)) {
					postExpression[index++] = charStack.top();
					charStack.pop();
					postExpression[index++] = ' ';
				}
			}
		}
		if (token == '-') {
			if (charStack.empty()) {
				charStack.push(token);
			}
			else {
				char buffer = charStack.top();
				if (getOrder(buffer, token)) {
					postExpression[index++] = charStack.top();
					charStack.pop();
					postExpression[index++] = ' ';
				}
			}
		}
		if (token == ')') {
			int buffer = charStack.top();
			charStack.pop();
			while (buffer != '(') {
				postExpression[index++] = buffer;
				postExpression[index++] = ' ';
				buffer = charStack.top();
				charStack.pop();
			}

		}
	}
	while (!charStack.empty()) {
		int buffer = charStack.top();
		charStack.pop();
		if (buffer != '(')
			postExpression[index++] = buffer;
	}
	postExpression[index] = NULL;
}

bool getOrder(char stackTopOp, char newOp) {
	if (stackTopOp == '(')
		return false;
	if (newOp == '+' || newOp == '-')
		return true;
	else {
		if (stackTopOp == '*' || stackTopOp == '/')
			return true;
		else
			return false;
	}
}