// Advent-2019-6.cpp : 
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <map>


template <class Container>
void splitString(const std::string& str, Container& cont, char delim = ' ')
{
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delim)) {
		cont.push_back(token);
	}
}

int main()
{
	std::string Orbits[11]{ "COM)B","B)C","C)D","D)E","E)F","B)G","G)H","D)I","E)J","J)K","K)L" };
	std::map < std::string, std::string[10] > Dict = {};

	for (int i =0; i < 11; i++)
	{
		std::vector<std::string> planets;
		splitString(Orbits[i], planets, ')');

		if (Dict[planets[0]]) {
			
		}

		std::cout << planets[0]<< "-" << planets[1] << std::endl;
	}

}
