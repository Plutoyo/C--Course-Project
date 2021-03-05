#include <iostream>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <conio.h>

#include "other Function.h"
#include "goods.h"
using namespace std;
int goods::Sum=0;
goods::goods()
{
	Sum++;
	price=0;
	amount=0;
	SoldAmount=0;
	goodsID=CreateRand(9999999999,1000000000);
}
goods::~goods()
{
	Sum--; 
}
int goods::returnSum()
{
	return Sum;
}
void goods::simplePrintGoodsInfo()
{
	cout<<" 商 品 名:"<<goodsName<<"\n";
	cout<<"   价    格:"<<price<<"\n";
	cout<<"   数    量:"<<amount<<"\n";
	cout<<"   销    量:"<<SoldAmount<<"\n";
	cout<<"   商品描述:";
	cout<<introduction<<"\n\n"; 
}


void goods::printGoodsInfo()
{
	cout<<" 卖 家 ID:"<<sellerID<<"\n"; 
	cout<<"   商品代码:"<<goodsID<<"\n"; 
	cout<<"   商 品 名:"<<goodsName<<"\n";
	cout<<"   价    格:"<<price<<"\n";
	cout<<"   数    量:"<<amount<<"\n";
	cout<<"   销    量:"<<SoldAmount<<"\n";
	cout<<"   商品描述:";
	cout<<introduction<<"\n\n"; 
}
void goods::setPrice(int a)
{
	price=a;
}
void goods::setAmount(int a)
{
	amount =a;
}
void goods::setGoodsName(char *p)
{
	strcpy(goodsName,p);
}
void goods::setIntroduction(char *p)
{
	strcpy(introduction,p);
}
void goods::setSellerID(int a)
{
	sellerID=a;
}
char* goods::showGoodsName()
{
	return goodsName;
}

int goods::showPrice()
{
	return price;
}

int goods::showSellerID()
{
	return sellerID;
}
int goods::showSoldAmount()
{
	return SoldAmount;
}
long long goods::showGoodsID()
{
	return goodsID;	
}

int goods::returnAmount()
{
	return amount;	
}
void goods::soldOut(){
	if(amount==0) cout<<"数量为0,购买失败";
	else 
	{
		amount--;
		SoldAmount++; 
	}
}
