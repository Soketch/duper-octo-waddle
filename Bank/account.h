#pragma once
#include<iostream>
using namespace std;

class Account
{
	//定义一个数组存储每一次存钱、取钱的交易记录，以便查询。
public:
	Account(string id, int money, string date);

	void showInfo();
	//
	string m_ID;
	int m_money;

	string m_date;
};