#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <sstream>
#include "Date.h"
#include "other Function.h"
#include "goods.h"
#include "List.h"
#include "Person.h"
#include "seller.h"
#include "consumer.h"
#include "sellerDataBase.h"
#include "buyerDataBase.h"
#include "pSkip.h"
#include "Administrator.h"

void Administrator::changeConsumer(buyerDataBase& Data,sellerDataBase& Data1)
{
	int order;
	int ID; 
	char Corder='N';
	int k=1,i;
	consumer *current=Data.Head;
	if(current->next==nullptr)
	{
		cout<<"  ���������Ϣ!\n\n  ";
		system("Pause");
		return; 
	} 
	while(current->next!=nullptr)
	{
		current=current->next;
		cout<<k<<".";
		k++;
		current->showSelfInfo();	
	}
	cout<<"--------------------------------------------\n";
	cout<<"�Ƿ�������Ϣ�����޸�?(Y/N):"; 
	cin>>Corder;
	if(toupper(Corder)=='Y')
	{
		cout<<"\n  ������Ҫ�޸ĵ�������:";
		cin>>order;
		if(!(order>=0&&order<=k-1))
		{
			cout<<"\n  �����˴����ָ��!\n\n  ";
			system("Pause");
			return; 
		} 
		consumer *now;
		now=pSkip(Data.Head,order);
		int order1;
		char temp[200];
		int temp1;
		while(true)
		{
			system("CLS");
			cout<<"*******************************Administrator***************************"<<"\n"<<"\n";
			now->showSelfInfo();
			cout<<"--------------------------------------------\n"; 
			cout<<"  1.�� �� ID"<<"\n";
			cout<<"  2.�޸�����"<<"\n";
			cout<<"  3.�޸�����"<<"\n";
			cout<<"  4.�޸ĵ�ַ"<<"\n";
			cout<<"  5.�޸����"<<"\n";
			cout<<"  6.��չ����¼"<<"\n"; 
			cout<<"  7.����"<<"\n\n";
			cout<<"  #������ָ��:"; 
			cin>>order1;
			if(!(order1>=1&&order1<=7))
			{ 	
				cout<<"  ��������ȷ��ָ��!"<<"\n";
				cin.clear();
				cin.ignore(10000,'\n');
				cout<<"  ";
				system("Pause");
				continue;
			}
			switch(order1)
			{
				case 1:
					{
						cout<<"  ������9λID,�����������ܵ����޷���¼;\n";
						cout<<"  ����Ҫ�޸ĵ����ID:";
						cin>>ID;
						if(!(ID<=999999999&&ID>=100000000)) 
						{
							cout<<"�����˴�����˺�!";
							cout<<"   3..";
							Sleep(1000);
							cout<<"\b\b\b2..";
							Sleep(1000);
							cout<<"\b\b\b1..\n";
							return;
						}
						seller *current=Data1.Head;
						while(current->next!=nullptr){
							current=current->next;
							for(i=0;i<1000;i++)
							{
								if(current->SendGoods1[i]==0) break;
								if(current->SendGoods1[i]=now->ID) current->SendGoods1[i]=ID;
							}
						}
						now->ID=ID;
						cout<<"\n  �޸ĳɹ�!"<<"\n\n  ";
						system("Pause");
						break;
					}
				case 2:
					cout<<"  ����Ҫ�޸ĵ�����:";
					cin.ignore();
					cin.getline(temp,200); 
					now->setName(temp);
					cout<<"\n  �޸ĳɹ�!"<<"\n\n  ";
					system("Pause");
					break; 
				case 3:
					Skip1:;
					cout<<"  ������Ҫ�޸ĵ�����:";
					cin>>temp1;
					if(cin.fail()==1)
					{
						cin.clear();
						cin.ignore(10000,'\n');
						cout<<"\n  �������˴��������,����������!\n";
						goto Skip1;
					}
					now->setAge(temp1);
					cout<<"\n  �޸ĳɹ�!"<<"\n\n  ";
					system("Pause");
					break;
				case 4:
					cout<<"  ����Ҫ�޸ĵĵ�ַ:";
					cin.ignore();
					cin.getline(temp,200); 
					now->setAddress(temp);
					cout<<"\n  �޸ĳɹ�!"<<"\n\n  ";
					system("Pause");
					break;
				case 5:
					Skip2:; 
					cout<<"  ������Ҫ�޸ĵĽ��:";
					cin>>temp1;
					if(cin.fail()==1)
					{
						cin.clear();
						cin.ignore(10000,'\n');
						cout<<"\n  �������˴���Ľ��,����������!\n";
						goto Skip2;
					}
					now->setAccount(temp1);
					cout<<"\n  �޸ĳɹ�!"<<"\n\n  ";
					system("Pause");
					break;
				case 6:
					now->empty();
					cout<<"\n  ��ճɹ�!"<<"\n\n  ";
					system("Pause");
					break;
				case 7:
					return;
			}
		}
	}
	else return; 
}
 
