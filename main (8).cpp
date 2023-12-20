#include <iostream>

#include "vector.h"
#include "SIGN.h"

int main() {
	MyVector<SIGN> signs;

	bool run = true;

	while (run) {
		system("cls");
		std::cout << "1. Add SIGN\n";
		std::cout << "2. Delete SIGN\n";
		std::cout << "3. Print SIGN\n";
		std::cout << "4. Exit\n";

		int index = 0;
		std::cout << "Choose index: ";
		std::cin >> index;


		if (index == 1) {
			system("cls");
			SIGN temp;
			std::cin >> temp;
			signs.push_back(temp);
			SIGN::sortByZodiacSign(signs);
			system("pause");
		}
		if (index == 2) {
			system("cls");
			if (signs.size() == 0) {
				std::cout << "Not exist sings\n";
				system("pause");
				continue;
			}
			for (int i = 0; i < signs.size(); ++i) {
				std::cout << "[" << i + 1 << "]\n";
				std::cout << signs[i];
			}

			int elem;
			std::cout << "\nChoose element: ";
			std::cin >> elem;

			while (!(elem >= 1 and elem <= signs.size())) {
				std::cout << "Elem not found (you stupid), enter again: ";
				std::cin >> elem;
			}
			signs.remove(elem - 1);
			SIGN::sortByZodiacSign(signs);
			system("pause");
		}
		if (index == 3) {
			system("cls");
			if (signs.size() == 0) {
				std::cout << "Not exist sings\n";
				system("pause");
				continue;
			}
			for (int i = 0; i < signs.size(); ++i) {
				std::cout << "[" << i + 1 << "]\n";
				std::cout << signs[i];
			}
			system("pause");
		}
		if (index == 4) {
			run = false;
		}
	}

}
