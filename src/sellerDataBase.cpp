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
	cout<<"\n ����������: ";
	cin.getline(a,100);
	Skip1:;
	cout<<"\n ����������(6λ����):";
	cin>>password;
	if(cin.fail()==1)
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"\n  �������˴��������,����������!\n\n  ";
		system("Pause");
		system("CLS");
		cout<<"****************************SellerSystem************************"<<"\n"<<"\n";
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
		cout<<"\n �������˴��������!\n\n  ";
		system("Pause");
		system("CLS");
		cout<<"****************************SellerSystem************************"<<"\n"<<"\n";
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
//		cout<<"\n  ��������ȷ�Ľ��\n\n  ";
//		if(account>1000000) cout<<"  ÿ�γ�ֵ����Ϊһ����!\n\n  ";
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
	cout<<"\n  ע��ɹ�,�����˺�Ϊ:"<<Last->showID()<<",���μ�"<<"\n\n  ";
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
			password=1; 
			if(password==current->showPassword())
			{
				return current;
			}
			else
			{
				cout<<"�������,�����µ�¼"<<"\n";
				system("Pause"); 
				return nullptr;
			}
		}
	}
	cout<<"\n û����������˺�,�Ƿ�ע���̼�(Y/N):"; 
	cin>>order;
	if(toupper(order)=='Y') 
	{
		input();
		return Last;
	}
	else 
	{
		cout<<"ϵͳ�˳�!"; 
		return nullptr;
	}
}

void sellerDataBase::FileStore()
{
	fstream fSeller;
	fSeller.open("SellerData.dat",ios::out|ios::binary);
	if(fSeller.fail()) cout<<"�����ļ�ʧ��!";
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
	if(fSeller.fail()) cout<<"���ļ�ʧ��!";
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
