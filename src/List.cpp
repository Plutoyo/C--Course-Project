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
List::List()
{
	Head=nullptr; 
	Last=Head;
	FlieLeadIn();
}

int List::returnSum()
{
	return Head->returnSum(); 
}
// �ϼ��贫�����ҵ�ID,������list������֮�� 
goods* List::input(int sellerID)
{
	goods *current;
	if(Head==nullptr)
	{
		Head=new goods;
		Last=Head;
		Head->next=Last;
		current=Last;
	}
	else
	{
		current=Last;
		Last=new goods;
		current->next=Last;
	}
	char a[100];
	char b[200]; 
	int price;
	char order='N';
	int amount;
	cin.ignore(); 
	cout<<"\n  ��������Ʒ����:";
	cin.getline(a,100);
	Skip1:; 
	cout<<"\n  ��������Ʒ�۸�:";
	cin>>price;
	if(cin.fail()==1)
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"\n  �������˴���ļ۸�,����������!\n\n  ";
		system("Pause");
		system("CLS");
		cout<<"****************************SellerSystem************************"<<"\n"<<"\n";
		cout<<"\n  ��������Ʒ����:"<<a<<"\n";
		goto Skip1; 
	}
	Skip2:;
	cout<<"\n  ��������Ʒ����:";
	cin>>amount;
	if(cin.fail()==1)
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"\n  �������˴��������,����������!\n\n  ";
		system("Pause");
		system("CLS");
		cout<<"****************************SellerSystem************************"<<"\n"<<"\n";
		cout<<"\n  ��������Ʒ����:"<<a<<"\n";
		cout<<"\n  ��������Ʒ�۸�:"<<price<<"\n";
		goto Skip2; 
	}
	cin.ignore();
	cout<<"\n  ���������Ʒ�Ľ���:";
	cin.getline(b,200);
	Last->setSellerID(sellerID);
	Last->setPrice(price);
	Last->setAmount(amount);
	Last->setGoodsName(a);
	Last->setIntroduction(b);
	cout<<"\n  �ϼܳɹ�,�Ƿ�����ϼ�?(Y/N)";
	cin>>order;
	while(toupper(order)=='Y')
	{
		system("CLS");
		cout<<"****************************SellerSystem************************"<<"\n"<<"\n";
		current=Last;
		Last=new goods;
		current->next=Last;
		cin.ignore();
		cout<<"\n  ��������Ʒ����:";
		cin.getline(a,100);
		Skip3:;
		cout<<"\n  ��������Ʒ�۸�:";
		cin>>price;
		if(cin.fail()==1)
		{
			cin.clear();
			cin.ignore(10000,'\n');
			cout<<"\n  �������˴���ļ۸�,����������!\n\n  ";
			system("Pause");
			system("CLS");
			cout<<"****************************SellerSystem************************"<<"\n"<<"\n";
			cout<<"\n  ��������Ʒ����:"<<a<<"\n";
			goto Skip3;
		}
		//������������  
		Skip4:;
		cout<<"\n  ��������Ʒ����:";
		cin>>amount;
		if(cin.fail()==1)
		{
			cin.clear();
			cin.ignore(10000,'\n');
			cout<<"\n  �������˴��������,����������!\n\n  ";
			system("Pause");
			system("CLS");
			cout<<"****************************SellerSystem************************"<<"\n"<<"\n";
			cout<<"\n  ��������Ʒ����:"<<a<<"\n";
			cout<<"\n  ��������Ʒ�۸�:"<<price<<"\n";
			goto Skip4;
		}
		//������������ 
		cin.ignore();
		cout<<"\n  ���������Ʒ�Ľ���:";
		cin.getline(b,200);
		Last->setSellerID(sellerID);
		Last->setPrice(price);
		Last->setAmount(amount);
		Last->setGoodsName(a);
		Last->setIntroduction(b);
		cout<<"\n  �ϼܳɹ�,�Ƿ�����ϼ�?(Y/N)";
		cin>>order;
	}
	Last->next=Head;
	return Head;
}

