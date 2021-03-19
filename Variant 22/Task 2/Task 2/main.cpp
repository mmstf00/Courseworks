#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

struct subscribers
{
	char name[15];
	char familia[15];
	char address[20];
	int phoneNumber;
	double payment;
}arr[30], temp[30];

void input();
void nad100leva();
void sortirane();
void load();
void save();
int i = 0;
int br = 0;


int main()
{
	int i;
	do
	{
		cout << "\n        *****MENU*****" << endl;
		cout << "\n 1.Vavejdane na inforfmaciq za abonat" << endl;
		cout << "\n 2.Izvejdane na spravka za abonati,chiyato suma za plashtane e nad 100 leva." << endl;
		cout << "\n 3.Izvejdane na sudurjanieto sortiran vuv vuzhodyasht red po suma na plashtane" << endl;
		cout << "\n 4.Zapisvane vav fail" << endl;
		cout << "\n 5.Izhod" << endl;

		cin >> i;
		if (i > 0 || i < 5)
		{
			switch (i)
			{
			case 1:input(); break;
			case 2:nad100leva(); break;
			case 3:sortirane(); break;
			case 4:save(); break;
			}
		}
		else
			cout << "\n Nevalidna funkciq" << endl;
	} while (i != 5);
}



void input()
{
	cout << "\n Vuvedete broy abonati:";
	cin >> br;
	if (br < 1 || br>30)
		cout << "\n Maksimalniqt broy abonati e 30!" << endl;
	else
		for (i = 0; i < br; i++)
		{
			cout << "\n Ime: ";
			cin >> arr[i].name;
			cout << "\n Familia: ";
			cin >> arr[i].familia;
			cout << "\n Adres: ";
			cin >> arr[i].address;
			cout << "\n Telefonen nomer: ";
			cin >> arr[i].phoneNumber;
			cout << "\n Mesechna suma za plashtane: ";
			cin >> arr[i].payment;
			cout << "-----------------" << endl;
			fflush(stdin);
		}
}

void nad100leva() {
	for (i = 0; i < br; i++)
	{
		if (arr[i].payment >= 100)
		{

			cout << "Ime: " << arr[i].name << endl;
			cout << "Familiq: " << arr[i].familia << endl;
			cout << "Adres: " << arr[i].address << endl;
			cout << "Telefonen nomer: " << arr[i].phoneNumber << endl;
			cout << "Mesechna suma za plashtane: " << arr[i].payment << endl;
			cout << " --------------" << endl;

		}
	}
}

void sortirane()
{

	int i;
	char x = 0;
	int j;
	for (i = 0; i < br - 1; i++)
		for (j = i + 1; j < br; j++)
			if (arr[i].payment > arr[j].payment)
			{
				temp[x] = arr[i];
				arr[i] = arr[j];
				arr[j] = temp[x];
			}

	cout << "\n Vazhodqsht spisak po suma na plashtane:" << endl;
	for (i = 0; i < br; i++)
	{
		cout << "Ime: " << arr[i].name << endl;
		cout << "Familiq: " << arr[i].familia << endl;
		cout << "Adres: " << arr[i].address << endl;
		cout << "Telefonen nomer: " << arr[i].phoneNumber << endl;
		cout << "Mesechna suma za plashtane: " << arr[i].payment << endl;
		cout << " --------------" << endl;
	}

}

void load()
{
	FILE* fp;
	fp = fopen("subscribers.dat", "rb");
	int i;
	if (fp == NULL)
	{
		cout << "\n File not found"; return;;
	}
	for (i = 0; i < br; i++)
		if (fread(&arr[i], sizeof(arr[i]), 1, fp) != 1)
		{
			cout << "\n Error reading subscribers"; exit(1);
		}
	fclose(fp);
}

void save()
{
	FILE* fp;
	fp = fopen("subscribers.dat", "wb");
	int i;
	if (fp == NULL)
	{
		cout << "\n File error"; exit(1);
	}
	for (i = 0; i < br; i++)
		if (fwrite(&arr[i], sizeof(arr[i]), 1, fp) != 1)
		{
			cout << "\n Error writing struct"; exit(1);
		}
	fclose(fp);
}