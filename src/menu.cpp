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

void SellerMenu(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,seller *now,List&wareList);
void BuyerMenu(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,consumer *now,List&wareList);
void AdministratorMenu(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,List&wareList);
void LogIn(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,consumer *p1,seller *p2,List&wareList)
{
	int order; 
	while(true)
	{
		system("CLS");
		cout<<"*******************************ShoppingSystem***************************"<<"\n"<<"\n";
		cout<<" ��ѡ�����:"<<"\n\n\n\n\n\n";
		cout<<"      1)���              ";
		cout<<" 2)����"<<"\n\n\n";
		cout<<"      3)�˳�ϵͳ\n\n\n"; 
		cout<<"--------------------------------------------\n";
		cout<<"  #������ָ��:";

		cin>>order;
		if(order!=2&&order!=1&&order!=3&&order!=9){
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
				BuyerMenu(SellerDataBase,BuyerDataBase,p1,wareList);
				break; 
			case 2:
				SellerMenu(SellerDataBase,BuyerDataBase,p2,wareList);
				break;
			case 3:
				cout<<"  ϵͳ�����˳�...\n"; 
						cout<<"   3..";
						Sleep(750);
						cout<<"\b\b\b2..";
						Sleep(750);
						cout<<"\b\b\b1..\n";
						cout<<"  ��л��ʹ��Nuaa����ϵͳ...\n"; 
						exit(0);
			case 9:
				AdministratorMenu(SellerDataBase,BuyerDataBase,wareList);
				break; 
		}
	}
}

void BuyerLogInMenu(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,consumer *now,List&wareList)
{
	cout<<"*******************************BuyerSystem***************************"<<"\n"<<"\n";
	int IDname;
	consumer *point; 
	cout<<" �������˻�(9λ����):";
	cin>>IDname;
	if(!(IDname<=999999999&&IDname>=100000000)) 
	{
		cout<<"\n �����˴�����˺�!";
		cout<<"   3..";
		Sleep(1000);
		cout<<"\b\b\b2..";
		Sleep(1000);
		cout<<"\b\b\b1..\n";
		cin.clear();
		cin.ignore(10000,'\n');
		return;
	}

	point=BuyerDataBase.logIn(IDname);
	BuyerMenu(SellerDataBase,BuyerDataBase,point,wareList);
}

void BuyersearchMenu(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,consumer *now,List&wareList)
{
	cout<<"*******************************BuyerSystem***************************"<<"\n"<<"\n";
	char a[100];
	int i=0,k=1;
	char order='N'; 
	long long goodsList[10];
	for(i=0;i<10;i++)
	{
		goodsList[i]=0;
	}
	cout<<"������Ҫ�����ı�������:"; 
	cin.ignore();
	cin.getline(a,100);
	goods *temp; 
	wareList.search(a,goodsList);
	if(goodsList[0]!=0){
		for(i=0;i<10;i++)
		{
			if(goodsList[i]!=0)
			{
				temp=wareList.returnGoodsPoint(goodsList[i]);
				if(temp->returnAmount()==0) continue; 
				cout<<k<<".";
				wareList.search(goodsList[i]);
				k++; 
			}
		}
		if(now==nullptr)
		{
			cout<<"  ���ȵ�¼!";
			system("Pause"); 
			return;
		} 
		cout<<"-----------------------------------------------------\n"; 
		cout<<"  �Ƿ�����Ʒ(Y/N):"; 
		cin>>order;
		if(toupper(order)=='Y')
		{
			cout<<"\n  ������:";
			cin>>i;
			if(!(i>0&&i<=k-1))
			{
				cin.clear();
				cin.ignore(10000,'\n');
				cout<<"\n  �������˴����ָ��!\n\n  ";
				system("Pause");
				return;
			} 
			system("CLS");
			cout<<"*******************************BuyerSystem***************************"<<"\n"<<"\n";
			now->buy(SellerDataBase,wareList,goodsList[i-1]);
		}
	}
	else {
		cout<<"δ�����������Ʒ"<<"\n";
		cout<<"�����Ը�����Ĺؼ��������.";
		cout<<"����:"<<wareList.returnRandomGoodsName()<<"\n"; 
		}
	cout<<"\n  ";
	system("Pause");
	BuyerMenu(SellerDataBase,BuyerDataBase,now,wareList);
}