//�г�������Ʒ��Ϣ
void List::print()
{
	int i=1,k;
	int Sum=Head->returnSum();
	goods *current=Head;
	for(k=0;k<Sum;k++)
	{
		cout<<i<<".";
		current->printGoodsInfo();
		current=current->next;
		i++; 
	}
}
void List::advice(long long *adList)
{
	int k=1,i=0,j;
	int Sum=Head->returnSum();
	goods *current=Head;
	while(true)
	{
		for(i=0;i<CreateRand(Sum,0);i++)
		{
			current=current->next;					
		}
		for(j=0;j<k;j++){
			if(adList[j]==current->showGoodsID())
			{
				goto skip;
			}
		}
		if(current->returnAmount()==0) goto skip;
		cout<<k<<".";
		adList[k-1]=current->showGoodsID();
		k++;
		current->printGoodsInfo();
		if((k-1)==Sum||(k-1)==10) 
			break;
		skip:;
	}
}
void List::showRank10Goods(long long *adList)
{
	this->RankSeller();
	int Sum=Head->returnSum();
	int i,t;
	goods *current=Head;
	char order;
	cout<<"---------------------------��������-------------------------------\n"; 
	for(i=0;i<Sum;i++)
	{
		if(i==10) break;
		cout<<i+1<<".";
		current->printGoodsInfo();
		adList[i]=current->showGoodsID();
		current=current->next;
	}
}
char * List::returnRandomGoodsName()
{
	int k=1,i=0,j;
	int Sum=Head->returnSum();
	goods *current=Head;
	while(true)
	{
		for(i=0;i<CreateRand(Sum,0);i++)
		{
			current=current->next;					
		}
		if(current->returnAmount()==0) continue; 
		return current->showGoodsName(); 
	}
} 


goods* List::returnGoodsPoint(long long wareID)
{
	int Sum=Head->returnSum(),i;
	goods *current=Head;
	for(i=0;i<Sum;i++)
	{
		if(current->showGoodsID()==wareID)
		{
			return current; 
		}
		current=current->next;
	}
}
//���ݲ�����Ϣ(�Ƿ����Ӵ�)��չʾ�����Ϣ
void List::search(char *a,long long *goodsList)
{
	int Sum=Head->returnSum(),i,k=0;
	goods *current=Head;
	char order='N';
	Skip:; 
	for(i=0;i<Sum;i++)
	{
		if(isStr(a,current->showGoodsName()))
		{ 	
			if(k==10)
			{	
				cout<<"��������?"<<endl;
				cin>>order;
				if(order=='Y')
				{ 
					system("Pause");
					for(k=0;k<10;k++)
						goodsList[k]=0;
					k=0;
					current=Head;
					goto Skip;
				}
				else return;
			}
			goodsList[k]=current->showGoodsID();
			k++;
		}
		current=current->next;
	}
}
void List::search(char *a)
{
	int Sum=Head->returnSum(),i;
	goods *current=Head;
	for(i=0;i<Sum;i++)
	{
		if(isStr(a,current->showGoodsName()))
		{ 	
			current->printGoodsInfo();
		}
		current=current->next;
	}
}

void List::search(long long GoodsID)
{
	int Sum=Head->returnSum();
	int i;
	goods *current=Head;
	for(i=0;i<Sum;i++)
	{
		if(current->showGoodsID()==GoodsID)
		{
			current->simplePrintGoodsInfo();
//			current->printGoodsInfo();
		}
		current=current->next;
	}
}
int List::searchSeller(int sellerID)
{
	int Sum=Head->returnSum();
	int i,k=1;
	goods *current=Head;
	for(i=0;i<Sum;i++)
	{
		if(current->showSellerID()==sellerID)
		{
			cout<<k<<"."; 
			current->simplePrintGoodsInfo();
			k++; 
		}
		current=current->next;
	}
	return k-1; 
}

void List::ChangeSingleSellerGoodsInfo(int sellerID,int t)
{
	int Sum=Head->returnSum();
	int i,k=1,order;
	goods *current=Head;
	for(i=0;i<Sum;i++)
	{
		if(current->showSellerID()==sellerID)
		{
			if(k==t)
			{	
				char a[100];
				char b[200];
				int price;
				int amount;
				while(true)
				{
					system("CLS");
					cout<<"  ";
					current->simplePrintGoodsInfo();
					cout<<"   1)�޸���Ʒ����"<<"\t\t";
					cout<<"   4)�޸���Ʒ����"<<"\n\n";
					cout<<"   2)�޸���Ʒ�۸�"<<"\t\t";
					cout<<"   5)�¼���Ʒ"<<"\n\n";
					cout<<"   3)��������Ʒ����"<<"\t\t";
					cout<<"   6)���ز˵�"<<"\n\n"; 
					cout<<"------------------------------\n";
					cout<<"  #������ָ��:";
					cin>>order;
					if(!(order<=6&&order>=1))
					{
						cout<<"  ��������ȷ��ָ��!"<<"\n";
						cin.clear();
						cin.ignore(10000,'\n');
						cout<<"  ";
						system("Pause");
						continue;
					}
					switch(order)
					{
						case 1:
							cin.ignore(); 
							cout<<"   ��������Ʒ����:";
							cin.getline(a,100);
							current->setGoodsName(a);
							break;
						case 2:
							Skip1:; 
							cout<<"   ��������Ʒ�۸�:"; 
							cin>>price;
							if(cin.fail()==1)
							{
								cin.clear();
								cin.ignore(10000,'\n');
								cout<<"\n  �������˴���ļ۸�,����������!\n";
								goto Skip1;
							}
							current->setPrice(price);
							break;
						case 3:
							Skip2:; 
							cout<<"   ��������Ʒ����:";
							cin>>amount;
							if(cin.fail()==1)
							{
								cin.clear();
								cin.ignore(10000,'\n');
								cout<<"\n  �������˴���ļ۸�,����������!\n";
								goto Skip2;
							}
							current->setAmount(amount);
							break;
						case 4:
							cin.ignore();
							cout<<"   ���������Ʒ������";
							cin.getline(b,200);
							current->setIntroduction(b);
							break;
						case 5:
							current->setAmount(0);
							cout<<"   �¼ܳɹ�!";
							Sleep(2000); 
							break;
						case 6:
							return;
					}
				}
			}
			k++;
		}
		current=current->next;
	}
}

