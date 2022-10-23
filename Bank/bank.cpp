#include"bank.h"

Bank::Bank()
{
	//�޲ι���
	ifstream ifs;
	ifs.open(FILENAME, ios::in);   //  in ���ļ�
	//�ļ������ڵ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;   //�������
		this->m_Num = 0;   //��ʼ������
		this->m_File = true;   //��ʼ���ļ�Ϊ�ձ�־
		this->m_Array = NULL;  //��ʼ������
		ifs.close();   //�ر��ļ�
		return;
	}

	//�ļ����ڣ���û������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�����Ϊ��" << endl;
		this->m_Num = 0;
		this->m_File = true;
		this->m_Array = NULL;
		ifs.close();
		return;
	}


	//���ļ����ڣ��ұ���������
	int num = this->get_BankNum();
	cout << "��ǰ������" << num << endl;
	this->m_Num = num;

	//����ְ������������
	this->m_Array = new Account * [this->m_Num];

	//��ʼ��ְ��
	init_Emp();
}


//��ʼ������
void Bank::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::out);

	string name;
	int money;
	string date;

	int index = 0;   //����

	while (ifs >> name && ifs >> money && ifs >> date)
	{
		Account* account = NULL;

		account = new Account(name, money, date);

		//����������
		this->m_Array[index] = account;
		index++;
	}
}

void Bank::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);   //���ļ�

	for (int i = 0; i < this->m_Num; i++)   //����ÿ��ְ������
	{
		ofs << this->m_Array[i]->m_ID << "  "
			<< this->m_Array[i]->m_money << "  "
			<< this->m_Array[i]->m_date << endl;
	}
	ofs.close();  //�ر��ļ�
}

//�ļ����ڣ���������
//ͳ�Ƹ���
int Bank::get_BankNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);   //��ȡ����

	string bank_id;
	int bank_money;
	string bank_date;

	int num = 0;    //����-����

	while (ifs >> bank_id && ifs >> bank_money && ifs>>bank_date)
	{
		//��¼����
		num++;
	}
	ifs.close();

	return num;
}

void Bank::showMenu()
{
	cout << "********************************" << endl;
	cout << "*****    0��  �˳�ϵͳ     *****" << endl;
	cout << "*****    1�������˺�(����) *****" << endl;
	cout << "*****    2��  ��ʾ�˺�     *****" << endl;;
	cout << "*****    3�� ���� / ȡ��   *****" << endl;
	cout << "*****    4��  ע���˺�     *****" << endl;
	cout << "********************************" << endl;
}

void Bank::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void Bank::Add_Bank()
{
	/*
	string Add_id;
	int Add_money;
	string Add_date;  //����

	
	//һ��ֻ��һ����
	int newSize = 0;
	newSize= this->m_Num + 1;  //�˺� +1

	//�����¿ռ�
	Account** newSpace = new Account * [newSize];

	//��ԭ�ռ������ݷŵ��¿ռ�
	if (this->m_Num != NULL)
	{
		for (int i = 0; i < this->m_Num; i++)
		{
			newSpace[i] = this->m_Array[i];
		}
	}
	


	//����������
	Account* account = NULL;

	cout << "�����˺���Ϣ��";
	cin >> Add_id;  cout << endl;

	
	Add_money = 10;   //Ĭ�Ͻ��Ϊ0
	Add_date = t.gettime();  //�Զ���ȡ��ǰʱ��

	account = new Account(Add_id, Add_money, Add_date);  //֮ǰ���������

	newSpace[this->m_Num + 1] = account;

	//cout << this->m_Array[this->m_Num]->m_ID << "\t" << this->m_Array[this->m_Num]->m_money << "\t" << this->m_Array[this->m_Num]->m_date << endl;

	//�ͷ�ԭ���ռ�
	delete[] this->m_Array;
	//���¿ռ�ָ��
	this->m_Array = newSpace;
	//���¿ռ�����
	this->m_Num = newSize;
	
	
	//��ʾ��Ϣ
	cout << "��ӳɹ�" << endl;

	//this->save();  //�������ݵ��ļ���

	system("pause");
	system("cls");
	*/
	
	
	cout << "��������Ҫ��������:" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//����ռ��С
		int newSize = this->m_Num + addNum;

		//�����¿ռ�
		Account** newSpace = new Account * [newSize];

		//��ԭ�ռ������ݷŵ��¿ռ�
		if (this->m_Num != NULL)
		{
			for (int i = 0; i < this->m_Num; i++)
			{
				newSpace[i] = this->m_Array[i];
			}
		}

		//����������
		for (int j = 0; j < addNum; j++)
		{
			int money;
			string id;
			string date;

			cout << "�������" << j + 1 << "���˺�" << endl;
			cin >> id;

			//cout << "�������" << j + 1 << "�����" << endl;
			//cin >> money;
			money = 0;
			//cout << "������ʱ��" << endl;
			//cin >> date;
			date = t.gettime();

			Account* account = NULL;
			
			account = new Account(id, money, date);
				
			newSpace[this->m_Num + j] = account;
		}

		//�ͷ�ԭ���ռ�
		delete[] this->m_Array;
		//���¿ռ�ָ��
		this->m_Array = newSpace;
		//���¿ռ�Num
		this->m_Num = newSize;
		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "���˺�" << endl;

		this->save();  //�������ݵ��ļ���

	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
	

}

