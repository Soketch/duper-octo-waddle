#include"account.h"

Account::Account(string id, int money, string date)
{
	this->m_date = date;
	this->m_ID = id;
	this->m_money = money;
}

void Account::showInfo()
{
	cout << "�˺�:" << this->m_ID << "\t"
		<< "���:"  << this->m_money << "\t"
		<< "����ʱ��:" << this->m_date << endl;
}