void BuyerAd(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,consumer *now,List&wareList){
	cout<<"*******************************BuyerSystem***************************"<<"\n"<<"\n";
	int i=0,k;
	char order='N'; 
	long long adList[10];
	for(i=0;i<10;i++)
	{
		adList[i]=0;
	}
	wareList.advice(adList);
	cout<<"----------------------------------------------------\n";
	cout<<"\n  �Ƿ�����ϲ������Ʒ?(Y/N):  ";
	cin>>order;
	if(toupper(order)=='Y'){
		if(now==nullptr) 
		{
			cout<<"\n ���ȵ�¼!"<<"\n"<<"\n"<<"\n";
			system("Pause"); 
			BuyerMenu(SellerDataBase,BuyerDataBase,now,wareList);
		} 
		cout<<"\n  �����Ź���:";
		for(i=0;i<10;i++)
		{
			if(adList[i]==0) break;
		}
		k=i;
		cin>>i;
		if(!(i>0&&i<=k))
			{
				cin.clear();
				cin.ignore(10000,'\n');
				cout<<"\n  �������˴����ָ��!\n\n  ";
				system("Pause");
				return;
			} 
		system("CLS");
		cout<<"*******************************BuyerSystem***************************"<<"\n"<<"\n";
		now->buy(SellerDataBase,wareList,adList[i-1]); 
	}
	else BuyerMenu(SellerDataBase,BuyerDataBase,now,wareList);
	system("Pause");
}

void BuyerRank(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,consumer *now,List&wareList)
{
	cout<<"*******************************BuyerSystem***************************"<<"\n"<<"\n";
	int i=0,k;
	char order='N'; 
	long long adList[10];
	for(i=0;i<10;i++)
	{
		adList[i]=0;
	}
	wareList.showRank10Goods(adList);
	cout<<"----------------------------------------------------\n";
	cout<<"\n  �Ƿ�����ϲ������Ʒ?(Y/N):  ";
	cin>>order;
	if(toupper(order)=='Y'){
		if(now==nullptr) 
		{
			cout<<"\n ���ȵ�¼!"<<"\n"<<"\n"<<"\n";
			system("Pause"); 
			BuyerMenu(SellerDataBase,BuyerDataBase,now,wareList);
		} 
		cout<<"\n  �����Ź���:";
		for(i=0;i<10;i++)
		{
			if(adList[i]==0) break;
		}
		k=i;
		cin>>i;
		if(!(i>0&&i<=k))
		{
			cin.clear();
			cin.ignore(10000,'\n');
			cout<<"\n  �������˴����ָ��!\n\n  ";
			system("Pause");
			return;
		}
		system("CLS");
		cout<<"*******************************BuyerSystem***************************"<<"\n"<<"\n";
		now->buy(SellerDataBase,wareList,adList[i-1]); 
	}
	else BuyerMenu(SellerDataBase,BuyerDataBase,now,wareList);
	cout<<"\n  ";
	system("Pause");
}

void BuyerSelfInfo(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,consumer *now,List&wareList)
{
	char order='N';
	int order1,i;
	cout<<"*******************************BuyerSystem***************************"<<"\n"<<"\n";
	if(now==nullptr)
	{
		cout<<"���ȵ�¼!";
		system("Pause");
		BuyerMenu(SellerDataBase,BuyerDataBase,now,wareList);
	}
	else
	{
		now->showSelfInfo();
		now->showLevel(); 
		cout<<"-----------------------------------------------------\n"; 
		cout<<"\n �Ƿ��޸������Ϣ(Y/N):"; 
		cin>>order;
		if(toupper(order)=='Y') 
		{	
			char temp[200];
			int temp1; 
			while(true)
			{ 
				system("CLS");
				now->showSelfInfo(); 
				cout<<"-----------------------------------------------------\n"; 
				cout<<"  1.�޸�����"<<"\n";
				cout<<"  2.�޸�����"<<"\n";
				cout<<"  3.�޸ĵ�ַ"<<"\n";
				cout<<"  4.��ֵ"<<"\n";
				cout<<"  5.�˳�"<<"\n\n"; 
				cout<<"  #������ָ��:";
				cin>>order1;
				
				if(!(order1>=1&&order1<=5)) 
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
						cout<<"  ����Ҫ�޸ĵ�����:";
						cin.ignore();
						cin.getline(temp,200); 
						now->setName(temp);
						cout<<"\n  �޸ĳɹ�!"<<"\n\n  ";
						system("Pause");
						break; 
					case 2:
						cout<<"  ������Ҫ�޸ĵ�����:";
						cin>>temp1;
						if(!(temp1>0&&temp1<=200))
						{
							cin.clear();
							cin.ignore(10000,'\n');
							cout<<"\n  �������˴��������!\n\n  ";
							system("Pause");
							break; 
						}
						now->setAge(temp1);
						cout<<"\n  �޸ĳɹ�!"<<"\n\n  ";
						system("Pause"); 
						break;
					case 3:
						cout<<"  ����Ҫ�޸ĵĵ�ַ:";
						cin.ignore();
						cin.getline(temp,200); 
						now->setAddress(temp);
						cout<<"\n  �޸ĳɹ�!"<<"\n\n  ";
						system("Pause");
						break;
					case 4:
						cout<<"  ������Ҫ��ֵ�Ľ��:";
						cin>>temp1;
						if(!(temp1>0&&temp1<=1000000)) 
						{
							cout<<"\n  ��������ȷ�Ľ��\n";
							if(temp1>1000000) cout<<"  ÿ�γ�ֵ����Ϊһ����!\n\n  ";
							cin.clear();
							cin.ignore(10000,'\n');
							system("Pause");
							break;
						}
						now->increaseAccount(temp1);
						cout<<"\n  ��ֵ�ɹ�!ף���������!"<<"\n\n  ";
						system("Pause");
						break;
					case 5:
						return;
				} 	
			} 
		system("Pause");
		BuyerMenu(SellerDataBase,BuyerDataBase,now,wareList);
		}
	}
}

