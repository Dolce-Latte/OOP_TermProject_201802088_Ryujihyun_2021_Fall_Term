#include "Facade.hpp"

int main() {

	std::string _input;
	Facade* calculator;

	while (true) {
		std::cout << "수식을 입력하세요.(종료 : QUIT or EOF)" << std::endl;
		std::cin >> _input;

		if (_input == "QUIT" || std::cin.eof()) { 
			std::cout << "계산기를 종료합니다." << std::endl << std::endl;
			break;
		}
		calculator = new Facade(_input);

		try{
			calculator->operationExpr();
			calculator->operationCalc();
		}
		catch (std::logic_error& e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		catch (...) {
			std::cout << "알 수 없는 오류" << std::endl << std::endl;
		}
	}

	return 0;
}