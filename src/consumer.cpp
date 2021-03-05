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
int consumer::consumerSum=0; 
consumer::consumer():Person()
{	
	//������Ѱ�Ƿ�id��ͬ,��ͬ�������һ��,ֱ�����ظ�Ϊֹ 
	consumerSum++;
	level=0;
	for(int i=0;i<100;i++)
	{
		PurchasedGoods[i]=0;
		deliver[i]=0; 
	}
}
consumer::~consumer()
{
	consumerSum--;
}
int consumer::returnSum()
{
	return consumerSum;
}
void consumer::search(List &wareList,long long *goodsList)
{
	char a[100];
	cout<<"������Ҫ��������Ʒ��:";
	cin.ignore();
	cin.getline(a,100);
	wareList.search(a,goodsList);
}

void consumer::empty()
{
	level=0; 
	for(int i=0;i<100;i++)
	{
		PurchasedGoods[i]=0;
		arrive[i].isSet=0;	
	}
} 

//�޸ĺ����������ֹ��� 
void consumer::comment(seller* seller1)
{
	int Score;
	Skip:;
	cout<<"  ������ҵķ�����(0~5):"; 
	cin>>Score;
	if(!(Score<=5&&Score>=0))
	{
		cout<<" �����˴���ķ���!";
		cout<<"   3..";
		Sleep(1000);
		cout<<"\b\b\b2..";
		Sleep(1000);
		cout<<"\b\b\b1..\n";
		goto Skip;
	}
	seller1->increaseScore(Score); 
}
 
void consumer::buy(sellerDataBase &SellerDataBase,List &wareList,long long wareID)
{
	seller* point; 
	int i,t=0,k;
	for(i=0;i<100;i++){
		if(PurchasedGoods[i]==0) break;
	}
	if(this->returnAccount()<wareList.returnPrice(wareID))
	{
		cout<<"  ����ʧ��!��������!";
		return; 
	}
	
	PurchasedGoods[i]=wareID;
	t=wareList.returnSellerID(wareID);
	point=SellerDataBase.returnSeller(t);
	k=point->returnScore();
	cout<<"   "<<point->showName();
	switch(k)
	{
		case 1:
			cout<<"  -- �ļ�����\n";
			break;
		case 2:
			cout<<"  -- ��ʯ������\n";
			break;
		case 3:
			cout<<"  -- �ʹڼ�����\n";
			break; 
		case 4:
		 	cout<<"  -- ��ڼ�����\n";
			break;
		case 5:
			cout<<"  -- ���߼�����\n";
			break; 
	} 
	t=wareList.sell(wareID);
	if(t==0) return;
	else {
		point->Sell(this,wareID);
		decreaseAccount(wareList.returnPrice(wareID));
		point->increaseAccount(wareList.returnPrice(wareID));
		comment(point);
	}
	level++;
}

void consumer::showPurchasedGoods(List &wareList)
{
	int i;
	for(i=0;i<100;i++){
		if(PurchasedGoods[i]==0) break;
		else 
		{
			cout<<i+1<<".";
			cout<<wareList.returnName(PurchasedGoods[i])<<"\n";
			cout<<"\n";
			cout<<"  ������Ϣ:";
			if(arrive[i].returnisSet()==1)
			{
				cout<<"  ��ݵ���:"<<deliver[i]<<"\n"; 
				cout<<"  Ԥ��"<<arrive[i]<<"����\n";
			}
			else cout<<"  ���������Ʒ��δ����.\n"; 
		}
	}
	if(i==0) cout<<"  ����δ��Nuaa����ϵͳ���򱦱�Ŷ...\n";
	
}
void consumer::showBuyerInfo()
{
	cout<<"  ��    ��:"<<ID<<"\n";
	cout<<"  �� �� ��:"<<name<<"\n";
	cout<<"  �ջ���ַ:"<<address<<"\n";
} 
void consumer::showSelfInfo()
{
	cout<<"  ��Ҹ�����Ϣ:"<<"\n\n";
	cout<<"  ��    ��:"<<ID<<"\n\n";
	cout<<"  �� �� ��:"<<name<<"\n\n";
	cout<<"  ��    ��:"<<age<<"\n\n";
	cout<<"  �ջ���ַ:"<<address<<"\n\n";
	cout<<"  �˻����:"<<account<<"Ԫ"<<"\n\n"; 
}
void consumer::showLevel()
{
	cout<<"  ���Ѿ���NUAA������"<<level<<"����Ʒ\n";	
}
