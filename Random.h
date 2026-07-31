#pragma once
#include <iostream>
#include <ctime>

using namespace std;

namespace Random
{
	int GenerateRandomNumberInRange(int from, int to)
	{
		return rand() % (to - from + 1) + from;
	}
}