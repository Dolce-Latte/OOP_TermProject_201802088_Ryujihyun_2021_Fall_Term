#include<iostream>
#include<string>
#include "Facade.hpp"

int main() {

	std::string _input;
	Facade* calculator;

	while (true) {
		std::cout << "수식을 입력하세요.(종료 : QUIT)" << std::endl;
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
			std::cout << "알 수 없는 오류" << std::endl;
		}
	}

	return 0;
}