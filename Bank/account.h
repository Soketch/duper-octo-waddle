#pragma once
#include<iostream>
using namespace std;

class Account
{
	//����һ������洢ÿһ�δ�Ǯ��ȡǮ�Ľ��׼�¼���Ա��ѯ��
public:
	Account(string id, int money, string date);

	void showInfo();
	//
	string m_ID;
	int m_money;

	string m_date;
};