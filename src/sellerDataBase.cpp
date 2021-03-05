#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <random>
#include <conio.h>
#include <sstream>

#include "other Function.h"
#include "Date.h"
#include "goods.h"
#include "List.h"
#include "Person.h"
#include "seller.h"
#include "consumer.h"
#include "sellerDataBase.h"
#include "buyerDataBase.h"
#include "pSkip.h"
sellerDataBase::sellerDataBase()
{
	Head=new seller;
	Last=Head;
	Head->next=nullptr;
	FlieLeadIn(); 
}
seller* sellerDataBase::returnSeller(int a)
{
	seller *current=Head;
	while(current->next!=nullptr)
	{
		current=current->next; 
		if(current->showID()==a) return current;	
	}
	return nullptr;
}
int sellerDataBase::showSum()
{
	return Head->returnSum(); 
}
void sellerDataBase::print()
{
	seller *current=Head;
	while(current->next!=nullptr)
	{
		current=current->next;
		current->showSelfInfo();
	}
}

seller* sellerDataBase::input()
{
	seller *current=Last;
	Last=new seller;
	current->next=Last; 
	char a[100];
	char b[200]; 
	int age;
	int account;
	int password;
	cin.ignore();
	cout<<"\n 请输入姓名: ";
	cin.getline(a,100);
	Skip1:;
	cout<<"\n 请输入密码(6位数字):";
	cin>>password;
	if(cin.fail()==1)
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"\n  您输入了错误的密码,请重新输入!\n\n  ";
		system("Pause");
		system("CLS");
		cout<<"****************************SellerSystem************************"<<"\n"<<"\n";
		cout<<"\n 请输入姓名: "<<a<<"\n";
		goto Skip1;
	}
	Skip2:; 
	cout<<"\n 请输入年龄:";
	cin>>age;
	if(!(age>0&&age<=200))
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"\n 您输入了错误的年龄!\n\n  ";
		system("Pause");
		system("CLS");
		cout<<"****************************SellerSystem************************"<<"\n"<<"\n";
		cout<<"\n 请输入姓名: "<<a<<"\n";
		cout<<"\n 请输入密码(6位数字):"<<password<<"\n";
		goto Skip2; 
	}
	cin.ignore();
	cout<<"\n 请输入收货地址:";
	cout<<" "; 
	cin.getline(b,200);
//	Skip3:; 
//	cout<<"\n 请输入账户余额:";
//	cin>>account;
//	if(!(account>0&&account<=1000000)) 
//	{
//		cout<<"\n  请输入正确的金额\n\n  ";
//		if(account>1000000) cout<<"  每次充值上限为一百万!\n\n  ";
//		cin.clear();
//		cin.ignore(10000,'\n');
//		system("Pause");
//		system("CLS");
//		cout<<"\n 请输入姓名: "<<a<<"\n";
//		cout<<"\n 请输入密码(6位数字):"<<password<<"\n";
//		cout<<"\n 请输入年龄:"<<age<<"\n";
//		cout<<"\n 请输入收货地址: "<<b<<"\n";
//		goto Skip3; 
//	}
	Last->setpassword(password);
	Last->setAge(age);
//	Last->setAccount(account);
	Last->setName(a);
	Last->setAddress(b);
	Last->next=nullptr;
	current=Head;
	while(current->next!=Last)
	{
		
		current=current->next;
		if(Last->showID()==current->showID())
		{
			Last->setID(CreateRand(999999999,100000000));
			current=Head;
		}
	}
	cout<<"-------------------------------------";
	cout<<"\n  注册成功,您的账号为:"<<Last->showID()<<",请牢记"<<"\n\n  ";
	system("pause");
	return Last;
	}
seller* sellerDataBase::logIn(int a)
{
	int password,i=0;
	char password1[10];
	stringstream turn;
	char order; 
	seller *current=Head;
	while(current->next!=nullptr){
		current=current->next;
		if(current->showID()==a)
		{
			cout<<"\n 账户存在,请输入密码:";
			for(i=0;i<10;i++)
			{
				password1[i]=getch();
				if(password1[i]=='\r')
				{
					password1[i]='\0';
					break;
				}
				cout<<"*";	
			}
			turn<<password1;
			turn>>password;
			password=1; 
			if(password==current->showPassword())
			{
				return current;
			}
			else
			{
				cout<<"密码错误,请重新登录"<<"\n";
				system("Pause"); 
				return nullptr;
			}
		}
	}
	cout<<"\n 没有你输入的账号,是否注册商家(Y/N):"; 
	cin>>order;
	if(toupper(order)=='Y') 
	{
		input();
		return Last;
	}
	else 
	{
		cout<<"系统退出!"; 
		return nullptr;
	}
}

void sellerDataBase::FileStore()
{
	fstream fSeller;
	fSeller.open("SellerData.dat",ios::out|ios::binary);
	if(fSeller.fail()) cout<<"储存文件失败!";
	seller *current=Head;
	while(current->next!=nullptr)
	{
		current=current->next;
		fSeller.write((char*)current,sizeof(seller));
	}
	fSeller.close();
}

void sellerDataBase::FlieLeadIn()
{
	fstream fSeller;
	fSeller.open("SellerData.dat",ios::in|ios::binary);
	if(fSeller.fail()) cout<<"打开文件失败!";
	seller *current=Head;
	while(fSeller.peek()!=EOF)
	{
		Last=new seller;
		fSeller.read((char *)Last,sizeof(seller));
		current->next=Last;
		current=Last;
	}
	Last->next=nullptr;
	fSeller.close();
}
