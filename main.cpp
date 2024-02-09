#include<iostream>

void printArray(int arrayTest[], int lenthArray)
{
	std::cout << "Reverse array:" << std::endl;
	for (int index = 0; index < lenthArray; index++)
	{
		std::cout << index + 1 << "element: " << arrayTest[index] << std::endl;
	}
}

void deleteMemoryarray(int arrayTest[])
{
	delete[] arrayTest;
	exit(0);
}

void printError()
{
	std::cout << "Error! Incorrect data array!";
	exit(1);
}

int main()
{
	int number; // размерность массива

	std::cout << "Enter array lenth: ";
	std::cin >> number;

	if (number < 0)
		printError();

	int* arrayTest = new int[number];
	std::cout << "Enter full array:" << std::endl;
	for (int i = 0; i < number; i++)
	{
		std::cout << "Enter " << i + 1 << " element:";
		std::cin >> arrayTest[i];
	}

	if (number == 1)
	{
		printArray(arrayTest, number);
		deleteMemoryarray(arrayTest);
	}
	if (number > 1) {
		for (int j = 0; j < number / 2; j++)
		{
			int bufferElement = arrayTest[j];
			arrayTest[j] = arrayTest[number - 1 - j];
			arrayTest[number - 1 - j] = bufferElement;
		}
		printArray(arrayTest, number);
		deleteMemoryarray(arrayTest);
	}
	/*if (number % 4 == 0 && number != 0)
	{
		for (int j = 0; j < number / 4; j+2)
		{
			int bufferElement1 = arrayTest[j];
			int bufferElement2 = arrayTest[j + 1];
			arrayTest[j] = arrayTest[number - 1 - j];
			arrayTest[j + 1] = arrayTest[number - 2 - j];
			arrayTest[number - 1 - j] = bufferElement1;
			arrayTest[number - 2 - j] = bufferElement2;
		}
		printArray(arrayTest, number);
		deleteMemoryarray(arrayTest);
	}*/
	else
	{
		delete[] arrayTest;
		printError();
	}
}