#pragma once
#include "StructTaskList.h"
#include "ConvertDateToDays.h"
#include "ChoiceOneOrZero.h"
void ShowByDayWeekMonth(Task* task, const int size)
{
  int view;
  std::cout << "Possible options to view tasks:" << std::endl;
  std::cout << "1. Day" << std::endl;
  std::cout << "2. Week" << std::endl;
  std::cout << "3. Month" << std::endl;
  std::cout << "View tasks by: ";
  std::cin >> view;
  while (view < 1 || view > 3)
  {
    std::cout << "Please, enter a value from 1 to 3!" << std::endl;
    std::cout << "View tasks by: ";
    std::cin >> view;
  }
  if (view == 1)
  {
    int d, m, y;
    bool found = false;
    std::cout << "Please, enter the date you want to view tasks for (DD MM YYYY)" << std::endl;
    std::cout << "Date: ";
    std::cin >> d >> m >> y;
    std::cout << "Tasks on: " << d << "." << m << "." << y << std::endl;
    std::cout << "Showing..." << std::endl;
    Sleep(1000);
    for (int i = 0; i < size; i++)
    {
      if (task[i].date.day == d && task[i].date.month == m && task[i].date.year == y)
      {
        std::cout << "- Task #" << i + 1 << ": " << std::endl;
        ShowAllTask(&task[i], size);
        found = true;
      }
    }
    if (!found)
    {
      std::cout << "No tasks found for this day" << std::endl;
    }
  }
  else if (view == 2)
  {
    int d, m, y;
    bool found = false;
    std::cout << "Please, enter the date you want to view tasks for the week from (DD MM YYYY)" << std::endl;
    std::cout << "Date: ";
    std::cin >> d >> m >> y;
    int dateToDays = ConvertDateToDays(d, m, y);
    std::cout << "Showing..." << std::endl;
    Sleep(1000);
    for (int i = 0; i < size; i++)
    {
      int tasksForWeek = ConvertDateToDays(task[i].date.day, task[i].date.month, task[i].date.year);
      int diff = tasksForWeek - dateToDays;
      if (diff >= 0 && diff < 7)
      {
        std::cout << "- Task #" << i + 1 << ": " << std::endl;
        ShowAllTask(&task[i], size);
        found = true;
      }
    }
    if (!found)
    {
      std::cout << "No tasks found for this week" << std::endl;
    }
  }
  else if (view == 3)
  {
    int d, m, y;
    bool found = false;
    std::cout << "Please, enter the date you want to view tasks for the month from (DD MM YYYY)" << std::endl;
    std::cout << "Date: ";
    std::cin >> d >> m >> y;
    int dateToDays = ConvertDateToDays(d, m, y);
    std::cout << "Showing..." << std::endl;

    for (int i = 0; i < size; i++)
    {
      int tasksForMonth = ConvertDateToDays(task[i].date.day, task[i].date.month, task[i].date.year);
      int diff = tasksForMonth - dateToDays;
      if (diff >= 0 && diff < 31)
      {
        std::cout << "- Task #" << i + 1 << ": " << std::endl;
        ShowAllTask(&task[i], size);
        found = true;
      }
    }
    if (!found)
    {
      std::cout << "No tasks found for this month" << std::endl;
    }
  }
}