void showPurchasedGoods(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,consumer *now,List&wareList)
{
	cout<<"*******************************BuyerSystem***************************"<<"\n"<<"\n";
	if(now==nullptr)
	{
		cout<<"���ȵ�¼!";
		system("Pause");
		BuyerMenu(SellerDataBase,BuyerDataBase,now,wareList);
	}
	else
	{
		now->showPurchasedGoods(wareList);
		cout<<"------------------------------------------------\n"; 
		cout<<"  ";
		system("Pause");
		BuyerMenu(SellerDataBase,BuyerDataBase,now,wareList);
	}

}

void BuyerMenu(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,consumer *now,List&wareList)
{
	int order;
	while(true)
	{
		system("CLS");
		if(now==nullptr)
		{
			cout<<"*******************************BuyerSystem***************************"<<"\n"<<"\n";
			cout<<"  1)��¼"<<"\t\t\t";
			cout<<"  5)�鿴�������а�"<<"\n\n";
			cout<<"  2)ע�����"<<"\t\t\t";
			cout<<"  6)�鿴������Ϣ"<<"\n\n";
			cout<<"  3)������Ҫ�������Ʒ"<<"\t\t";
			cout<<"  7)�鿴�ѹ������Ʒ"<<"\n\n";
			cout<<"  4)����Ƽ���Ʒ"<<"\t\t";
			cout<<"  8)�˳�ϵͳ"<<"\n"<<"\n\n";
			
	
			if(now==nullptr) cout<<"                                               ���δ��¼"<<"\n\n";
			else  cout<<"                                               ����ѵ�¼"<<"\n\n";
			cout<<"                          �������:"<<BuyerDataBase.showSum()-1<<" ��������:"
			<<SellerDataBase.showSum()-1<<" ��Ʒ��:"<<wareList.returnSum()<<"\n";
			cout<<"-------------------------------------------------------------------\n";
			cout<<"  #������ָ��:";
			cin>>order;
			if(!(order<=8&&order>=1))
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
						system("CLS");
//						BuyerDataBase.print();
						BuyerLogInMenu(SellerDataBase,BuyerDataBase,now,wareList);
						break;
					case 2:
						system("CLS");
						cout<<"*******************************BuyerSystem***************************"<<"\n"<<"\n";
						now=BuyerDataBase.input();
						continue; 
						break; 
					case 3:
						system("CLS");
						BuyersearchMenu(SellerDataBase,BuyerDataBase,now,wareList); 
						break;
					case 4:
						system("CLS");
						BuyerAd(SellerDataBase,BuyerDataBase,now,wareList);
						break;
					case 5:
						system("CLS");
						BuyerRank(SellerDataBase,BuyerDataBase,now,wareList);
						break;
					case 6:
						system("CLS");
						BuyerSelfInfo(SellerDataBase,BuyerDataBase,now,wareList); 
						break; 
					case 7:
						system("CLS");
						showPurchasedGoods(SellerDataBase,BuyerDataBase,now,wareList);
						break;
					case 8:
						BuyerDataBase.FileStore();
						SellerDataBase.FileStore();
						wareList.FileStore();
						cout<<"  �����˳����ϵͳ...\n"; 
						cout<<"   3..";
						Sleep(750);
						cout<<"\b\b\b2..";
						Sleep(750);
						cout<<"\b\b\b1..\n";
						Sleep(750);
						return; 
				}	
		}
		else 
		{
			cout<<"*******************************BuyerSystem***************************"<<"\n"<<"\n";
			cout<<"  1)������Ҫ�������Ʒ"<<"\t\t";
			cout<<"  4)�鿴������Ϣ"<<"\n\n";
			cout<<"  2)����Ƽ���Ʒ"<<"\t\t";
			cout<<"  5)�鿴�ѹ������Ʒ"<<"\n\n";
			cout<<"  3)�鿴�������а�"<<"\t\t";
			cout<<"  6)�˳�ϵͳ"<<"\n"<<"\n\n";
			
	
			if(now==nullptr) cout<<"                                               ���δ��¼"<<"\n\n";
			else  cout<<"                                               ����ѵ�¼"<<"\n\n";
			cout<<"                          �������:"<<BuyerDataBase.showSum()-1<<" ��������:"
			<<SellerDataBase.showSum()-1<<" ��Ʒ��:"<<wareList.returnSum()<<"\n";
			cout<<"-------------------------------------------------------------------\n";
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
 			switch(order){
					case 1:
						system("CLS");
						BuyersearchMenu(SellerDataBase,BuyerDataBase,now,wareList); 
						break;
					case 2:
						system("CLS");
						BuyerAd(SellerDataBase,BuyerDataBase,now,wareList);
						break;
					case 3:
						system("CLS");
						BuyerRank(SellerDataBase,BuyerDataBase,now,wareList);
						break;
					case 4:
						system("CLS");
						BuyerSelfInfo(SellerDataBase,BuyerDataBase,now,wareList); 
						break; 
					case 5:
						system("CLS");
						showPurchasedGoods(SellerDataBase,BuyerDataBase,now,wareList);
						break;
					case 6:
						BuyerDataBase.FileStore();
						SellerDataBase.FileStore();
						wareList.FileStore();
						cout<<"  �����˳����ϵͳ...\n"; 
						cout<<"   3..";
						Sleep(750);
						cout<<"\b\b\b2..";
						Sleep(750);
						cout<<"\b\b\b1..\n";
						Sleep(750);
						return;
			}
		}
	}
}






