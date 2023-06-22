#include "extras.h"

#include <iostream>
#include <string>
#include <cmath>
namespace soop {
	void clearMemory(double **arr, unsigned short size)
	{
		for (int i = 0; i < size; i++)
			delete arr[i];
	}
	double roundBy(double &val, unsigned short n)
	{
		return val=round(val * pow(10, n))/ pow(10, n);
	}
}
