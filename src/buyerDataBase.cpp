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
buyerDataBase::buyerDataBase()
{
	Head=new consumer;
	Last=Head;
	Head->next=nullptr;
	FlieLeadIn();
}
//		~buyerDataBase(){
//			this->FileStore();
//		}
int buyerDataBase::showSum()
{
	return Head->returnSum(); 
} 
void buyerDataBase::print()
{
	consumer *current=Head;
	while(current->next!=nullptr)
	{
		current=current->next;
		current->showSelfInfo();
	}
}
consumer* buyerDataBase::input()
{
	consumer *current=Last;
	this->Last=new consumer;
	current->next=Last; 
	char a[100];
	char b[200]; 
	int age;
	int account;
	int password;
	cin.ignore();
	cout<<"\n 请输入姓名:";
	cout<<" "; 
	cin.getline(a,100);
	Skip1:; 
	cout<<"\n 请输入密码(6位数字):"; 
	cin>>password; 
	if(cin.fail()==1)
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"\n 您输入了错误的密码,请重新输入!\n\n  ";
		system("Pause");
		system("CLS");
		cout<<"*******************************BuyerSystem***************************"<<"\n"<<"\n";
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
		cout<<"\n 您输入了错误的年龄!\n\n ";
		system("Pause");
		system("CLS");
		cout<<"*******************************BuyerSystem***************************"<<"\n"<<"\n";
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
//		cout<<"\n 请输入正确的金额\n\n ";
//		if(account>1000000) cout<<" 每次充值上限为一百万!\n\n  ";
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
	Last->setAge(age);
//	Last->setAccount(account);
	Last->setName(a);
	Last->setAddress(b);
	Last->setpassword(password);
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

consumer* buyerDataBase::logIn(int a)
{
	int password,i=0;
	char password1[10];
	stringstream turn;
	char order;
	consumer *current=Head;
	while(current->next!=nullptr)
	{			
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
			if(password==current->showPassword())
			{
				return current;
			}
			else 
			{
				cout<<" 密码错误,请重新登录"<<"\n ";
				system("Pause"); 
				return nullptr;
			}
		}
	}
		cout<<"\n 没有你输入的账号,是否注册买家(Y/N):"; 
		cin>>order;
		if(toupper(order)=='Y')
		{
			input();
			return Last; 
		}
		else
		{
			cout<<"\n "; 
			system("Pause"); 
			return nullptr; 
		}
}

consumer * buyerDataBase::searchBuyer(int a)
{
	consumer *current=Head;
	while(current->next!=nullptr)
	{			
		current=current->next;
		if(current->showID()==a) return current;
	} 
}

void buyerDataBase::FileStore()
{
	fstream fBuyer;
	fBuyer.open("BuyerData.dat",ios::out|ios::binary);
	if(fBuyer.fail()) cout<<"储存文件失败!";
	consumer *current=Head;
	while(current->next!=nullptr){
		current=current->next;
		fBuyer.write((char*)current,sizeof(consumer));
	}
	fBuyer.close();
}
void buyerDataBase::FlieLeadIn()
{
	fstream fBuyer;
	fBuyer.open("BuyerData.dat",ios::in|ios::binary);
	if(fBuyer.fail()) cout<<"打开文件失败!";
	consumer *current=Head;
	while(fBuyer.peek()!=EOF)
	{
		Last=new consumer;
		fBuyer.read((char *)Last,sizeof(consumer));
		current->next=Last;
		current=Last;
	}
	Last->next=nullptr;
	fBuyer.close();
}

