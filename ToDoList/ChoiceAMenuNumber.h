#pragma once
int ChoiceAMenuNumber()
{
	int choiceMenu;
	std::cout << "Enter the menu number to perform the desired action" << std::endl;
	std::cout << "Choice: ";
	std::cin >> choiceMenu;
	while (choiceMenu < 1 || choiceMenu > 8)
	{
		std::cout << "Please, enter a value from 1 to 7!" << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Choice: ";
		std::cin >> choiceMenu;
	}
	return choiceMenu;
}
