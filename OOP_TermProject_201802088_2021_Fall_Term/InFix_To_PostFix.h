#include<iostream>
#include<stack>
#pragma once

using namespace std;

void in_To_Post(char* inExpression, char* postExpression);
bool getOrder(char stackTopOp, char newOP);