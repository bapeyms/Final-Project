#pragma once
#include "StructTaskList.h"
#include "ShowAllTask.h"
#include "ChoiceOneOrZero.h"
void DeleteTask(Task* task, int& size)
{
	std::cout << "Are you sure you want to delete the task? (1 - yes, 0 - no)" << std::endl;
	int choice = ChoiceOneOrZero();
	if (choice == 1)
	{
		std::cout << "Showing all available tasks..." << std::endl;
		Sleep(1000);
		std::cout << "--------------------" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << "- Task #" << i+1 << ": " << std::endl;
			ShowAllTask(&task[i], size);
		}
		std::cout << "--------------------" << std::endl;
		int number;
		std::cout << "Please, select the number of the task you want to delete" << std::endl;
		std::cout << "Number: ";
		std::cin >> number;
		while (number < 0 || number > size)
		{
			std::cout << "Please, enter a value from 0 to " << size - 1 << "!" << std::endl;
			std::cout << "Number: ";
			std::cin >> number;
		}
		int index = number - 1;
		for (int i = index; i < size - 1; i++)
		{
			task[i] = task[i + 1];
		}
		size--;
		std::cout << "Task #" << number << " successfully deleted!" << std::endl;
	}
	else if (choice == 0)
	{
		std::cout << "Deletion cancelled. All tasks remain unchanged" << std::endl;
	}
}
