#include <iostream>
#include <string>
#include <algorithm>
#include "stack.h"
#include "trapezoid.h"
#include "point.h"

int main() {
	containers::TStack<TTrapezoid<int>> s;
	std::string cmd;
	int index;
	std::cout << "ps - to push figure to stack\n"
			  << "i  - to insert figure to stack\n"
			  << "p  - to pop figure from Stack\n"
			  << "e  - to delete figure from Stack\n"
			  << "t  - to show first figure\n"
			  << "f  - to print figures\n"
			  << "c  - to print quantity of figures with square less then given\n"
			  << "ex - to finish execution of program\n";
	while (true) {
		std::cin >> cmd;
		if (cmd == "ps") {
			std::cout << "enter coordinates\n";
			TTrapezoid<int> fig(std::cin);
			s.push(fig);
		} else if (cmd == "i") {
			std::cout << "enter index\n";
			std::cin >> index;
			auto p = s.begin();
			try {
				s.advance(p, index);
			} catch (std::exception& err) {
				std::cout << err.what() << "\n";
				continue;
			}
			std::cout << "enter coordinates\n";
			TTrapezoid<int> fig(std::cin);
			s.insert(p, fig);
			
		} else if (cmd == "p") {
			try {
				s.pop();
			} catch (std::exception& err) {
				std::cout << err.what() << "\n";
				continue;
			}
		} else if (cmd == "e") {
			std::cout << "enter index\n";
			std::cin >> index;
			auto p = s.begin();
			try {
				s.advance(p, index);
			} catch (std::exception& err) {
				std::cout << err.what() << "\n";
				continue;
			}
			try {
				s.erase(p);
			} catch (std::exception& err) {
				std::cout << err.what() << "\n";
			}
			
			
		} else if (cmd == "t") {
			try {
				s.top();
			} catch (std::exception& err) {
				std::cout << err.what() << "\n";
				continue;
			}
			TTrapezoid<int> figure = s.top();
			figure.Print();

		} else if (cmd == "f") {
			std::for_each(s.begin(), s.end(), [] (TTrapezoid<int> tmp) {return tmp.Print();});
		} else if (cmd == "c") {
			int less;
			std::cout << "enter square\n";
			std::cin >> less;
			std::cout << std::count_if(s.begin(), s.end(), [less](TTrapezoid<int> t ) {return t.Square() < less;}) << "\n";

		} else if (cmd == "ex") {
			break;
		} else {
			std::cout << "wrong comand\n";
			continue;
		}
	}

}
