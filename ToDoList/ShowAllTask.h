#include "StructTaskList.h"
void ShowAllTask(Task* task, const int size)
{
	std::cout << "Task: " << task->name << std::endl;
	std::cout << "Description: " << task->description << std::endl;
	std::cout << "Prioriry: " << task->priority << std::endl;
	std::cout << "Execution date: " << task->date.day << "." << task->date.month << "." << task->date.year << std::endl;
	std::cout << "Execution time: " << task->time.hours << ":" << task->time.minutes << std::endl;
}