char * List::returnName(long long wareID)
{
	int Sum=Head->returnSum();
	int i;
	goods *current=Head;
	for(i=0;i<Sum;i++)
	{
		if(current->showGoodsID()==wareID)
		{
			return current->showGoodsName(); 
		}
		current=current->next;
	}
}

int List::returnPrice(long long wareID)
{
	int Sum=Head->returnSum();
	int i;
	goods *current=Head;
	for(i=0;i<Sum;i++)
	{
		if(current->showGoodsID()==wareID)
		{
			return current->showPrice(); 
		}
		current=current->next;
	}
}

int List::returnSellerID(long long wareID)
{
	int Sum=Head->returnSum();
	int i,t;
	goods *current=Head;
	char order;
	for(i=0;i<Sum;i++)
	{
		if(current->showGoodsID()==wareID)
		{
				t=current->showSellerID();
				return t; 
		}
		current=current->next;
	}
	return 0; 	
}

int List::sell(long long wareID)
{ 	
	int Sum=Head->returnSum();
	int i,t;
	goods *current=Head;
	char order;
	for(i=0;i<Sum;i++)
	{
		if(current->showGoodsID()==wareID)
		{
			
			cout<<"  ";
			current->printGoodsInfo();
			cout<<"------------------------------------------\n";
			cout<<"  #�Ƿ���(Y/N):";
			cin>>order;
			if(toupper(order)=='Y')
			{
				current->soldOut(); 
				cout<<"\n  ����ɹ�!"<<"\n";
				t=current->showSellerID();
				return t; 
				//�����غ�������ӽ����������а�or���ۺ�̨���� 
			}
		}
		current=current->next;
	}
	return 0; 
}

goods*  List::pSkip(goods *p,int a)
{
	int i;
	for(i=0;i<a;i++)
	{
		p=p->next;
	}
	return p;
}

void List::RankSeller()
	{
		goods *p1,*p2,*p3;
		int Sum=Head->returnSum();
		int i,j;
		goods *current=Head;
		int temp; 
		for(i=0;i<Sum;i++)
		{
			for(j=1;j<Sum-i;j++)//�������нڵ�,ʹ�õ�ǰ�ڵ�Ϊ���ֵ; 
			{
				if(current->showSoldAmount()<pSkip(current,j)->showSoldAmount()) {
					goods temp;
					goods *p4=pSkip(current,j);
					p2=current->next;
					p3=p4->next;
					temp=*current;
					*current=*p4;
					current->next=p2;
					*p4=temp;
					p4->next=p3;
				}
			}
			current=current->next;
		}
	}


void List::showRank10Goods(int sellerID)
{
	this->RankSeller();
	int Sum=Head->returnSum();
	int i,k=1;
	goods *current=Head;
	char order;
	cout<<"---------------------------��������-------------------------------\n"; 
	for(i=0;i<Sum;i++)
	{
		if(i==10) break;
		if(current->showSellerID()==sellerID)
		{
			cout<<k<<".";
			current->simplePrintGoodsInfo();
			k++;
		}
		current=current->next;
	}
}

void List::FileStore()
{
	fstream fList;
	fList.open("ListData.dat",ios::out|ios::binary);
	if(fList.fail()) cout<<"�����ļ�ʧ��!";
	goods *current=Head;
	int i; 
	int Sum=Head->returnSum(); 
	for(i=0;i<Sum;i++)
	{
		fList.write((char*)current,sizeof(goods));
		current=current->next;		
	}
	fList.close();
}

void List::FlieLeadIn()
{
	fstream fList;
	fList.open("ListData.dat",ios::in|ios::binary);
	if(fList.fail()) return; 
	Last=new goods;
	Head=Last;
	goods *current=Last;
	fList.read((char *)current,sizeof(goods));
	while(fList.peek()!=EOF)
	{
		Last=new goods;
		fList.read((char *)Last,sizeof(goods));
		current->next=Last;
		current=Last;
	}
	Last->next=Head;
	fList.close();
}
