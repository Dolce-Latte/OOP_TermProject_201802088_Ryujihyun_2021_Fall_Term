#include<iostream>
#include<string>
#include<stack>
#include<sstream>
#include<vector>
#include<iterator>
#include "InFix_To_PostFix.h"

using namespace std;

//class Strategy {
//public:
//	virtual int doOperation(int operand1, int operand2) = 0;
//	virtual double doOperation(double operand1, double operand2) = 0;
//};
//
//class OperationAdd : public Strategy {
//public:
//	int doOperation(int operand1, int operand2) {
//		return operand1 + operand2;
//	}
//	double doOperation(double operand1, double operand2) {
//		return operand1 + operand2;
//	}
//};
//
//class OperationSubstract : public Strategy{
//public:
//	int doOperation(int operand1, int operand2) {
//		return operand1 - operand2;
//	}
//	double doOperation(double operand1, double operand2) {
//		return operand1 - operand2;
//	}
//};
//
//class OperationMultiply : public Strategy {
//public:
//	int doOperation(int operand1, int operand2) {
//		return operand1 * operand2;
//	}
//	double doOperation(double operand1, double operand2) {
//		return operand1 * operand2;
//	}
//};
//
////³ª´°¼À ±¸ÇöÇØ¾ßÇÔ.
//
//class Calc {
//private:
//	Strategy *strategy;
//public:
//
//};

int main() {
	char inFix[50];
	char postFix[50];

	cout << "PreFix" << endl;
	cin.getline(inFix, 50);

	in_To_Post(inFix, postFix);

	cout << endl << "postFix" << endl << postFix << endl;
	return 0;
}