void SellerLogInMenu(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,seller *now,List&wareList)
{
	cout<<"*******************************SellerSystem***************************"<<"\n"<<"\n";
	int IDname;
	seller *point; 
	cout<<" �������˻�(9λ����):";
	cin>>IDname;
	if(!(IDname<=999999999&&IDname>=100000000)) 
	{
		cout<<"\n �����˴�����˺�!";
		cout<<"   3..";
		Sleep(1000);
		cout<<"\b\b\b2..";
		Sleep(1000);
		cout<<"\b\b\b1..\n";
		cin.clear();
		cin.ignore(10000,'\n');
		return;
	}
	point=SellerDataBase.logIn(IDname);
	SellerMenu(SellerDataBase,BuyerDataBase,point,wareList);
}

void PutOnSale(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,seller *now,List&wareList)
{
	cout<<"*******************************SellerSystem***************************"<<"\n"<<"\n";
	if(now==nullptr)
	{
		cout<<"���ȵ�¼!";
		system("Pause");
		SellerMenu(SellerDataBase,BuyerDataBase,now,wareList);
	}
	else
	{
		now->putOnSale(wareList);
		cout<<"\n  ";
		system("Pause");
		SellerMenu(SellerDataBase,BuyerDataBase,now,wareList);
	}
}

