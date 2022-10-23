#pragma once

#include<iostream>
#include<fstream>  //�ļ���
#include"Time.h"
#include"account.h"

#define FILENAME "bankFile.txt"   //�ļ�
using namespace std;

class Bank
{
	//���Bank��˽�г�Ա�������˺š����ڡ���
public:

	Account** m_Array = NULL;   //����һ������
	int m_Num = 0;    //�˺Ÿ���

	Times t;  //ʱ�������

	//��־�ļ�Ϊ��
	bool m_File;

	Bank();  //����
	
	int get_BankNum();

	//��ʼ������
	void init_Emp();

	void save();

	void showMenu();  //�˵�

	void exitSystem();   //  0--�˳�ϵͳ

	void Add_Bank();  //  1--����

	void show_Bank(); //  2--��ʾ

	void Mod_Bank();   //  3--����/ȡ��

	void Del_Bank();   //  4--ע��

	int IsExist(string id);

	~Bank();

};
