#pragma once
#include "StructTaskList.h"
#include "ShowAllTask.h"
void SortTask(Task* task, const int size)
{
	int sorting;
	std::cout << "Possible options to sort tasks by:" << std::endl;
	std::cout << "1. Priority" << std::endl;
	std::cout << "2. Execution date" << std::endl;
	std::cout << "3. Execution time" << std::endl;
    std::cout << "Option: ";
	std::cin >> sorting;
	while (sorting < 1 || sorting > 3)
	{
		std::cout << "Please, enter a value from 1 to 3!" << std::endl;
		std::cout << "Option: ";
		std::cin >> sorting;
	}
    std::cout << "Sorting...\n";
    Sleep(1000);

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            bool swap = false;
            if (sorting == 1) 
            {
                if (task[i].priority > task[j].priority)
                {
                    swap = true;
                }
            }
            else if (sorting == 2)
            {
                if (task[i].date.year > task[j].date.year)
                {
                    swap = true;
                }
                else if (task[i].date.year == task[j].date.year)
                {
                    if (task[i].date.month > task[j].date.month)
                    {
                        swap = true;
                    }
                    else if (task[i].date.month == task[j].date.month)
                    {
                        if (task[i].date.day > task[j].date.day)
                        {
                            swap = true;
                        }
                    }
                }
            }
            else if (sorting == 3) 
            {
                if (task[i].time.hours > task[j].time.hours)
                {
                    swap = true;
                }
                else if (task[i].time.hours == task[j].time.hours)
                {
                    if (task[i].time.minutes > task[j].time.minutes)
                    {
                        swap = true;
                    } 
                }
            }
            if (swap)
            {
                Task temp = task[i];
                task[i] = task[j];
                task[j] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << "- Task #" << i + 1 << ": " << std::endl;
        ShowAllTask(&task[i], size);
    }
    std::cout << "Tasks sorted successfully!" << std::endl;
}
