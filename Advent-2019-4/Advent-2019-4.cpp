// Advent-2019-4.cpp 
// 1360 - 1450

#include <iostream>

bool isPassword(int Pass);

int main()
{
    // 128392-643281
	int NumberOfPasswords = 0;

	std::cout << isPassword(112221);
	
    for (int Pass = 128392; Pass <= 643281; ++Pass)
    {
	    if (isPassword(Pass))
	    {
			NumberOfPasswords++;
	    }
    }

	std::cout << "The number of possible passwords is " << NumberOfPasswords << std::endl;
	return 0;
}

bool isPassword(int Pass)
{
	int numbers[6] = {};
	int count = 0;
	for (int i = 100000; i > 0; i = i / 10)
	{
		numbers[count] = Pass / i;
		Pass = Pass - (numbers[count] * i);
		count++;
	}
	bool Double = false;
	int Dubs = 0;
	int Streak = 0;
	bool InStreak = false;
	for (int i = 1; i < 6; ++i)
	{
		
		if (numbers[i] < numbers[i-1])
		{
			return false;
		}
		
		if (numbers[i] == numbers[i - 1])
		{
			if (!InStreak)
			{
				Dubs++;
				InStreak = true;
				Streak++;
			}
			else
			{
				Dubs = 0;
				Streak++;
			}
		}
		else
		{
			InStreak = false;
			if (Streak == 1)
			{
				Double = true;
			}
			Streak = 0;
		}
	}
	bool value = Dubs > 0;
	
	if (Double)
	{
		value = true;
	}
	return value;
}