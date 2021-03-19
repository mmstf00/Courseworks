#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int i, j = 0, temp, p;
    char label;
    int m1[20], m2[20];

label:
    system("cls");
    cout << "Enter amount of elements:"; cin >> p;

    if (p > 20 || p == 0)
    {
        cout << " The number 0 or a number above 20 cannot be entered\n";
        system("pause");
        goto label;
    }

    for (i = 0; i <= p - 1; i++)
    {
        cout << "m1[" << i << "]=";
        cin >> m1[i];
    }

    for (i = p - 1, j = 0; i >= 0; i--, j++)
    {
        m2[j] = m1[i];
    }
    cout << endl << "Reverse ordered array:" << "\n";

    for (i = 0; i < p; i++)
    {
        m1[i] = m2[i];
        cout << "m2[" << i << "]=" << m2[i] << "\n";
    }

    for (i = 0; i < p - 1; i++) {
        for (j = i + 1; j < p; j++) {

            if (m1[i] > m1[j])
            {
                temp = m1[i];
                m1[i] = m1[j];
                m1[j] = temp;

            }
        }
    }

    cout << "\nSorted array:" << endl;

    for (i = 0; i < p; i++) {
        cout << "x[" << i << "]= " << m1[i] << endl;
    }

    system("pause");
}
}