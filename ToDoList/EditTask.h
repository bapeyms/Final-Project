#pragma once
#include "StructTaskList.h"
#include "ChoiceOneOrZero.h"
void EditTask(Task* task, int& size)
{
	std::cout << "Are you sure you want to edit the task? (1 - yes, 0 - no)" << std::endl;
	int choice = ChoiceOneOrZero();
	if (choice == 1)
	{
		std::cout << "Showing all available tasks..." << std::endl;
		Sleep(1000);
		std::cout << "--------------------" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << "- Task #" << i + 1 << ": " << std::endl;
			ShowAllTask(&task[i], size);
		}
		std::cout << "--------------------" << std::endl;
		int number;
		std::cout << "Please, select the number of the task you want to edit" << std::endl;
		std::cout << "Number: ";
		std::cin >> number;
		while (number < 0 || number > size)
		{
			std::cout << "Please, enter a value from 0 to " << size - 1 << "!" << std::endl;
			std::cout << "Number: ";
			std::cin >> number;
		}
		int index = number - 1;
		std::cout << "- Task #" << number << ": " << std::endl;
		ShowAllTask(&task[index], size);
		int fieldToChange;
		std::cout << "Please, enter the field you would like to change" << std::endl;
		std::cout << "(1 - name, 2 - priority, 3 - description, 4 - date, 5 - time)" << std::endl;
		std::cout << "Field: ";
		std::cin >> fieldToChange;
		while (fieldToChange < 1 || fieldToChange > 5)
		{
			std::cout << "Please, enter a value from 0 to 5!" << std::endl;
			std::cout << "Value: ";
			std::cin >> fieldToChange;
		}
		if (fieldToChange == 1)
		{
			const int N = 256;
			std::cin.ignore();
			std::cout << "Enter new name for the task: ";
			std::cin.getline(task[index].name, N);
			std::cout << std::endl;
		}
		else if (fieldToChange == 2)
		{
			std::cout << "Enter new priority for the task: ";
			std::cin >> task[index].priority;
			while (task[index].priority != 1 && task[index].priority != 2 && task[index].priority != 3)
			{
				std::cout << "Please, enter only 1 (high), 2 (medium) or 3 (low)!" << std::endl;
				std::cout << "New priority: ";
				std::cin >> task[index].priority;
			}
			std::cout << std::endl;
		}
		else if (fieldToChange == 3)
		{
			const int N = 256;
			std::cout << "Enter new description for the task: ";
			std::cin.ignore();
			std::cin.getline(task[index].description, N);
			std::cout << std::endl;
		}
		else if (fieldToChange == 4)
		{
			int fieldToChangeDate;
			std::cout << "Please, enter the field you would like to change" << std::endl;
			std::cout << "Value: ";
			std::cout << "(6 - date, 7 - month, 8 - year)" << std::endl;
			std::cin >> fieldToChangeDate;
			while (fieldToChangeDate < 6 || fieldToChangeDate > 8)
			{
				std::cout << "Please, enter a value from 6 to 8!" << std::endl;
				std::cout << "Value: ";
				std::cin >> fieldToChangeDate;
			}
			// додати перевірки
			if (fieldToChangeDate == 6)
			{
				std::cout << "Enter new day for the task: ";
				std::cin >> task[index].date.day;
				std::cout << std::endl;
			}
			else if (fieldToChangeDate == 7)
			{
				std::cout << "Enter new month for the task: ";
				std::cin >> task[index].date.month;
				std::cout << std::endl;
			}
			else if (fieldToChangeDate == 8)
			{
				std::cout << "Enter new year for the task: ";
				std::cin >> task[index].date.year;
				std::cout << std::endl;
			}
		}
		else if (fieldToChange == 5)
		{
			int fieldToChangeTime;
			std::cout << "Please, enter the field you would like to change" << std::endl;
			std::cout << "(9 - hours, 10 - minutes)" << std::endl;
			std::cout << "Value: ";
			std::cin >> fieldToChangeTime;
			while (fieldToChangeTime != 9 && fieldToChangeTime != 10)
			{
				std::cout << "Please, enter a value from 6 to 8!" << std::endl;
				std::cout << "Value: ";
				std::cin >> fieldToChangeTime;
			}
			std::cin >> fieldToChangeTime;
			if (fieldToChangeTime == 9)
			{
				std::cout << "Enter new hours for the task: ";
				std::cin >> task[index].time.hours;
				std::cout << std::endl;
			}
			else if (fieldToChangeTime == 10)
			{
				std::cout << "Enter new minutes for the task: ";
				std::cin >> task[index].time.minutes;
			}
		}
		std::cout << "Task was successfully edited!" << std::endl;
	}
	else if (choice == 0)
	{
		std::cout << "Edition cancelled. All tasks remain unchanged" << std::endl;
	}
}
