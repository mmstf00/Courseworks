#include <iostream>
#include <algorithm>
using namespace std;

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

int largest(int arr[], int n)
{
	int i;

	// Initialize maximum element 
	int max = arr[0];

	// Traverse array elements  
	// from second and compare 
	// every element with current max  
	for (i = 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];

	return max;
}


int main() {

	char choise, choise1;
	int numbers[25]; // Масив с факултетни номера.
	int numbers1[25]; // Масив с нечетните номера.
	int numbers2[25]; // Сортиран масив във възходящ ред.
	int i,
		N; // Брой студентиç

	do
	{

		cout << "                 MENU" << endl;
		cout << " 1 - Enter the faculty numbers;" << endl;
		cout << " 0 - To end the program." << endl;
		cout << "Enter choise: "; cin >> choise;
		switch (choise)
		{
		case'1':
			cout << "Enter amount faculty numbers:"; cin >> N;
			for (i = 0; i < N; i++)
			{
				cout << "FN [" << i << "]: "; cin >> numbers[i];
			}
			do
			{
				cout << " 1 - Create new array with only odd faculty numbers and determination of the maximum faculty number;" << endl;
				cout << " 2 - Create new array and sort in ascending order;" << endl;
				cout << " 0 - To go back." << endl;
				cout << "Enter choise: "; cin >> choise1;
				switch (choise1)
				{
				case'1':

					for (i = 0; i < N; i++)
					{
						numbers1[i] = numbers[i];
					}

					for (i = 0; i < N; i++)
					{
						if (numbers1[i] % 2 == 1) {
							cout << numbers1[i] << endl;
						}
						else if (numbers1[i] % 2 == 0)
						{
							continue;
						}
						else
						{
							cout << "Odd faculty numbers doesn't exist!" << endl;
						}
					}

					largest(numbers1, N);
					cout << "The maximum faculty number is: " << largest(numbers1, N) << endl;
					break;
				case'2':
					for (i = 0; i < N; i++)
					{
						numbers2[i] = numbers[i];
					}

					sort(numbers2, numbers2 + N);

					cout << "Sorted array: " << endl;
					for (i = 0; i < N; i++)
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