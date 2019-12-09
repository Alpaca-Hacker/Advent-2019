// Advent-2019-7.cpp 
//

#include <iostream>
#include <algorithm>    // std::next_permutation, std::sort
#include <vector>

std::vector<int> runCode(int Input[], int setting, int phaseInput, int Ip);
void getArg(const int  instruction[5], int& Arg1, int& Arg2, int& Arg3, int* Input, int Ip);

int main() {
	int Code[] = { 3,26,1001,26,-4,26,3,27,1002,27,2,27,1,27,26,27,4,27,1001,28,-1,28,1005,28,6,99,0,0,5 };
	int inputs[] = { 5,6,7,8,9 };


	std::sort(inputs, inputs + 5);
	int Largest = 0;
	//std::string Settings = "01234";
	do {
		int next = 0;
		int prev = 0;
		int i = 0;
		std::vector<int> machineIp = { 0,0,0,0,0 };
		while (true)
		{
			std::cout << next << "-[" << i << "][" << inputs[i] << "] | ";
			auto Result = runCode(Code, inputs[i], next, machineIp[i]);
			next = Result[0];
			machineIp[i] = Result[1];
			i++;
			if (i == 5)
			{
				i = 0;
			}
			if (next == -99999)
			{
				break;
			}
			prev = next;
		}

		if (prev > Largest)
		{
			Largest = prev;
		}
		std::cout << "[" << inputs[0] << inputs[1] << inputs[2] << inputs[3] << inputs[4] << "] - " << prev << std::endl;
	} while (std::next_permutation(inputs, inputs + 5));

	std::cout << "Largest amount is " << Largest << std::endl;
	return 0;
}

std::vector<int> runCode(int Input[], int setting, int phaseInput, int Ip)
{
	//int Ip = 0;
	int Instruction[5];
	bool useSetting = true;

	while (Input[Ip] != 99)
	{
		int count = 0;
		int Pass = Input[Ip];

		for (int i = 10000; i > 0; i = i / 10)
		{
			Instruction[count] = Pass / i;
			Pass = Pass - (Instruction[count] * i);
			count++;
		}

		int Opcode = Instruction[3] * 10 + Instruction[4];

		int Arg1 = {};
		int Arg2 = {};
		int Arg3 = {};
		getArg(Instruction, Arg1, Arg2, Arg3, Input, Ip);

		switch (Opcode)
		{
		case 1:
		{
			Input[Input[Ip + 3]] = Arg1 + Arg2;
			Ip += 4;
			break;
		}
		case 2:
		{
			Input[Input[Ip + 3]] = Arg1 * Arg2;
			Ip += 4;
			break;
		}
		case 3:
		{
			const auto In = useSetting ? setting : phaseInput;
			useSetting = false;
			Input[Input[Ip + 1]] = In;
			Ip += 2;
			break;
		}

		case 4:
		{
			Ip += 2;
			std::vector<int> ReturnValue = { Arg1, Ip };
			return ReturnValue;
		}
		case 5: // JPNZ
		{
			Ip += 3;

			if (Arg1 != 0)
			{
				Ip = Arg2;
			}
			break;
		}
		case 6: // JPE
		{
			Ip += 3;

			if (Arg1 == 0)
			{
				Ip = Arg2;
			}
			break;
		}

		case 7: // Less than
		{

			Input[Input[Ip + 3]] = 0;

			if (Arg1 < Arg2)
			{
				Input[Input[Ip + 3]] = 1;
			}

			Ip += 4;
			break;
		}

		case 8: // Equals
		{
			Input[Input[Ip + 3]] = 0;

			if (Arg1 == Arg2)
			{
				Input[Input[Ip + 3]] = 1;
			}

			Ip += 4;
			break;
		}

		default:
		{
			std::cout << "Unknown Opcode at " << Ip << " [" << Input[Ip] << "]\n";
			std::vector<int> ReturnValue = { -99999, 0 };
			return ReturnValue;
		}
		}
	}
	std::vector<int> ReturnValue = { -99999, 0 };
	return ReturnValue;
}

void getArg(const int instruction[5], int& Arg1, int& Arg2, int& Arg3, int* Input, int Ip)
{
	if (instruction[2] == 0) {
		Arg1 = Input[Input[Ip + 1]];
	}
	if (instruction[2] == 1) {
		Arg1 = Input[Ip + 1];
	}

	if (instruction[1] == 0) {
		Arg2 = Input[Input[Ip + 2]];
	}
	if (instruction[1] == 1) {
		Arg2 = Input[Ip + 2];
	}

	if (Ip + 3 < sizeof(Input) / sizeof(Input[0])) {
		if (instruction[0] == 0) {
			Arg3 = Input[Input[Ip + 3]];
		}
		if (instruction[0] == 1) {
			Arg2 = Input[Ip + 3];
		}
	}
}
