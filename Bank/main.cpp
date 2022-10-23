#include<iostream>
#include"bank.h"
#include"Time.h"
#include<typeinfo>
#include<string>
using namespace std;

int main()
{
	Bank b;
	int choice;  //选择功能

	while (true)
	{
		b.showMenu();
		cout << "输入你的选择：";
		cin >> choice; cout << endl;

		switch (choice)
		{
		case 0:
			b.exitSystem();
			break;
		case 1:
			b.Add_Bank();
			break;
		case 2:
			b.show_Bank();
			break;
		case 3:
			b.Mod_Bank();
			break;
		case 4:
			b.Del_Bank();
			break;

		}
	}

	system("pause");
	return 0;
}