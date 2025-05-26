#pragma once
struct Date
{
	unsigned int day;
	unsigned int month;
	unsigned int year;
};
struct Time
{
	unsigned hours;
	unsigned minutes;
};

struct Task
{
	char* name;
	unsigned int priority;
	char* description;
	Date date;
	Time time;
};
