#include "Facade.hpp"

int main() {

	std::string _input;
	Facade* calculator;

	while (true) {
		std::cout << "������ �Է��ϼ���.(���� : QUIT or EOF)" << std::endl;
		std::cin >> _input;

		if (_input == "QUIT" || std::cin.eof()) { 
			std::cout << "���⸦ �����մϴ�." << std::endl << std::endl;
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
			std::cout << "�� �� ���� ����" << std::endl << std::endl;
		}
	}

	return 0;
}