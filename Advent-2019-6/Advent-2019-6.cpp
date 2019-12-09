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

int get_orbits(const std::string& planet, std::map<std::string, std::vector<std::string>>& Dict);

int main()
{
	std::string Orbits[11]{ "COM)B","B)C","C)D","D)E","E)F","B)G","G)H","D)I","E)J","J)K","K)L" };
	std::map <std::string, std::vector<std::string>> Dict = {};

	for (const auto& Orbit : Orbits)
	{
		std::vector<std::string> planets;
		splitString(Orbit, planets, ')');

		Dict[planets[0]].push_back(planets[1]);
	}

	std::cout << "The number of orbits is " << get_orbits("COM", Dict);
	return 0;
}

int get_orbits(const std::string& planet, std::map<std::string, std::vector<std::string>>&Dict)
{
	int steps = 0;
	for (int i = 0; i < Dict[planet].size(); i++)
	{
		steps += get_orbits(Dict[planet][i], Dict);
	}

	return Dict[planet].size() +steps;
}

