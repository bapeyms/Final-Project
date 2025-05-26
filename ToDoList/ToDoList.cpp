#include <iostream>
#include <windows.h>
#include "StructTaskList.h"
#include "AddTask.h"
using namespace std;

enum ToDoListMenu
{
	ADD_TASK = 1,
	EDIT_TASK,
	DELETE_TASK,
	SEARCH_TASK,
	SHOW_TASKS,
	EXIT
};


int main()
{
	cout << "-- TO-DO LIST --" << endl;
	// підтверження додавання таски
	int choice1; 
	cout << "Would you like to add task to the list? Enter 1 for \"yes\" or 0 for \"no\"" << endl;
	cout << "Choice: ";
	cin >> choice1;
	while (choice1 != 0 && choice1 != 1)
	{
		cout << "Please, enter only 1 or 0!" << endl;
		cout << "Choice: ";
		cin >> choice1;
	}
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
		cout << "- New task #" << size + 1 << ": " << endl;
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
	cout << endl << endl;

	cout << "- TO-DO LIST MENU -" << endl;
	cout << "1. Add a task" << endl;
	cout << "2. Edit a task" << endl;
	cout << "3. Delete a task" << endl;
	cout << "4. Search for a task" << endl;
	cout << "5. View tasks" << endl;
	cout << "6. Exit" << endl;
	
	delete[] tasks;
	return 0;
}
