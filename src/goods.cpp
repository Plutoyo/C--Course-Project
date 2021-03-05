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
	cout<<" �� Ʒ ��:"<<goodsName<<"\n";
	cout<<"   ��    ��:"<<price<<"\n";
	cout<<"   ��    ��:"<<amount<<"\n";
	cout<<"   ��    ��:"<<SoldAmount<<"\n";
	cout<<"   ��Ʒ����:";
	cout<<introduction<<"\n\n"; 
}


void goods::printGoodsInfo()
{
	cout<<" �� �� ID:"<<sellerID<<"\n"; 
	cout<<"   ��Ʒ����:"<<goodsID<<"\n"; 
	cout<<"   �� Ʒ ��:"<<goodsName<<"\n";
	cout<<"   ��    ��:"<<price<<"\n";
	cout<<"   ��    ��:"<<amount<<"\n";
	cout<<"   ��    ��:"<<SoldAmount<<"\n";
	cout<<"   ��Ʒ����:";
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
	if(amount==0) cout<<"����Ϊ0,����ʧ��";
	else 
	{
		amount--;
		SoldAmount++; 
	}
}
