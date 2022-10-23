#pragma once

#include<iostream>
#include<fstream>  //文件流
#include"Time.h"
#include"account.h"

#define FILENAME "bankFile.txt"   //文件
using namespace std;

class Bank
{
	//设计Bank类私有成员变量：账号、日期、余额。
public:

	Account** m_Array = NULL;   //定义一个数组
	int m_Num = 0;    //账号个数

	Times t;  //时间类对象

	//标志文件为空
	bool m_File;

	Bank();  //构造
	
	int get_BankNum();

	//初始化数组
	void init_Emp();

	void save();

	void showMenu();  //菜单

	void exitSystem();   //  0--退出系统

	void Add_Bank();  //  1--创建

	void show_Bank(); //  2--显示

	void Mod_Bank();   //  3--存入/取出

	void Del_Bank();   //  4--注销

	int IsExist(string id);

	~Bank();

};
