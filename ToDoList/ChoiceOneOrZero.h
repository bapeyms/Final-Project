#pragma once
#include "StructTaskList.h"
int ChoiceOneOrZero()
{
	int choice;
	std::cout << "Choice: ";
	std::cin >> choice;
	while (choice != 0 && choice != 1)
	{
		std::cout << "Please, enter only 1 or 0!" << std::endl;
		std::cout << "Choice: ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> choice;
	}
	return choice;
}
