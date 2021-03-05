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
	//遍历找寻是否id相同,相同则再随机一个,直到不重复为止 
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
	cout<<"请输入要搜索的商品名:";
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

//修改函数增加评分功能 
void consumer::comment(seller* seller1)
{
	int Score;
	Skip:;
	cout<<"  请对卖家的服务打分(0~5):"; 
	cin>>Score;
	if(!(Score<=5&&Score>=0))
	{
		cout<<" 输入了错误的分数!";
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
		cout<<"  购买失败!您的余额不足!";
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
			cout<<"  -- 心级卖家\n";
			break;
		case 2:
			cout<<"  -- 钻石级卖家\n";
			break;
		case 3:
			cout<<"  -- 皇冠级卖家\n";
			break; 
		case 4:
		 	cout<<"  -- 金冠级卖家\n";
			break;
		case 5:
			cout<<"  -- 王者级卖家\n";
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
			cout<<"  物流信息:";
			if(arrive[i].returnisSet()==1)
			{
				cout<<"  快递单号:"<<deliver[i]<<"\n"; 
				cout<<"  预计"<<arrive[i]<<"到达\n";
			}
			else cout<<"  您购买的商品尚未发货.\n"; 
		}
	}
	if(i==0) cout<<"  您尚未在Nuaa购物系统购买宝贝哦...\n";
	
}
void consumer::showBuyerInfo()
{
	cout<<"  账    号:"<<ID<<"\n";
	cout<<"  用 户 名:"<<name<<"\n";
	cout<<"  收货地址:"<<address<<"\n";
} 
void consumer::showSelfInfo()
{
	cout<<"  买家个人信息:"<<"\n\n";
	cout<<"  账    号:"<<ID<<"\n\n";
	cout<<"  用 户 名:"<<name<<"\n\n";
	cout<<"  年    龄:"<<age<<"\n\n";
	cout<<"  收货地址:"<<address<<"\n\n";
	cout<<"  账户余额:"<<account<<"元"<<"\n\n"; 
}
void consumer::showLevel()
{
	cout<<"  您已经在NUAA购买了"<<level<<"件商品\n";	
}
