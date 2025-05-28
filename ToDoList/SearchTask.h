#pragma once
#include "StructTaskList.h"
#include "ShowAllTask.h"
void SearchTask(Task* task, const int size)
{
  int search;
  std::cout << "Possible options to search tasks:" << std::endl;
  std::cout << "1. Name" << std::endl;
  std::cout << "2. Priority" << std::endl;
  std::cout << "3. Description" << std::endl;
  std::cout << "4. Execution date (DD MM YYYY)" << std::endl;
  std::cout << "5. Execution time (HH MM)" << std::endl;
  std::cout << "Search by: ";
  std::cin >> search;
  while (search < 1 || search > 5)
  {
    std::cout << "Please, enter a value from 1 to 5!" << std::endl;
    std::cout << "Search by: ";
    std::cin >> search;
  }
  if (search == 1)
  {
    const int N = 256;
    char searchName[N];
    std::cin.ignore();
    std::cout << "Enter task's name or part of it to search: ";
    std::cin.getline(searchName, N);
    bool found1 = false;
    std::cout << "Searching..." << std::endl;
    Sleep(1000);
    for (int i = 0; i < size; i++)
    {
      if (strstr(task[i].name, searchName))
      {
        std::cout << "- Task #" << i + 1 << ": " << std::endl;
        ShowAllTask(&task[i], size);
        found1 = true;
      }
    }
    if (!found1)
    {
      std::cout << "Task with this name was not found :(" << std::endl;
    }
    std::cout << "Search complited successufully!" << std::endl;
  }
  else if (search == 2)
  {
    int searchPriority;
    std::cout << "Enter task's priority to search: ";
    std::cin >> searchPriority;
    bool found2 = false;
    std::cout << "Searching..." << std::endl;
    Sleep(1000);
    for (int i = 0; i < size; i++)
    {
      if (task[i].priority == searchPriority)
      {
        std::cout << "- Task #" << i + 1 << ": " << std::endl;
        ShowAllTask(&task[i], size);
        found2 = true;
      }
      if (!found2)
      {
        std::cout << "Task with this priority was not found :(" << std::endl;
      }
    }
    std::cout << "Search complited successufully!" << std::endl;
  }
  else if (search == 3)
  {
    const int N = 256;
    char searchDescription[N];
    std::cin.ignore();
    std::cout << "Enter task's description to search: ";
    std::cin.getline(searchDescription, N);
    bool found3 = false;
    std::cout << "Searching..." << std::endl;
    Sleep(1000);
    for (int i = 0; i < size; i++)
    {
      if (strstr(task[i].description, searchDescription))
      {
        std::cout << "- Task #" << i + 1 << ": " << std::endl;
        ShowAllTask(&task[i], size);
        found3 = true;
      }
    }
    if (!found3)
    {
      std::cout << "Task with this description was not found :(" << std::endl;
    }
    std::cout << "Search complited successufully!" << std::endl;
  }
  else if (search == 4)
  {
    int searchDate;
    std::cout << "Enter task's date to search: ";
    std::cin >> searchDate;
    bool found4 = false;
    std::cout << "Searching..." << std::endl;
    Sleep(1000);
    for (int i = 0; i < size; i++)
    {
      if (task[i].date.day == searchDate)
      {
        std::cout << "- Task #" << i + 1 << ": " << std::endl;
        ShowAllTask(&task[i], size);
        found4 = true;
      }
      if (!found4)
      {
        std::cout << "Task with this date was not found :(" << std::endl;
      }
    }
    std::cout << "Search complited successufully!" << std::endl;
  }
  else if (search == 5)
  {
    int searchTime;
    std::cout << "Enter task's time to search: ";
    std::cin >> searchTime;
    bool found5 = false;
    std::cout << "Searching..." << std::endl;
    Sleep(1000);
    for (int i = 0; i < size; i++)
    {
      if (task[i].date.day == searchTime)
      {
        std::cout << "- Task #" << i + 1 << ": " << std::endl;
        ShowAllTask(&task[i], size);
        found5 = true;
      }
      if (!found5)
      {
        std::cout << "Task with this time was not found :(" << std::endl;
      }
    }
    std::cout << "Search complited successufully!" << std::endl;
  }
}