void Bank::show_Bank()
{
	if (this->m_File)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��!" << endl;
	}
	else
	{
		for (int i = 0; i < m_Num; i++)
		{
			//���ö�̬���ýӿ�
			this->m_Array[i]->showInfo();
			//cout << "�˺ţ�" << this->m_Array[i]->m_ID << "\t"
			//	<< "��" << this->m_Array[i]->m_money << "\t"
			//	<< "����ʱ��:" << this->m_Array[i]->m_date << endl;
		}
	}

	system("pause");
	system("cls");
}

void Bank::Mod_Bank()
{
	if (this->m_File)
	{
		cout << "�ļ������ڻ�������Ϊ��" << endl;
	}
	else
	{
		string Mod_id;
		cout << "ѡ������˻�����";
		cin >> Mod_id;
		int ret = IsExist(Mod_id);
		if (ret != -1)
		{
			//��Ա����
			int select = 0;
			while (true)
			{
				cout << "������Ҫ���еĲ���" << endl;
				cout << "  1 -- ��Ǯ" << endl;
				cout << "  2 -- ȡǮ" << endl;
				cout << "  3 -- ����" << endl;
				cin >> select;
				if (select == 1)
				{
					//��Ǯ
					int Saving_select;
					cout << "����������:" << endl;
					cout << "********************************************" << endl;
					cout << "****    1. -- 100Ԫ      2. -- 200Ԫ    ****" << endl;
					cout << "****    3. -- 500Ԫ      4. -- 1000Ԫ   ****" << endl;
					cout << "****    5. -- 2000Ԫ     6. -- 5000Ԫ   ****" << endl;
					cout << "********************************************" << endl;
					cout << "��ѡ��";   cin >> Saving_select;
					switch (Saving_select)
					{
					case 1:
						this->m_Array[ret]->m_money += 100;
						
						break;
					case 2:
						this->m_Array[ret]->m_money += 200;
						break;
					case 3:
						this->m_Array[ret]->m_money += 500;
						break;
					case 4:
						this->m_Array[ret]->m_money += 1000;
						break;
					case 5:
						this->m_Array[ret]->m_money += 2000;
						break;
					case 6:
						this->m_Array[ret]->m_money += 5000;
						break;
					default:
						cout << "�������" << endl;
						break;
					}
					cout << "���Ѵ������" << endl;
					system("pause");
					system("cls");
				}
				else if (select == 2)
				{
					if (this->m_Array[ret]->m_money < 100)
					{
						cout << "���������" << endl;

					}
					else
					{
						//ȡǮ
						int getM_select;
						cout << "����������:" << endl;
						cout << "********************************************" << endl;
						cout << "****    1. -- 100Ԫ      2. -- 200Ԫ    ****" << endl;
						cout << "****    3. -- 500Ԫ      4. -- 1000Ԫ   ****" << endl;
						cout << "****    5. -- 2000Ԫ     6. -- 5000Ԫ   ****" << endl;
						cout << "********************************************" << endl;
						cout << "��ѡ��";   cin >> getM_select;
						switch (getM_select)
						{
						case 1:
							this->m_Array[ret]->m_money -= 100;
							break;
						case 2:
							this->m_Array[ret]->m_money -= 200;
							break;
						case 3:
							this->m_Array[ret]->m_money -= 500;
							break;
						case 4:
							this->m_Array[ret]->m_money -= 1000;
							break;
						case 5:
							this->m_Array[ret]->m_money -= 2000;
							break;
						case 6:
							this->m_Array[ret]->m_money -= 5000;
							break;
						default:
							cout << "�������" << endl;
							break;
						}
						cout << "����ȡ��" << endl;
						system("pause");
						system("cls");
					}

				}
				
				else if (select == 3)
				{
					system("pause");
					system("cls");
					return;
				}
				else
				{
					cout << "�������" << endl;
				}

			}

		}
		else
		{
			cout << "δ�ҵ����˺�!" << endl;
		}
	}

}
void Bank::Del_Bank()
{
	int c_select = 0;
	cout << "�Ƿ�ѡ����գ�" << endl;
	cout << "  1 --- ��" << endl;
	cout << "  2 --- ��" << endl;
	cout << "�������ѡ��";
	cin >> c_select; cout << endl;

	if (c_select == 1)
	{
		//���

		//��ģʽios::trunc    ������ھ�ɾ���ļ������´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_Array != NULL)
		{
			for (int i = 0; i < this->m_Num; i++)
			{
				if (this->m_Array[i] != NULL)
				{
					delete this->m_Array[i]; //ѭ�����ÿһ��
					//��ÿһ���ڶ��������������ͷŸɾ�

				}
			}
			this->m_Num = 0;
			delete[] this->m_Array;
			this->m_Array = NULL;
			this->m_File = true;   //�ļ���־
		}
		cout << "�����ɣ�" << endl;
	}
	else if (c_select == 2)
	{
		cout << "��ѡ���� ��  --- ��ִ�����" << endl;
	}
	system("pause");
	system("cls");
}

int Bank::IsExist(string id)
{
	//�жϳ�Ա�Ƿ����
	int index = -1;
	for (int i = 0; i < this->m_Num; i++)
	{
		if (this->m_Array[i]->m_ID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

Bank::~Bank()
{
	if (this->m_Array != NULL)
	{
		delete[] this->m_Array;
		this->m_Array = NULL;
	}
}