void showPutOnSaleGoods(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,seller *now,List&wareList)
{
	cout<<"*******************************SellerSystem***************************"<<"\n"<<"\n";
	if(now==nullptr)
	{
		cout<<"���ȵ�¼!";
		system("Pause");
		SellerMenu(SellerDataBase,BuyerDataBase,now,wareList);
	}
	else
	{
		char Corder='N';
		int order,k; 
		k=now->ListAllGoods(wareList);
		cout<<"--------------------------------------------\n";
		cout<<"�Ƿ����Ʒ��Ϣ�����޸�?(Y/N):"; 
		cin>>Corder;
		if(toupper(Corder)=='Y')
		{
			cout<<"\n������Ҫ�޸ĵ���Ʒ���:";
			cin>>order;
			if(!(order<=k&&order>=1))
			{
				cout<<"  ��������ȷ��ָ��!"<<"\n";
				cin.clear();
				cin.ignore(10000,'\n');
				cout<<"  ";
				system("Pause");
				return;
			}
			system("CLS"); 
			wareList.ChangeSingleSellerGoodsInfo(now->showID(),order); 
		}
		system("Pause");
		SellerMenu(SellerDataBase,BuyerDataBase,now,wareList);
	} 
} 
void SendGoodsSystem(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,seller *now,List&wareList)
{
	cout<<"*******************************SellerSystem***************************"<<"\n"<<"\n";
	if(now==nullptr)
	{
		cout<<"���ȵ�¼!";
		system("Pause");
		SellerMenu(SellerDataBase,BuyerDataBase,now,wareList);
	}
	else
	{
		now->SendGoods(BuyerDataBase,wareList);
		cout<<"\n  "; 
		system("Pause");
		SellerMenu(SellerDataBase,BuyerDataBase,now,wareList);
	}
} 
void SellerSelfInfo(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,seller *now,List&wareList)
{
	int k;
	char order='N'; 
	cout<<"*******************************SellerSystem***************************"<<"\n"<<"\n";
	if(now==nullptr)
	{
		cout<<"���ȵ�¼!";
		system("Pause");
		SellerMenu(SellerDataBase,BuyerDataBase,now,wareList);
	}
	else
	{
		k=now->returnScore();
		cout<<"  ����"; 
		switch(k)
		{
			case 1:
				cout<<"  -- �ļ�����\n\n";
				break;
			case 2:
				cout<<"  -- ��ʯ������\n\n";
				break;
			case 3:
				cout<<"  -- �ʹڼ�����\n\n";
				break; 
			case 4:
			 	cout<<"  -- ��ڼ�����\n\n";
				break;
			case 5:
				cout<<"  -- ���߼�����\n\n";
				break; 
		} 
		now->showSelfInfo();
		cout<<"-----------------------------------------------------\n"; 
		cout<<"�Ƿ��޸������Ϣ(Y/N):"; 
		cin>>order;
		if(toupper(order)=='Y') 
		{	
			int order1; 
			char temp[200];
			int temp1;
			while(true)
			{ 
				system("CLS");
				now->showSelfInfo();
				cout<<"-----------------------------------------------------\n"; 
				cout<<"  1.�޸�����"<<"\n";
				cout<<"  2.�޸�����"<<"\n";
				cout<<"  3.�޸ĵ�ַ"<<"\n";
				cout<<"  4.��ֵ"<<"\n";
				cout<<"  5.�˳�"<<"\n\n";
				cout<<"  #������ָ��:";
				cin>>order1;
				if(!(order1>=1&&order1<=5))
				{ 	
					cout<<"\n  ��������ȷ��ָ��!"<<"\n\n";
					cin.clear();
					cin.ignore(10000,'\n');
					cout<<"  ";
					system("Pause");
					continue;
				}
				switch(order1)
				{
					case 1:
						cout<<"  ����Ҫ�޸ĵ�����:";
						cin.ignore();
						cin.getline(temp,200); 
						now->setName(temp);
						cout<<"\n  �޸ĳɹ�!"<<"\n\n  ";
						system("Pause");
						break; 
					case 2:
						cout<<"  ������Ҫ�޸ĵ�����:";
						cin>>temp1;
						if(!(temp1>0&&temp1<=200))
						{
							cin.clear();
							cin.ignore(10000,'\n');
							cout<<"  �������˴��������!\n\n  ";
							system("Pause");
							break; 
						}
						now->setAge(temp1);
						cout<<"\n  �޸ĳɹ�!"<<"\n\n  ";
						system("Pause"); 
						break;
					case 3:
						cout<<"  ����Ҫ�޸ĵĵ�ַ:";
						cin.ignore();
						cin.getline(temp,200); 
						now->setAddress(temp);
						cout<<"\n  �޸ĳɹ�!"<<"\n\n  ";
						system("Pause");
						break;
					case 4:
						cout<<"  ������Ҫ��ֵ�Ľ��:";
						cin>>temp1;
						if(!(temp1>0&&temp1<=1000000)) 
						{
							cout<<"  ��������ȷ�Ľ��\n";
							if(temp1>1000000) cout<<"  ÿ�γ�ֵ����Ϊһ����!\n\n  ";
							cin.clear();
							cin.ignore(10000,'\n');
							system("Pause");
							break;
						}
						now->increaseAccount(temp1);
						cout<<"\n  ��ֵ�ɹ�!ף���������!"<<"\n\n  ";
						system("Pause");
						break;
					case 5:
						return; 
				}
			}
		system("Pause");
		SellerMenu(SellerDataBase,BuyerDataBase,now,wareList);
		}
	}
}

