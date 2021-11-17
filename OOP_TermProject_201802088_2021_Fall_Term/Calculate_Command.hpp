#ifndef _CALCULATE_COMMAND_H_
#define _CALCULATE_COMMAND_H_

#include "Addition_Operation_Command.hpp"
#include "Subtraction_Operation_Command.hpp"
#include "Multiplication_Operation_Command.hpp"
#include "Division_Operation_Command.hpp"

class Calculate_Command {
private:
	Operation_Command* _opCommand;
public:
	void setCommand(Operation_Command* opCommand);
	int run(int secondOperand, int firstOperand);
};

#endif 
