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
		cout<<"  暂无买家信息!\n\n  ";
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
	cout<<"是否对买家信息进行修改?(Y/N):"; 
	cin>>Corder;
	if(toupper(Corder)=='Y')
	{
		cout<<"\n  请输入要修改的买家序号:";
		cin>>order;
		if(!(order>=0&&order<=k-1))
		{
			cout<<"\n  输入了错误的指令!\n\n  ";
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
			cout<<"  1.修 改 ID"<<"\n";
			cout<<"  2.修改姓名"<<"\n";
			cout<<"  3.修改年龄"<<"\n";
			cout<<"  4.修改地址"<<"\n";
			cout<<"  5.修改余额"<<"\n";
			cout<<"  6.清空购买记录"<<"\n"; 
			cout<<"  7.结束"<<"\n\n";
			cout<<"  #请输入指令:"; 
			cin>>order1;
			if(!(order1>=1&&order1<=7))
			{ 	
				cout<<"  请输入正确的指令!"<<"\n";
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
						cout<<"  请输入9位ID,若输入错误可能导致无法登录;\n";
						cout<<"  输入要修改的买家ID:";
						cin>>ID;
						if(!(ID<=999999999&&ID>=100000000)) 
						{
							cout<<"输入了错误的账号!";
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
						cout<<"\n  修改成功!"<<"\n\n  ";
						system("Pause");
						break;
					}
				case 2:
					cout<<"  输入要修改的姓名:";
					cin.ignore();
					cin.getline(temp,200); 
					now->setName(temp);
					cout<<"\n  修改成功!"<<"\n\n  ";
					system("Pause");
					break; 
				case 3:
					Skip1:;
					cout<<"  请输入要修改的年龄:";
					cin>>temp1;
					if(cin.fail()==1)
					{
						cin.clear();
						cin.ignore(10000,'\n');
						cout<<"\n  您输入了错误的年龄,请重新输入!\n";
						goto Skip1;
					}
					now->setAge(temp1);
					cout<<"\n  修改成功!"<<"\n\n  ";
					system("Pause");
					break;
				case 4:
					cout<<"  输入要修改的地址:";
					cin.ignore();
					cin.getline(temp,200); 
					now->setAddress(temp);
					cout<<"\n  修改成功!"<<"\n\n  ";
					system("Pause");
					break;
				case 5:
					Skip2:; 
					cout<<"  请输入要修改的金额:";
					cin>>temp1;
					if(cin.fail()==1)
					{
						cin.clear();
						cin.ignore(10000,'\n');
						cout<<"\n  您输入了错误的金额,请重新输入!\n";
						goto Skip2;
					}
					now->setAccount(temp1);
					cout<<"\n  修改成功!"<<"\n\n  ";
					system("Pause");
					break;
				case 6:
					now->empty();
					cout<<"\n  清空成功!"<<"\n\n  ";
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
		cout<<"  暂无卖家信息!\n\n  ";
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
	cout<<"是否对卖家信息进行修改?(Y/N)"; 
	cin>>Corder;
	if(toupper(Corder)=='Y')
	{
		cout<<"\n  请输入要修改的卖家信息:";
		cin>>order;
		if(!(order>=0&&order<=k-1)) 
		{
			cout<<"\n  输入了错误的指令!\n\n  ";
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
			cout<<"  1.修 改 ID"<<"\n";
			cout<<"  2.修改姓名"<<"\n";
			cout<<"  3.修改年龄"<<"\n";
			cout<<"  4.修改地址"<<"\n";
			cout<<"  5.修改余额"<<"\n";
			cout<<"  6.清空销售信息"<<"\n";
			cout<<"  7.结束"<<"\n\n";
			cout<<"  #请输入指令:"; 
			cin>>order1;
			if(!(order1>=1&&order1<=7)) 
			{ 	
				cout<<"  请输入正确的指令!"<<"\n";
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
					cout<<"  请输入9位ID,若输入错误可能导致无法登录;\n";
					cout<<"  输入要修改的卖家ID:";
					cin>>ID;
					if(!(ID<=999999999&&ID>=100000000)) 
					{
						cout<<"输入了错误的账号!";
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
//修改ID之后所有相关信息都要进行修改;
					break;
					}
				case 2:
					cout<<"  输入要修改的姓名:";
					cin.ignore();
					cin.getline(temp,200); 
					now->setName(temp);
					cout<<"  修改成功!"<<"\n"; 
					break; 
				case 3:
					Skip1:; 
					cout<<"  请输入要修改的年龄:";
					cin>>temp1;
					if(cin.fail()==1)
					{
						cin.clear();
						cin.ignore(10000,'\n');
						cout<<"\n  您输入了错误的年龄,请重新输入!\n";
						goto Skip1;
					}
					now->setAge(temp1);
					cout<<"  修改成功!"<<"\n";
					break;
				case 4:
					cout<<"  输入要修改的地址:";
					cin.ignore();
					cin.getline(temp,200); 
					now->setAddress(temp);
					cout<<"  修改成功!"<<"\n";
					break;
				case 5:
					Skip2:; 
					cout<<"  请输入要修改的金额:";
					cin>>temp1;
					if(cin.fail()==1)
					{
						cin.clear();
						cin.ignore(10000,'\n');
						cout<<"\n  您输入了错误的金额,请重新输入!\n";
						goto Skip2;
					}
					now->setAccount(temp1);
					cout<<"  修改成功!"<<"\n";
					break;
				case 6:
					now->empty();
					cout<<"  清空成功!"<<"\n";
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
	cout<<"  请输入要删除的卖家信息:";
	cin>>order;
	if(cin.fail()==1)
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"\n  您输入了错误的指令,请重新输入!\n";
		goto Skip1;
	}
	seller *temp1;
	seller *temp2;
	temp1=pSkip(Data.Head,order-1);
	temp2=temp1->next; 
	temp1->next=temp2->next;
	delete temp2;
	cout<<"\n  删除成功!\n\n  ";
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
	cout<<"  请输入要删除的买家信息:";
	cin>>order;
	if(cin.fail()==1)
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"\n  您输入了错误的指令,请重新输入!\n";
		goto Skip1;
	} 
	consumer *temp1;
	consumer *temp2;
	temp1=pSkip(Data.Head,order-1);
	temp2=temp1->next;
	temp1->next=temp2->next;
	delete temp2;
	cout<<"\n  删除成功!\n\n  ";
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
	cout<<"  是否要删除商品信息?(Y/N)"; 
	cin>>Corder;
	if(toupper(Corder)!='Y') return;
	else
	{ 
		cout<<"  请输入要删除的节点信息:";
		cin>>order;
		if(!(order>=0&&order<=k-1)) 
		{
			cout<<"  输入了错误的指令!\n  ";
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
