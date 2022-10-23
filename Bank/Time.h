#pragma once
#include<iostream>
#include<atltime.h>
#include<string>
using namespace std;

class Times
{
public:
	int year;
	int month;
	int days;
	int hour;
	int minute;
	int second;

	Times();

	string gettime();
};
