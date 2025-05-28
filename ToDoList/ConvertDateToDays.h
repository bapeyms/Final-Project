#pragma once
#include "StructTaskList.h"
int ConvertDateToDays(int d, int m, int y)
{
	return y * 365 + m * 30 + d;
}
