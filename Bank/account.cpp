#include"account.h"

Account::Account(string id, int money, string date)
{
	this->m_date = date;
	this->m_ID = id;
	this->m_money = money;
}

void Account::showInfo()
{
	cout << "账号:" << this->m_ID << "\t"
		<< "余额:"  << this->m_money << "\t"
		<< "创建时间:" << this->m_date << endl;
}