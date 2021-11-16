#include<iostream>
#include<string>
#include "Facade.hpp"

int main() {

	std::string _input;
	Facade* calculator;

	while (true) {
		std::cout << "������ �Է��ϼ���.(���� : QUIT)" << std::endl;
		std::getline(std::cin, _input);

		if (_input == "QUIT") { break; }
		calculator = new Facade(_input);

		try{
			calculator->operationExpr();
			calculator->operationCalc();
		}
		catch (std::string e) {
			std::cout << e << std::endl;
		}
		catch (...) {
			std::cout << "�� �� ���� ����" << std::endl;
		}
	}

	return 0;
}