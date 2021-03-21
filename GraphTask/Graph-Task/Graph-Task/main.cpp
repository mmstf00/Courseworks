#include <iomanip>
#include <iostream>
#include <queue>
using namespace std;

void ZeroGraph(int city, int G[50][50])
{
	int i, j;

	for (i = 1; i <= city; i++)
	{
		for (j = 1; j <= city; j++) {
			G[i][j] = 0;
		}
	}
}

void makeGraph(int road, int G[50][50])
{
	int i, startingPoint, endPoint;
	cout << "----------------------" << endl;
	for (i = 1; i <= road; i++)
	{
		cout << "Enter starting point: "; cin >> startingPoint;
		cout << "Enter end point: "; cin >> endPoint;
		G[startingPoint][endPoint] = 1;
		//G[endPoint][startingPoint] = 1; !!!
		cout << "----------------------" << endl;
	}
}

void displayGraph(int city, int G[50][50])
{
	int i, j;
	cout << "\n               MATRIX \n" << endl;;
	cout << "    ";

	for (i = 1; i <= city; i++) cout << setw(3) << i;
	cout << endl;

	for (i = 1; i <= city; i++)
	{
		cout << setw(4) << i;
		for (j = 1; j <= city; j++) {
			cout << setw(3) << G[i][j];
		}
		cout << endl;
	}
}

//Проверка дали има път между два града.
bool isRoute(int G[50][50], int from, int to, int city) {
	bool route = false;

	bool visited[50] = { false };

	queue<int> verticies;

	//      ???
	if (from == to) {
		cout << "The starting statement = capial" << endl;
		return true;
	}

	visited[from] = true;
	verticies.push(from);

	//cout << "Testing if there is a route from " << from << " To " << to << endl;
	while (!verticies.empty() && route == false) {
		int current;
		current = verticies.front();
		verticies.pop();
		//cout << "Going into for Loop, with a current value of " << current << endl;
		for (int i = 1; i <= city; i++) {
			if (G[current][i] != NULL)
			{
				if (i == to) {
					route = true;
					break;
				}
				if (visited[i] == false && G[current][i] != 0) {
					visited[i] = true;
					verticies.push(i);
				}
			}
		}
	}
	return route;
}

//Намиране на Градовете, от които не може да се достигне до Столицата. 
void Capital(int G[50][50], int capital, int city) {

	for (int i = 1; i <= city; i++)
	{
		bool answer = isRoute(G, i, capital, city);
		if (!answer) {
			cout << "There is no road to capital from city: " << i << endl;
		}
	}

}

int main()
{
	int city; // Брой върхове - 10.
	int road; // Брой ребра - 16.
	int G[50][50];
	int capital; // Столица.


	cout << "Number of cities: "; cin >> city;
	cout << "Number of lines: "; cin >> road;


	ZeroGraph(city, G); // Занулява матрицата на съседство.
	makeGraph(road, G); // Запълва матрицата на съседство.
	displayGraph(city, G); // Отпечатва матрицата на съседство.

	cout << "Enter Capital: "; cin >> capital;
	Capital(G, capital, city); // Намира Градовете, от които не може да се достигне до Столицата.

	system("pause");

}
