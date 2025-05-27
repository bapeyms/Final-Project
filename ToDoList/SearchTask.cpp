#include <iostream>
#include <cstring>
#include "StructTaskList.h"
using namespace std;
void FillTask(Task *task)
{
  int sizeData = 0;
  const int N = 256;
  char data[N];
  cin.ignore();
  cout << "Task: ";
  cin.getline(data, N);
  sizeData = strlen(data) + 1;
  task->name = new char[sizeData];
  strncpy(task->name, data, sizeData);
}
void FindByName(Task task[], int size, const char *searchName)
{
  bool found = false;
  for (int i = 0; i < size; i++)
  {
    if (strcmp(task[i].name, searchName) == 0)
    {
      cout << "Found by name:" << searchName << endl;
      cout << "Priority: " << task[i].priority << endl;
      cout << "Description: " << task[i].description << endl;
      cout << "Date: " << task[i].date.day << '.' << task[i].date.month << '.' << task[i].date.year << endl;
      found = true;
    }
    if (found != 0)
    {
      cout << "Not found, by this name!" << endl;
    }
  }
}
void FindByPriority(Task task[], int size, int searchProirity)
{
  bool found = false;
  for (int i = 0; i < size; i++)
  {
    if (task[i].priority == searchProirity)
    {
      cout << "Found by Priority: " << searchProirity << endl;
      cout << "Name: " << task[i].name << endl;
      cout << "Description: " << task[i].description << endl;
      cout << "Date: " << task[i].date.day << '.' << task[i].date.month << '.' << task[i].date.year << endl;
      found = true;
    }
    if (found != 0)
    {
      cout << "Not found, by this Priority!" << endl;
    }
  }
}
void FindByDescription(Task task[], int size, const char *searchDescription)
{
  bool found = false;
  for (int i = 0; i < size; i++)
  {
    if (strcmp(task[i].description, searchDescription) == 0)
    {
      cout << "Found by Description: " << searchDescription << endl;
      cout << "Name: " << task[i].name << endl;
      cout << "Priority: " << task[i].priority << endl;
      cout << "Date: " << task[i].date.day << '.' << task[i].date.month << '.' << task[i].date.year << endl;
      found = true;
    }
    if (found != 0)
    {
      cout << "Not found, by this Description!" << endl;
    }
  }
}
void FindByDate(Task task[], int size, Date searchDate)
{
  bool found = false;
  for (int i = 0; i < size; i++)
  {
    if (task[i].date.day == searchDate.day && task[i].date.month == searchDate.month && task[i].date.year == searchDate.year)
    {
      cout << "Found task by Date: " << searchDate.day << '.' << searchDate.month << '.' << searchDate.year << endl;
      cout << "Name: " << task[i].name << endl;
      cout << "Priority: " << task[i].priority << endl;
      cout << "Description: " << task[i].description << endl;
      found = true;
    }
    if (found != 0)
    {
      cout << "Not found, by this Date!" << endl;
    }
  }
}
void FindbyTime(Task task[], Date data, int size, Time searchTime, Date searchDate)
{
  bool found = false;
  for (int i = 0; i < size; i++)
  {
    if (task[i].time.hours == searchTime.hours && task[i].time.minutes == searchTime.minutes)
    {
      cout << "Found by Time!: " << searchTime.hours << ':' << searchTime.minutes;
      cout << "Found task by Date: " << searchDate.day << '.' << searchDate.month << '.' << searchDate.year << endl;
      cout << "Name: " << task[i].name << endl;
      cout << "Priority: " << task[i].priority << endl;
      cout << "Description: " << task[i].description << endl;
      found = true;
    }
    if (found != 0)
    {
      cout << "Not found, by this Date!" << endl;
    }
  }
}

