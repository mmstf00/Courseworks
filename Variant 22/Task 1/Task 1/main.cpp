#include <iostream>

using namespace std;

int main()
{
	int money, bet;
	int numOne = rand() % 10;
	int numTwo = rand() % 10;
	int numThree = rand() % 10;
	char input;

	cout << "Enter amount leva: "; cin >> money;
	cout << endl;
	cout << "Type 'Y' or 'y' to play!" << endl;
	do
	{
		cout << "You have " << money << " leva. Wanna bet? ";
		cin >> input;
		if (input == 'Y' || input == 'y')
		{
			cout << "Enter bet: "; cin >> bet;
			int numOne = rand() % 10;
			int numTwo = rand() % 10;
			int numThree = rand() % 10;
			cout << "[" << numOne << "] " << "[" << numTwo << "] " << "[" << numThree << "]" << endl;
			if (numOne == numTwo && numTwo == numThree && numOne == numThree)
			{
				money += 10 * bet;
				cout << "You won! You have " << money << " leva." << endl;
			}
			else
			{
				money -= bet;
				cout << "You lost! You have " << money << " leva." << endl;
			}
		}
	} while (input == 'Y' || input == 'y' && money >= 0);

	cout << "" << endl;
	cout << "Game Over!!!" << endl;
	cout << "" << endl;

	return 0;
}