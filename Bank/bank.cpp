#include"bank.h"

Bank::Bank()
{
	//无参构造
	ifstream ifs;
	ifs.open(FILENAME, ios::in);   //  in 读文件
	//文件不存在的情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;   //测试输出
		this->m_Num = 0;   //初始化个数
		this->m_File = true;   //初始化文件为空标志
		this->m_Array = NULL;  //初始化数组
		ifs.close();   //关闭文件
		return;
	}

	//文件存在，但没有数据
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件数据为空" << endl;
		this->m_Num = 0;
		this->m_File = true;
		this->m_Array = NULL;
		ifs.close();
		return;
	}


	//当文件存在，且保存有数据
	int num = this->get_BankNum();
	cout << "当前个数：" << num << endl;
	this->m_Num = num;

	//根据职工数创建数组
	this->m_Array = new Account * [this->m_Num];

	//初始化职工
	init_Emp();
}


//初始化数组
void Bank::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::out);

	string name;
	int money;
	string date;

	int index = 0;   //索引

	while (ifs >> name && ifs >> money && ifs >> date)
	{
		Account* account = NULL;

		account = new Account(name, money, date);

		//存入数组中
		this->m_Array[index] = account;
		index++;
	}
}

void Bank::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);   //打开文件

	for (int i = 0; i < this->m_Num; i++)   //保存每个职工数据
	{
		ofs << this->m_Array[i]->m_ID << "  "
			<< this->m_Array[i]->m_money << "  "
			<< this->m_Array[i]->m_date << endl;
	}
	ofs.close();  //关闭文件
}

//文件存在，且有数据
//统计个数
int Bank::get_BankNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);   //读取数据

	string bank_id;
	int bank_money;
	string bank_date;

	int num = 0;    //人数-计数

	while (ifs >> bank_id && ifs >> bank_money && ifs>>bank_date)
	{
		//记录人数
		num++;
	}
	ifs.close();

	return num;
}

void Bank::showMenu()
{
	cout << "********************************" << endl;
	cout << "*****    0、  退出系统     *****" << endl;
	cout << "*****    1、创建账号(开户) *****" << endl;
	cout << "*****    2、  显示账号     *****" << endl;;
	cout << "*****    3、 存入 / 取出   *****" << endl;
	cout << "*****    4、  注销账号     *****" << endl;
	cout << "********************************" << endl;
}

void Bank::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void Bank::Add_Bank()
{
	/*
	string Add_id;
	int Add_money;
	string Add_date;  //属性

	
	//一次只开一个户
	int newSize = 0;
	newSize= this->m_Num + 1;  //账号 +1

	//开辟新空间
	Account** newSpace = new Account * [newSize];

	//将原空间下内容放到新空间
	if (this->m_Num != NULL)
	{
		for (int i = 0; i < this->m_Num; i++)
		{
			newSpace[i] = this->m_Array[i];
		}
	}
	


	//输入新数据
	Account* account = NULL;

	cout << "输入账号信息：";
	cin >> Add_id;  cout << endl;

	
	Add_money = 10;   //默认金额为0
	Add_date = t.gettime();  //自动获取当前时间

	account = new Account(Add_id, Add_money, Add_date);  //之前搞错误两次

	newSpace[this->m_Num + 1] = account;

	//cout << this->m_Array[this->m_Num]->m_ID << "\t" << this->m_Array[this->m_Num]->m_money << "\t" << this->m_Array[this->m_Num]->m_date << endl;

	//释放原来空间
	delete[] this->m_Array;
	//更新空间指向
	this->m_Array = newSpace;
	//更新空间人数
	this->m_Num = newSize;
	
	
	//提示信息
	cout << "添加成功" << endl;

	//this->save();  //保存数据到文件中

	system("pause");
	system("cls");
	*/
	
	
	cout << "请输入需要开户个数:" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//计算空间大小
		int newSize = this->m_Num + addNum;

		//开辟新空间
		Account** newSpace = new Account * [newSize];

		//将原空间下内容放到新空间
		if (this->m_Num != NULL)
		{
			for (int i = 0; i < this->m_Num; i++)
			{
				newSpace[i] = this->m_Array[i];
			}
		}

		//输入新数据
		for (int j = 0; j < addNum; j++)
		{
			int money;
			string id;
			string date;

			cout << "请输入第" << j + 1 << "个账号" << endl;
			cin >> id;

			//cout << "请输入第" << j + 1 << "个金额" << endl;
			//cin >> money;
			money = 0;
			//cout << "请输入时间" << endl;
			//cin >> date;
			date = t.gettime();

			Account* account = NULL;
			
			account = new Account(id, money, date);
				
			newSpace[this->m_Num + j] = account;
		}

		//释放原来空间
		delete[] this->m_Array;
		//更新空间指向
		this->m_Array = newSpace;
		//更新空间Num
		this->m_Num = newSize;
		//提示信息
		cout << "成功添加" << addNum << "个账号" << endl;

		this->save();  //保存数据到文件中

	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
	

}