void SellerShowRank10(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,seller *now,List&wareList)
{
	cout<<"*******************************SellerSystem***************************"<<"\n"<<"\n";
	if(now==nullptr)
	{
		cout<<"���ȵ�¼!";
		system("Pause");
		SellerMenu(SellerDataBase,BuyerDataBase,now,wareList);
	}
	else
	{
		wareList.showRank10Goods(now->showID());
		system("Pause");
		SellerMenu(SellerDataBase,BuyerDataBase,now,wareList);
	}
}

void SellerSoldGoods(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,seller *now,List&wareList)
{
	cout<<"*******************************SellerSystem***************************"<<"\n"<<"\n";
	if(now==nullptr)
	{
		cout<<"���ȵ�¼!";
		system("Pause");
		SellerMenu(SellerDataBase,BuyerDataBase,now,wareList);
	}
	else
	{
		now->showAllMerchandiseSold(wareList);
		cout<<"--------------------------------------------\n";
		system("Pause");
		SellerMenu(SellerDataBase,BuyerDataBase,now,wareList);
	}
	
}

void SellerMenu(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,seller *now,List&wareList)
{
	int order;
	while(true)
	{

		system("CLS");
		if(now==nullptr){
			
			cout<<"*******************************SellerSystem***************************"<<"\n"<<"\n";
			cout<<"  1)��¼"<<"\t\t\t";
			cout<<"  5)����ϵͳ"<<"\n\n";
			cout<<"  2)ע������"<<"\t\t\t";
			cout<<"  6)�鿴�̼Ҹ�����Ϣ"<<"\n\n";
			cout<<"  3)�ϼ���Ʒ"<<"\t\t\t";
			cout<<"  7)�鿴�����������а�"<<"\n\n";
			cout<<"  4)�鿴���ϼܵ���Ʒ"<<"\t\t";
			cout<<"  8)�鿴����������Ʒ"<<"\n\n";
			cout<<"  9)�˳�ϵͳ"<<"\n"<<"\n\n";
			if(now==nullptr) cout<<"                                               ����δ��¼"<<"\n\n";
			else  cout<<"                                               �����ѵ�¼"<<"\n\n";
			cout<<"                          �������:"<<BuyerDataBase.showSum()-1<<" ��������:"
			<<SellerDataBase.showSum()-1<<" ��Ʒ��:"<<wareList.returnSum()<<"\n";
			cout<<"-------------------------------------------------------------------\n";
			cout<<"   #������ָ��:";
			cin>>order;
	
			if(!(order<=9&&order>=1))
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
							system("CLS");
	//						SellerDataBase.print();
							SellerLogInMenu(SellerDataBase,BuyerDataBase,now,wareList);
							break;
						case 2:
							system("ClS");
							cout<<"*******************************SellerSystem***************************"<<"\n"<<"\n";
							now=SellerDataBase.input();
							continue; 
						case 3:
							system("CLS");
							PutOnSale(SellerDataBase,BuyerDataBase,now,wareList);
							break;
						case 4: 
							system("CLS");
							showPutOnSaleGoods(SellerDataBase,BuyerDataBase,now,wareList);
							break;
						case 5:
							system("CLS");
							SendGoodsSystem(SellerDataBase,BuyerDataBase,now,wareList);
							break;
						case 6:
							system("CLS");
							SellerSelfInfo(SellerDataBase,BuyerDataBase,now,wareList);
							break;
						case 7:
							system("CLS");
							SellerShowRank10(SellerDataBase,BuyerDataBase,now,wareList);
							break;
						case 8:
							system("CLS");
							SellerSoldGoods(SellerDataBase,BuyerDataBase,now,wareList);
							break;
						case 9:
							SellerDataBase.FileStore();
							BuyerDataBase.FileStore();
							wareList.FileStore();
							cout<<"  �����˳�����ϵͳ...\n";
							cout<<"   3..";
							Sleep(750);
							cout<<"\b\b\b2..";
							Sleep(750);
							cout<<"\b\b\b1..\n";
							Sleep(750);
							return; 
				}
			}
		else 
		{	
			cout<<"*******************************SellerSystem***************************"<<"\n"<<"\n";
			cout<<"  1)�ϼ���Ʒ"<<"\t\t\t";
			cout<<"  5)�鿴�����������а�"<<"\n\n";
			cout<<"  2)�鿴���ϼܵ���Ʒ"<<"\t\t";
			cout<<"  6)�鿴����������Ʒ"<<"\n\n";
			cout<<"  3)����ϵͳ"<<"\t\t\t";
			cout<<"  7)�˳�ϵͳ"<<"\n"<<"\n";
			cout<<"  4)�鿴�̼Ҹ�����Ϣ"<<"\n\n";
			if(now==nullptr) cout<<"                                               ����δ��¼"<<"\n\n";
			else  cout<<"                                               �����ѵ�¼"<<"\n\n";
			cout<<"                          �������:"<<BuyerDataBase.showSum()-1<<" ��������:"
			<<SellerDataBase.showSum()-1<<" ��Ʒ��:"<<wareList.returnSum()<<"\n";
			cout<<"-------------------------------------------------------------------\n";
			cout<<"   #������ָ��:";
			cin>>order;
	
			if(!(order<=7&&order>=1))
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
							system("CLS");
							PutOnSale(SellerDataBase,BuyerDataBase,now,wareList);
							break;
						case 2: 
							system("CLS");
							showPutOnSaleGoods(SellerDataBase,BuyerDataBase,now,wareList);
							break;
						case 3:
							system("CLS");
							SendGoodsSystem(SellerDataBase,BuyerDataBase,now,wareList);
							break;
						case 4:
							system("CLS");
							SellerSelfInfo(SellerDataBase,BuyerDataBase,now,wareList);
							break;
						case 5:
							system("CLS");
							SellerShowRank10(SellerDataBase,BuyerDataBase,now,wareList);
							break;
						case 6:
							system("CLS");
							SellerSoldGoods(SellerDataBase,BuyerDataBase,now,wareList);
							break;
						case 7:
							SellerDataBase.FileStore();
							BuyerDataBase.FileStore();
							wareList.FileStore();
							cout<<"  �����˳�����ϵͳ...\n";
							cout<<"   3..";
							Sleep(750);
							cout<<"\b\b\b2..";
							Sleep(750);
							cout<<"\b\b\b1..\n";
							Sleep(750);
							return; 
				}
		}				
	}
}



