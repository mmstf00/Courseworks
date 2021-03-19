#include <iostream>
#include <algorithm>
using namespace std;

//Извежда най-често срещаната цифра, като параметри взима масива от числа и размера на масива.
void most_occurred_number(int nums[], int size)
{
	int max_count = 0;
	cout << "\nMost occurred number: ";
	for (int i = 0; i < size; i++)
	{
		int count = 1;
		// В цикъл с параметър се проверява дали първото число е равно на следващото, ако е увеличава броя с 1.
		for (int j = i + 1; j < size; j++)
			if (nums[i] == nums[j])
				count++;
		if (count > max_count)
			max_count = count;
	}

	// В цикъл с параметър се извежда резултата.
	for (int i = 0; i < size; i++)
	{
		int count = 1;
		for (int j = i + 1; j < size; j++)
			if (nums[i] == nums[j])
				count++;
		if (count == max_count)
			cout << nums[i] << endl;
	}
	cout << endl;
}

// Алгоритъм за сортиране на масив.
void twoWaySort(int arr[], int n)
{
	// Превръща всички нечетни числа в отрищателни.
	for (int i = 0; i < n; i++)
		if (arr[i] & 1) // Проверка за нечетно число.
			arr[i] *= -1;

	// Функция за сортиране. 
	sort(arr, arr + n);

	// Преобръща масива в предишния(оригиналния) си вид.
	for (int i = 0; i < n; i++)
		if (arr[i] & 1)
			arr[i] *= -1;
}

int main() {
	system("chcp 1251");
	char choise, choise1;
	int numbers[30];
	int numbers1[30];
	int numbers2[30];
	int i, N;

	do
	{

		cout << "                 MENU" << endl;
		cout << " 1 - Enter three-digit numbers from keyboard:" << endl;
		cout << " 2 - Generate three-digit random numbers:" << endl;
		cout << " 0 - To end the program." << endl;
		cout << "Enter choise: "; cin >> choise;
		switch (choise)
		{
		case'1':
			cout << "Enter amount numbers:"; cin >> N; // Задава се брой числа/
			for (i = 1; i <= N; i++)
			{
				cout << "[" << i << "]: "; cin >> numbers[i]; // Въвеждат се числата в масива.
			}
			do
			{
				cout << " 1 - Display the most frequent number." << endl;
				cout << " 2 - Odd and after even numbers in a new array." << endl;
				cout << " 3 - Sort in ascending order." << endl;
				cout << " 0 - To go back." << endl;
				cout << "Enter choise: "; cin >> choise1;
				switch (choise1)
				{
				case'1':
					most_occurred_number(numbers, N); // Извиква горната функция и извежда най-често срещанара цифра.
					break;

				case'2':
					for (i = 1; i <= N; i++)
					{
						numbers1[i] = numbers[i]; // Запазва в друг масив същите числа.
					}
					twoWaySort(numbers1, N); // Извиква горната ф-я и извежда нечетните, а после четните,като параветър се задава масива и броя числа.

					cout << "Unsorted array: " << endl;
					for (i = 1; i <= N; i++)
					{
						cout << "[" << i << "]: " << numbers[i] << endl; // Извежда оригиналия масив.
					}

					cout << "Sorted from odd to even array: " << endl;
					for (i = 1; i <= N; i++)
					{
						cout << "[" << i << "]: " << numbers1[i] << endl; // Извежда сортирания масив.
					}
					break;

				case'3':
					for (i = 1; i <= N; i++)
					{
						numbers2[i] = numbers[i]; // В друг масив пак запазща същите числа от оригиналят за сортиране.
					}

					sort(numbers2, numbers2 + N); // Тук е sort e функция на Visial Studio няма нужда да се дефинира горе, направо се извиква.

					cout << "Unsorted array: " << endl;
					for (i = 1; i <= N; i++)
					{
						cout << "[" << i << "]: " << numbers[i] << endl; // Показва се оригиналния масив.
					}

					cout << "Sorted array: " << endl;
					for (i = 1; i <= N; i++)
					{
						cout << "[" << i << "]: " << numbers2[i] << endl; // Показва се сортирания масив.
					}

					break;

				}
			} while (choise1 != '0');
			break;

			// Долу пак се правят същите неща, но само там се генерират произволни числа.
		case'2':
			cout << "Enter amount numbers to generate:"; cin >> N;
			for (i = 1; i <= N; i++)
			{
				numbers[i] = rand() % 899 + 100;
			}
			for (i = 1; i <= N; i++)
			{
				cout << "[" << i << "]: " << numbers[i] << endl;
			}

			do
			{
				cout << " 1 - Display the most common number." << endl;
				cout << " 2 - Odd and after even numbers in a new array." << endl;
				cout << " 3 - Sort in ascending order." << endl;
				cout << " 0 - To go back." << endl;
				cout << "Enter choise: "; cin >> choise1;
				switch (choise1)
				{
				case'1':
					most_occurred_number(numbers, N); // Извежда най-често срещанара цифра.
					break;
				case'2':
					for (i = 1; i <= N; i++)
					{
						numbers1[i] = numbers[i];
					}
					twoWaySort(numbers1, N); // Сортира от масива

					cout << "Unsorted array: " << endl;
					for (i = 1; i <= N; i++)
					{
						cout << "[" << i << "]: " << numbers[i] << endl;
					}

					cout << "Sorted from odd to even array: " << endl;
					for (i = 1; i <= N; i++)
					{
						cout << "[" << i << "]: " << numbers1[i] << endl;
					}
					break;
				case'3':
					for (i = 1; i <= N; i++)
					{
						numbers2[i] = numbers[i];
					}

					sort(numbers2, numbers2 + N);

					cout << "Unsorted array: " << endl;
					for (i = 1; i <= N; i++)
					{
						cout << "[" << i << "]: " << numbers[i] << endl;
					}

					cout << "Sorted array: " << endl;
					for (i = 1; i <= N; i++)
					{
						cout << "[" << i << "]: " << numbers2[i] << endl;
					}
					break;
				}
			} while (choise1 != '0');

			break;
		}
	} while (choise != '0');
}