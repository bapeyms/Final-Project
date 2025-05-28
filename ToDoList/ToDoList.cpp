#include <iostream>
#include <windows.h>
#include "StructTaskList.h"
#include "AddTask.h"
#include "DeleteTask.h"
#include "EditTask.h"
#include "ShowAllTask.h"
#include "SearchTask.h"
#include "ShowByDayWeekMonth.h"
#include "SortTask.h"
#include "ChoiceOneOrZero.h"
#include "ChoiceAMenuNumber.h"
#include "ConvertDateToDays.h"
using namespace std;

enum ToDoListMenu
{
	ADD_TASK = 1,
	SHOW_TASK,
	EDIT_TASK,
	DELETE_TASK,
	SEARCH_TASK,
	SHOW_TASKS_BY_DWM,
	SORT,
	EXIT
};


int main()
{
	cout << "-- TO-DO LIST --" << endl;
	// підтверження додавання таски
	cout << "Would you like to add task to the list? Enter 1 for \"yes\" or 0 for \"no\"" << endl;
	int choice1 = ChoiceOneOrZero();
	if (choice1 == 1)
	{
		cout << endl;
		cout << "Starting to add a new task..." << endl;
		Sleep(1000);
	}
	else
	{
		cout << "NO NEW TASK :(";
		return 0;
	}

	// додавання таски
	int size = 0, capacity = 2;
	int choice2;
	Task* tasks = new Task[capacity];
	do
	{
		if (size == capacity)
		{
			capacity *= 2;
			Task* newTask = new Task[capacity];
			for (int i = 0; i < size; i++)
			{
				newTask[i] = tasks[i];
			}
			delete[] tasks;
			tasks = newTask;
		}
		cout << "- New task: " << endl;
		AddTask(&tasks[size]);
		size++;
		cout << "Successfull addition! Would you like to add one more task? (1 - yes, 0 - no)" << endl;
		cout << "Choice: ";
		cin >> choice2;
		while (choice2 != 0 && choice2 != 1)
		{
			cout << "Please, enter only 1 or 0!" << endl;
			cout << "Choice: ";
			cin >> choice2;
		}
	} while (choice2 == 1);
	cout << endl;

	if (choice2 == 0)
	{
		cout << "Great! Access to the menu is being granted...";
		cout << endl << endl;
	}

	while (true)
	{
		Sleep(1000);
		cout << "-- TO-DO LIST MENU --" << endl;
		cout << "1. Add a task" << endl;
		cout << "2. Show all tasks" << endl;
		cout << "3. Edit a task" << endl;
		cout << "4. Delete a task" << endl;
		cout << "5. Search for a task" << endl;
		cout << "6. View tasks by day, week or month" << endl;
		cout << "7. Sort tasks" << endl;
		cout << "8. Exit" << endl << endl;

		int choiceMenu;
		choiceMenu = ChoiceAMenuNumber();

		switch (choiceMenu) {
		case ADD_TASK:
			cout << "- ADDING -" << endl;
			cout << "Adding new task..." << endl;
			Sleep(1000);
			if (size == capacity)
			{
				capacity *= 2;
				Task* newTask = new Task[capacity];
				for (int i = 0; i < size; i++)
				{
					newTask[i] = tasks[i];
				}
				delete[] tasks;
				tasks = newTask;
			}
			cout << "- Task: " << endl;
			AddTask(&tasks[size]);
			size++;
			break;
		case SHOW_TASK:
			cout << "- SHOWING -" << endl;
			cout << "Showing all tasks..." << endl;
			Sleep(1000);
			for (int i = 0; i < size; i++)
			{
				cout << "- Task #" << i + 1 << ": " << endl;
				ShowAllTask(&tasks[i], size);
			}
			break;
		case EDIT_TASK:
			cout << "- EDITING -" << endl;
			EditTask(tasks, size);
			break;
		case DELETE_TASK:
			cout << "- DELETING -" << endl;
			DeleteTask(tasks, size);
			break;
		case SEARCH_TASK:
			cout << "- SEARCHING -" << endl;
			SearchTask(tasks, size);
			break;
		case SHOW_TASKS_BY_DWM:
			cout << "- SHOWING BY -" << endl;
			ShowByDayWeekMonth(tasks, size);
			break;
		case SORT:
			cout << "- SORTING -" << endl;
			SortTask(tasks, size);
			break;
		case EXIT:
			cout << "Exiting..." << endl;
			Sleep(1000);
			return 0;
		default:
			cout << "Invalid value!" << endl;
		}
		cout << endl;
	}
	delete[] tasks;
	return 0;
}