void AdministratorMenu(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,List&wareList)
{
	int order,i;
	int password;
	char password1[10]; 
	stringstream turn; 
	Administrator A;
	cout<<"\n  ���������Ա�˻�����:"; 
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
	if(password!=1618103)
	{
		cout<<"\n\n  �������,ϵͳ�����˳�!\n";
		cout<<"    3..";
		Sleep(750);
		cout<<"\b\b\b2..";
		Sleep(750);
		cout<<"\b\b\b1..";
		exit(0);
	}
		while(true)
		{
			system("CLS");
			cout<<"*******************************Administrator***************************"<<"\n"<<"\n";
			cout<<"  1)�鿴���������Ϣ"<<"\t\t";
			cout<<"  4)ɾ�����"<<"\n\n";
			cout<<"  2)�鿴����������Ϣ"<<"\t\t";
			cout<<"  5)ɾ������"<<"\n\n"; 
			cout<<"  3)�鿴������Ʒ��Ϣ"<<"\t\t";
			cout<<"  6)�˳���̨����ϵͳ"<<"\n\n"; 
			cout<<"                          �������:"<<BuyerDataBase.showSum()-1<<" ��������:"
			<<SellerDataBase.showSum()-1<<" ��Ʒ��:"<<wareList.returnSum()<<"\n";
			cout<<"-------------------------------------------------------------------\n";
			cout<<"   #������ָ��:";
			cout<<"  ";
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
							system("CLS");
							cout<<"*******************************Administrator***************************"<<"\n"<<"\n";
							A.changeConsumer(BuyerDataBase,SellerDataBase);
							break;
						case 4:
							system("CLS");
							cout<<"*******************************Administrator***************************"<<"\n"<<"\n";
							A.deleteConsumer(BuyerDataBase); 
							break;
						case 2:
							system("CLS");
							cout<<"*******************************Administrator***************************"<<"\n"<<"\n";
							A.changeSeller(SellerDataBase,wareList); 
							break;
						case 5:
							system("CLS");
							cout<<"*******************************Administrator***************************"<<"\n"<<"\n";
							A.deleteSeller(SellerDataBase);
							break;
						case 3:
							system("CLS");
							cout<<"*******************************Administrator***************************"<<"\n"<<"\n";
							A.deleteGoods(wareList); 
							system("Pause");
							break;
						case 6:
							SellerDataBase.FileStore();
							BuyerDataBase.FileStore();
							wareList.FileStore();
							cout<<"    3..";
							Sleep(750);
							cout<<"\b\b\b2..";
							Sleep(750);
							cout<<"\b\b\b1..";
							cout<<"  ��л��ʹ�ñ�ϵͳ...�ټ�"; 
							exit(0);
				}
			}
}