void Administrator::changeSeller(sellerDataBase& Data,List& wareList)
{
	int order;
	char Corder='N';
	int k=1;
	seller *current=Data.Head;
	system("CLS");
	if(current->next==nullptr)
	{
		cout<<"  ����������Ϣ!\n\n  ";
		system("Pause");
		return; 
	} 
	while(current->next!=nullptr)
	{
		current=current->next;
		cout<<k<<".";
		k++; 
		current->showSelfInfo();	
	}
	cout<<"--------------------------------------------\n";
	cout<<"�Ƿ��������Ϣ�����޸�?(Y/N)"; 
	cin>>Corder;
	if(toupper(Corder)=='Y')
	{
		cout<<"\n  ������Ҫ�޸ĵ�������Ϣ:";
		cin>>order;
		if(!(order>=0&&order<=k-1)) 
		{
			cout<<"\n  �����˴����ָ��!\n\n  ";
			system("Pause");
			return; 
		}
		seller *now;
		now=pSkip(Data.Head,order);
		int order1;
		char temp[200];
		int temp1;
		while(true)
		{
			system("CLS");
			cout<<"*******************************Administrator***************************"<<"\n"<<"\n";
			now->showSelfInfo();
			cout<<"--------------------------------------------\n";
			cout<<"  1.�� �� ID"<<"\n";
			cout<<"  2.�޸�����"<<"\n";
			cout<<"  3.�޸�����"<<"\n";
			cout<<"  4.�޸ĵ�ַ"<<"\n";
			cout<<"  5.�޸����"<<"\n";
			cout<<"  6.���������Ϣ"<<"\n";
			cout<<"  7.����"<<"\n\n";
			cout<<"  #������ָ��:"; 
			cin>>order1;
			if(!(order1>=1&&order1<=7)) 
			{ 	
				cout<<"  ��������ȷ��ָ��!"<<"\n";
				cin.clear();
				cin.ignore(10000,'\n');
				cout<<"  ";
				system("Pause");
				continue;
			}
			switch(order1)
			{
				case 1:
					{
					cout<<"  ������9λID,�����������ܵ����޷���¼;\n";
					cout<<"  ����Ҫ�޸ĵ�����ID:";
					cin>>ID;
					if(!(ID<=999999999&&ID>=100000000)) 
					{
						cout<<"�����˴�����˺�!";
						Sleep(3000);
						return;
					}
					int Sum=wareList.Head->returnSum();
					int m;
					goods *current=wareList.Head;
					for(m=0;m<Sum;m++)
					{
						if(current->showSellerID()==now->ID)
						{
							current->setSellerID(ID);
						}
						current=current->next;
					}
					now->ID=ID;
//�޸�ID֮�����������Ϣ��Ҫ�����޸�;
					break;
					}
				case 2:
					cout<<"  ����Ҫ�޸ĵ�����:";
					cin.ignore();
					cin.getline(temp,200); 
					now->setName(temp);
					cout<<"  �޸ĳɹ�!"<<"\n"; 
					break; 
				case 3:
					Skip1:; 
					cout<<"  ������Ҫ�޸ĵ�����:";
					cin>>temp1;
					if(cin.fail()==1)
					{
						cin.clear();
						cin.ignore(10000,'\n');
						cout<<"\n  �������˴��������,����������!\n";
						goto Skip1;
					}
					now->setAge(temp1);
					cout<<"  �޸ĳɹ�!"<<"\n";
					break;
				case 4:
					cout<<"  ����Ҫ�޸ĵĵ�ַ:";
					cin.ignore();
					cin.getline(temp,200); 
					now->setAddress(temp);
					cout<<"  �޸ĳɹ�!"<<"\n";
					break;
				case 5:
					Skip2:; 
					cout<<"  ������Ҫ�޸ĵĽ��:";
					cin>>temp1;
					if(cin.fail()==1)
					{
						cin.clear();
						cin.ignore(10000,'\n');
						cout<<"\n  �������˴���Ľ��,����������!\n";
						goto Skip2;
					}
					now->setAccount(temp1);
					cout<<"  �޸ĳɹ�!"<<"\n";
					break;
				case 6:
					now->empty();
					cout<<"  ��ճɹ�!"<<"\n";
					break;
				case 7: 
					return; 
			}
		}
	}
	else return; 
}