void Bank::show_Bank()
{
	if (this->m_File)
	{
		cout << "文件不存在或者记录为空!" << endl;
	}
	else
	{
		for (int i = 0; i < m_Num; i++)
		{
			//利用多态调用接口
			this->m_Array[i]->showInfo();
			//cout << "账号：" << this->m_Array[i]->m_ID << "\t"
			//	<< "余额：" << this->m_Array[i]->m_money << "\t"
			//	<< "创建时间:" << this->m_Array[i]->m_date << endl;
		}
	}

	system("pause");
	system("cls");
}

void Bank::Mod_Bank()
{
	if (this->m_File)
	{
		cout << "文件不存在或者数据为空" << endl;
	}
	else
	{
		string Mod_id;
		cout << "选择你的账户名：";
		cin >> Mod_id;
		int ret = IsExist(Mod_id);
		if (ret != -1)
		{
			//成员存在
			int select = 0;
			while (true)
			{
				cout << "输入需要进行的操作" << endl;
				cout << "  1 -- 存钱" << endl;
				cout << "  2 -- 取钱" << endl;
				cout << "  3 -- 返回" << endl;
				cin >> select;
				if (select == 1)
				{
					//存钱
					int Saving_select;
					cout << "存入金额如下:" << endl;
					cout << "********************************************" << endl;
					cout << "****    1. -- 100元      2. -- 200元    ****" << endl;
					cout << "****    3. -- 500元      4. -- 1000元   ****" << endl;
					cout << "****    5. -- 2000元     6. -- 5000元   ****" << endl;
					cout << "********************************************" << endl;
					cout << "请选择：";   cin >> Saving_select;
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
						cout << "输入错误" << endl;
						break;
					}
					cout << "您已存入余额" << endl;
					system("pause");
					system("cls");
				}
				else if (select == 2)
				{
					if (this->m_Array[ret]->m_money < 100)
					{
						cout << "你的余额不够！" << endl;

					}
					else
					{
						//取钱
						int getM_select;
						cout << "存入金额如下:" << endl;
						cout << "********************************************" << endl;
						cout << "****    1. -- 100元      2. -- 200元    ****" << endl;
						cout << "****    3. -- 500元      4. -- 1000元   ****" << endl;
						cout << "****    5. -- 2000元     6. -- 5000元   ****" << endl;
						cout << "********************************************" << endl;
						cout << "请选择：";   cin >> getM_select;
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
							cout << "输入错误" << endl;
							break;
						}
						cout << "你已取出" << endl;
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
					cout << "输入错误" << endl;
				}

			}

		}
		else
		{
			cout << "未找到该账号!" << endl;
		}
	}

}
void Bank::Del_Bank()
{
	int c_select = 0;
	cout << "是否选择清空：" << endl;
	cout << "  1 --- 是" << endl;
	cout << "  2 --- 否" << endl;
	cout << "输入你的选择：";
	cin >> c_select; cout << endl;

	if (c_select == 1)
	{
		//清空

		//打开模式ios::trunc    如果存在就删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_Array != NULL)
		{
			for (int i = 0; i < this->m_Num; i++)
			{
				if (this->m_Array[i] != NULL)
				{
					delete this->m_Array[i]; //循环清空每一个
					//把每一个在堆区创建的数据释放干净

				}
			}
			this->m_Num = 0;
			delete[] this->m_Array;
			this->m_Array = NULL;
			this->m_File = true;   //文件标志
		}
		cout << "清空完成！" << endl;
	}
	else if (c_select == 2)
	{
		cout << "你选择了 否  --- 不执行清空" << endl;
	}
	system("pause");
	system("cls");
}

int Bank::IsExist(string id)
{
	//判断成员是否存在
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