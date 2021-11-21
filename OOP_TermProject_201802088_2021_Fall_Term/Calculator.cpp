#include "Facade_Calculator.hpp"

int main() {

	std::string _input;
	Facade_Caculator* calculator;

	while (true) {
		std::cout << "수식을 입력하세요.(종료 : QUIT or EOF)" << std::endl;
		std::cin >> _input;
		if (_input == "QUIT" || std::cin.eof()) { 
			std::cout << "계산기를 종료합니다." << std::endl << std::endl;
			break;
		}
		calculator = new Facade_Caculator(_input);

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
	delete calculator;
	return 0;
}