void Administrator::deleteSeller(sellerDataBase& Data)
{
	int order;
	int k=1;
	seller *current=Data.Head;
	while(current->next!=nullptr)
	{
		current=current->next;
		cout<<k<<".";
		k++; 
		current->showSelfInfo();	
	}
	cout<<"--------------------------------------------\n"; 
	Skip1:; 
	cout<<"  ������Ҫɾ����������Ϣ:";
	cin>>order;
	if(cin.fail()==1)
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"\n  �������˴����ָ��,����������!\n";
		goto Skip1;
	}
	seller *temp1;
	seller *temp2;
	temp1=pSkip(Data.Head,order-1);
	temp2=temp1->next; 
	temp1->next=temp2->next;
	delete temp2;
	cout<<"\n  ɾ���ɹ�!\n\n  ";
	system("Pause");
} 
void Administrator::deleteConsumer(buyerDataBase& Data)
{
	int order; 
	int k=1;
	consumer *current=Data.Head;
	while(current->next!=nullptr)
	{
		current=current->next;
		cout<<k<<".";
		k++; 
		current->showSelfInfo();	
	}
	cout<<"--------------------------------------------\n"; 
	Skip1:; 
	cout<<"  ������Ҫɾ���������Ϣ:";
	cin>>order;
	if(cin.fail()==1)
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"\n  �������˴����ָ��,����������!\n";
		goto Skip1;
	} 
	consumer *temp1;
	consumer *temp2;
	temp1=pSkip(Data.Head,order-1);
	temp2=temp1->next;
	temp1->next=temp2->next;
	delete temp2;
	cout<<"\n  ɾ���ɹ�!\n\n  ";
	system("Pause");
}

void Administrator::deleteGoods(List&Data)
{
	int order;
	char Corder='N'; 
	int k=1,i;
	int Sum;
	Sum=Data.Head->returnSum();
	goods *current=Data.Head;
	for(i=0;i<Sum;i++)
	{
		cout<<k<<".";
		current->printGoodsInfo();
		current=current->next;
		k++;
	}
	cout<<"--------------------------------------------\n";
	cout<<"  �Ƿ�Ҫɾ����Ʒ��Ϣ?(Y/N)"; 
	cin>>Corder;
	if(toupper(Corder)!='Y') return;
	else
	{ 
		cout<<"  ������Ҫɾ���Ľڵ���Ϣ:";
		cin>>order;
		if(!(order>=0&&order<=k-1)) 
		{
			cout<<"  �����˴����ָ��!\n  ";
			system("Pause");
			return; 
		}
		goods *temp1;
		goods *temp2;
		temp1=pSkip(Data.Head,order-2);
		temp2=temp1->next; 
		temp1->next=temp2->next;
		delete temp2;
	} 
}
