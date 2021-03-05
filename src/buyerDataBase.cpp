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
	cout<<"\n ����������:";
	cout<<" "; 
	cin.getline(a,100);
	Skip1:; 
	cout<<"\n ����������(6λ����):"; 
	cin>>password; 
	if(cin.fail()==1)
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"\n �������˴��������,����������!\n\n  ";
		system("Pause");
		system("CLS");
		cout<<"*******************************BuyerSystem***************************"<<"\n"<<"\n";
		cout<<"\n ����������: "<<a<<"\n";
		goto Skip1;
	}
	Skip2:; 
	cout<<"\n ����������:";
	cin>>age;
	if(!(age>0&&age<=200))
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"\n �������˴��������!\n\n ";
		system("Pause");
		system("CLS");
		cout<<"*******************************BuyerSystem***************************"<<"\n"<<"\n";
		cout<<"\n ����������: "<<a<<"\n";
		cout<<"\n ����������(6λ����):"<<password<<"\n"; 
		goto Skip2; 
	}
	cin.ignore();
	cout<<"\n �������ջ���ַ:";
	cout<<" "; 
	cin.getline(b,200);
//	Skip3:;
//	cout<<"\n �������˻����:";
//	cin>>account;
//	if(!(account>0&&account<=1000000)) 
//	{
//		cout<<"\n ��������ȷ�Ľ��\n\n ";
//		if(account>1000000) cout<<" ÿ�γ�ֵ����Ϊһ����!\n\n  ";
//		cin.clear();
//		cin.ignore(10000,'\n');
//		system("Pause");
//		system("CLS");
//		cout<<"\n ����������: "<<a<<"\n";
//		cout<<"\n ����������(6λ����):"<<password<<"\n";
//		cout<<"\n ����������:"<<age<<"\n";
//		cout<<"\n �������ջ���ַ: "<<b<<"\n";
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
	cout<<"\n  ע��ɹ�,�����˺�Ϊ:"<<Last->showID()<<",���μ�"<<"\n\n  ";
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
			cout<<"\n �˻�����,����������:";
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
				cout<<" �������,�����µ�¼"<<"\n ";
				system("Pause"); 
				return nullptr;
			}
		}
	}
		cout<<"\n û����������˺�,�Ƿ�ע�����(Y/N):"; 
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
	if(fBuyer.fail()) cout<<"�����ļ�ʧ��!";
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
	if(fBuyer.fail()) cout<<"���ļ�ʧ��!";
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

