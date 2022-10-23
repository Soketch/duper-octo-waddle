#include"Time.h"

Times::Times()
{
	CTime today = CTime::GetCurrentTime();
	this->year = today.GetYear();
	this->month = today.GetMonth();
	this->days = today.GetDay();
	this->hour = today.GetHour();
	this->minute = today.GetMinute();
	this->second = today.GetSecond();
}

string Times::gettime() {

	//CTime today = CTime::GetCurrentTime();
	//cout << today.GetYear() << "-" << today.GetMonth() << "-" << today.GetDay() << " "
	//	<< today.GetHour() << ":" << today.GetMinute() << ":" << today.GetSecond() << endl;
	//  年月日 时分秒

	//cout << this->year << "-" << this->month << "-" << this->days
	//	<< "." << this->hour << ":" << this->minute << ":" << this->second
	//	<< endl;

	string s = to_string(this->year) + "-" + to_string(this->month) 
		+ "-" + to_string(this->days)+ "." + to_string(this->hour)
		+ ":" + to_string(this->minute) + ":" + to_string(this->second);

	return s;
}