void openingAnimation1(){
cout<<"                  .ZIjs,         .Z0qZFFjI  v s             ::                  \n"
"                   DENSNZI              :Luv ,I0N                                \n" 
"    ;lsv;          VOzFFV0             ;VlyysZL;Q               .         ss     \n" 
"   VOFzFuFSI,       ,7vv7:           vFI. ,SF                ,Z#mv,7      OlLF   \n" 
"  ;OClslssICFu        sjlIuuj.       bRFFNZ:            ,   vF7vjSO8C     0.:v   \n" 
"   FzFCyjyLVS#Z      :Rqv7vcySj.     v@v #@       ;vC;      0s    ,ZZ            \n" 
"    NFFFSzNVVsNZ       IuFCvv7V0Z.       :u     OQDE#NEE.   .bO.   zl            \n" 
"   vzLFzsIyLv:7SF       ;cFNCSSZ00C;           .QEZOZZqb7     yEZFFv   ;vv:      \n" 
"   .y7SvSyLsv.,jzu.        lZFzlLFER0          :OFzyCSqv              .R7vDO;    \n" 
"        ,FzCjLsjLzF.         yFFzZNZ;          lNZZZzu.        v;      FZ;vz7.   \n" 
"          LFzjjssLVF.          ;Iv                ;vV;         m@:      .::..    \n" 
"           :FSjLsssVz.                                          V#;              \n" 
"             sSVCsLjuZ;                   ybFQVvcv          .    Fqs:     ;      \n" 
"              ;qNzjSzZNv     u0v           b@@#FIDm        ,0v.;;7;sslzl;;Lb:,.  \n" 
"              vFFyCyIvlFC    b@D.         ;vllljNNv        Fb0svvVFVSs;..  ..,   \n" 
"               7;7CzCVVuzy.   :,        OIF@vSs            ;:.   ;OOFQL          \n" 
"                 :;;::vv;.,            v@@,@@u@Z                  .  ,RN         \n" 
"                  ..                    @@zF0SE#                      .RZl ..    \n" 
"                                         m@;;                 vqqc.   :;EDv,.    \n" 
"                       . ;0DF             ;                 7OEOZQbD   .v. .     \n" 
"                   : 7ONFFFF#.        .vv                S0qEZEFFVl,             \n" 
"                  O80NSOu;lvSZ       mR80ENl     .     vOmEqNFFqF                \n" 
"                  vRu.uFFCSsl#v     F@Nc7jbbs   vv;;  7bDFSuSIuS8I               \n" 
"                  S@ZLcZNFSZsF7    @b8NFuOq     ;Slv   sZEZSsjF0Nv               \n" 
"                    mbN7FOOqO;     .  sSF7               NmN#ZZZ.                \n" 
"                     zR8jZm8S:                            :7F0j                  \n" 
"                       vv  .                                                     \n" 
"                             FNF;      v7:         ;VF,                          \n" 
"                            Q@EFOv     s77.       vZFNqv.                        \n" 
"                            vmZFFF     ,77       ZFl;;N7                         \n"
"                              ;zZZz      ll    ,Ozl;:,:                          \n" 
"                                 vD0      S   :Ez7;::;                           \n" 
"                                  F8S         cZyv;;;                            \n" 
"                                    ,.         .,;v;                             \n" 
"                                                  .                              \n" 
 "                                                                                \n" 
"                                        .,,                                      \n" 
"                                         s0O                                     \n" 
"                                        7COv                                     \n" 
"                                       ;FI,                                      \n" 
"                                                                                 \n" 
"                                                                                 \n";
}
