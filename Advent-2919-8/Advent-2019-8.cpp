// Advent-2919-8.cpp 
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main()
{

	std::ifstream file("Input.txt");
	std::string input{};

	std::vector<std::string> Layers;
	std::vector<int> count0;
	std::vector<int> count1;
	std::vector<int> count2;

	std::getline(file, input);
	for (int i = 0; i < input.size(); i += 150)
	{
		Layers.push_back(input.substr(i, 150));
	}

	for (std::string Layer : Layers)
	{
		int layerCount[3] = { 0,0,0 };
		for (int i =0; i < 150; i++)
		{
			switch (Layer[i])
			{
			case '0':
				{
				layerCount[0] ++;
				break;
				}
			case '1':
			{
				layerCount[1] ++;
				break;
			}
			case '2':
			{
				layerCount[2] ++;
				break;
			}
			default: ;
			}
		}
		count0.push_back(layerCount[0]);
		count1.push_back(layerCount[1]);
		count2.push_back(layerCount[2]);
	}
	for (int line = 0; line < 6; line++)
	{
		for (int col = 0; col < 25; col++)
		{
			for (int i = 0; i < 100; ++i)
			{
				if (Layers[i][(25 * line) + col] == '0')
				{
					std::cout << " ";
					break;
				}
				if (Layers[i][(25 * line) + col] == '1')
				{
					std::cout << (char)178u;
					break;
				}
			}
		}
		std::cout << std::endl;
	}
	return 0;


}

