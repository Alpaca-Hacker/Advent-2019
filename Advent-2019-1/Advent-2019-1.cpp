// Advent-2019-1.cpp

#include <iostream>
#include <fstream>
#include <string>

int calculateFuel(int weight);


int main()
{
	std::ifstream file("Input.txt");
	std::string input{};

	int fuelRequired = 0;
	
	while (std::getline(file, input)) {
		int total = 0;
		int weight = std::stoi(input);
		total += calculateFuel(weight);

		int fuelAmount = total;
		std::cout << fuelAmount << std::endl;

		while (fuelAmount > 0)
		{
			fuelAmount = calculateFuel(fuelAmount);
			std::cout << fuelAmount << " - " << total << std::endl;
			if (fuelAmount > 0)
			{
				total += fuelAmount;
			}
		}
		fuelRequired += total;
	}
	

	std::cout << "The elves need " << fuelRequired << " units of fuel!\n";
}

int calculateFuel(int weight)
{
	int fuelNeeded = (weight / 3) - 2;

	return fuelNeeded;

	//5038444
}
