#pragma once
#include "StructTaskList.h"
void AddTask(Task* task)
{
	int sizeData = 0;
	const int N = 256;
	char data[N];

	// назва таски
	std::cin.ignore();
	std::cout << "Task: ";
	std::cin.getline(data, N);
	sizeData = strlen(data) + 1;
	task->name = new char[sizeData];
	strcpy_s(task->name, sizeData, data);
	
	// пріоритет таски
	std::cout << "Prioriry (1 - high, 2 - medium, 3 - low): ";
	std::cin >> task->priority;
	while (task->priority != 1 && task->priority != 2 && task->priority != 3)
	{
		std::cout << "Please, enter only 1 (high), 2 (medium) or 3 (low)!" << std::endl;
		std::cout << "Prioriry: ";
		std::cin >> task->priority;
	}
	std::cin.ignore();

	// опис таски
	std::cout << "Description: ";
	std::cin.getline(data, N);
	sizeData = strlen(data) + 1;
	task->description = new char[sizeData];
	strcpy_s(task->description, sizeData, data);

	// дата виконання таски
	std::cout << "Execution date (DD MM YYYY): ";
	std::cin >> task->date.day >> task->date.month >> task->date.year;
	while (task->date.day < 1 || task->date.day > 31 || task->date.month < 1 || task->date.month > 12
		|| task->date.year < 0)
	{
		if (task->date.day < 1 || task->date.day > 31)
		{
			std::cout << "Please, enter a value from 01 to 31 for the day!" << std::endl;
			std::cout << "Execution date (DD MM YYYY): ";
			std::cin >> task->date.day >> task->date.month >> task->date.year;
		}
		else if (task->date.month < 1 || task->date.month > 12)
		{
			std::cout << "Please, enter a value from 01 to 12 for the month!" << std::endl;
			std::cout << "Execution date (DD MM YYYY): ";
			std::cin >> task->date.day >> task->date.month >> task->date.year;
		}
		else if (task->date.year < 0)
		{
			std::cout << "Please, enter a value greater than 0 for year!" << std::endl;
			std::cout << "Execution date (DD MM YYYY): ";
			std::cin >> task->date.day >> task->date.month >> task->date.year;
		}
	}

	// час виконання таски
	std::cout << "Execution time (HH MM): ";
	std::cin >> task->time.hours >> task->time.minutes;
	while (task->time.hours < 1 || task->time.hours > 24 || task->time.minutes < 1 || task->time.minutes > 60)
	{
		if (task->time.hours < 1 || task->time.hours > 24)
		{
			std::cout << "Please, enter a value from 01 to 24 for the hour!" << std::endl;
			std::cout << "Execution time (HH MM): ";
			std::cin >> task->time.hours >> task->time.minutes;
		}
		else if (task->time.minutes < 1 || task->time.minutes > 60)
		{
			std::cout << "Please, enter a value from 01 to 60 for the minutes!" << std::endl;
			std::cout << "Execution time (HH MM): ";
			std::cin >> task->time.hours >> task->time.minutes;
		}
		else if (task->date.year < 0)
		{
			std::cout << "Please, enter a value greater than 0 for year!" << std::endl;
			std::cout << "Execution date (DD MM YYYY): ";
			std::cin >> task->date.day >> task->date.month >> task->date.year;
		}
	}
}
