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
#include "Administrator.h"
int seller::sellerSum=0;
seller::seller()
{
	int i;
	sellerSum++;
	Score=0;
	for(i=0;i<1000;i++)
	{
		SendGoods1[i]=0;
		SendGoods2[i]=0;
		SendGoods3[i]=0;
	}
}
seller::~seller()
{
	sellerSum--;	
}
int seller::returnSum()
{
	return sellerSum;
}
void seller::putOnSale(List&catalogue)//上架商品 
{
	catalogue.input(ID);
}
//传入特征ID,所以可以查询到每个商品的卖家 
int seller::ListAllGoods(List&catalogue)
{
	return catalogue.searchSeller(ID);
}

void seller::Sell(consumer *point,long long wareID)
{
	int i;
	for(i=0;i<1000;i++)
	{
		if(SendGoods1[i]==0) break;
	}
	SendGoods1[i]=point->showID();
	SendGoods2[i]=wareID;
	SendGoods3[i]=1;
}

void seller::SendGoods(buyerDataBase&BuyerDataBase,List&catalogue)
{
	consumer *point;
	int k,i,m;
	long long t;
	for(i=0;i<1000;i++)
	{
		if(SendGoods1[i]==0) break;
		cout<<i+1<<".";
		cout<<catalogue.returnName(SendGoods2[i])<<"\n";
		point=BuyerDataBase.searchBuyer(SendGoods1[i]); 
		point->showBuyerInfo();
		if(SendGoods3[i]==1) cout<<"  单    号:尚未发货"<<"\n";
		else cout<<"单号:"<<SendGoods3[i]<<"\n";
	}
	cout<<"------------------------------------------------\n";
	if(i==0)
	{
		cout<<"  暂未售出商品;\n\n  "; 
		return;
	} 
	cout<<"  输入序号进行发货,输入0退出:"<<"\n";
	cout<<"  "; 
	cin>>k;
//	SendGoods1[i]=point->showID();买家的Id 
//	SendGoods2[i]=wareID;售出物品的Id' 
//	SendGoods3[i]=1;单号 
	if(!(k>0&&k<=i)){
		cout<<"  输入了错误的指令!\n  ";
		return;
	}
	else
	{
		system("CLS");
		cout<<"-----------------------SendGoodsSystem---------------------------\n\n"; 
		k--; 
		point=BuyerDataBase.searchBuyer(SendGoods1[k]);
		for(m=0;m<100;m++){
			if(point->PurchasedGoods[m]==SendGoods2[k]&&SendGoods3[k]==1) break;
		}
		Skip1:;
		cout<<"  请输入单号: ";
		cin>>t;
		if(cin.fail()==1)
		{
			cin.clear();
			cin.ignore(10000,'\n');
			cout<<"\n  您输入了错误的单号,请重新输入!\n";
			goto Skip1;
		}
		
		SendGoods3[k]=t;
		point->deliver[m]=t;
		string address1;
		string provice1[]={"江苏","浙江","上海"};
		string provice2[]={"安徽","福建","广东","北京","河北省"}; 
		char address2[200];
		strcpy(address2,point->showAddress());
		for(i=0;i<4;i++)
		{
			address1+=address2[i]; 
		}
		Date t1;
		cout<<"\n  您的包裹送到:"<<point->showAddress()<<"\n";
		cout<<"\n  您的单号为:"<<t<<"\n"; 
		if(address1==provice1[0]||address1==provice1[1]||address1==provice1[2])
		{
			t1++;
			t1++; 
			cout<<"\n  您的包裹预计 "<<t1<<" 送达"<<endl;
			t1.change();
			point->arrive[m]=t1;
				
		} 
		else if(address1==provice2[0]||address1==provice2[1]||address1==provice2[2]||address1==provice2[3]||address1==provice2[4])
		{
			t1++;
			t1++;
			t1++; 
			cout<<"\n  您的包裹预计 "<<t1<<" 送达"<<endl;
			t1.change();
			point->arrive[m]=t1;
		}
		else
		{
			t1++;	
			t1++;
			t1++;
			cout<<"\n  您的包裹预计 "<<t1<<" 后送达"<<endl;
			t1.change();
			point->arrive[m]=t1;
		}
	} 
} 
////与买家一样,卖家同时也可以搜索商品
void seller::search(List&catalogue,char *a)
{
	
	catalogue.search(a);
}
void seller::empty()
{
	int i; 
	for(i=0;i<1000;i++)
	{
		SendGoods1[i]=0;
		SendGoods2[i]=0;
		SendGoods3[i]=0;
	}	
}
void seller::increaseScore(int a)
{
	Score+=a;
}
int seller::returnScore()
{
	switch(Score/10){
		case 0: 
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
		case 4:
			return 	3;
		case 5:
		case 6:
		case 7:
			return 4;
		case 8:
		case 9:
		case 10:
		case 11:
			return 5;
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
			return 6;
	}
}
void seller::showAllMerchandiseSold(List &wareList)
{
	int i; 
	for(i=0;i<1000;i++)
	{
		if(SendGoods2[i]==0) break;
		else 
		{
			cout<<i+1<<".";
			wareList.search(SendGoods2[i]);
		}
	}
	if(i==0) cout<<"  尚未售出商品...\n"; 
}
void seller::showSelfInfo()
{
	cout<<"  卖家个人信息:"<<"\n\n";
	cout<<"  账    号:"<<ID<<"\n\n";
	cout<<"  用 户 名:"<<name<<"\n\n";
	cout<<"  年    龄:"<<age<<"\n\n";
	cout<<"  收货地址:"<<address<<"\n\n";
	cout<<"  账户余额:"<<account<<"元\n\n";  
}

