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
#include "menu.h"
using namespace std;

//2019/4/7 ��ʼ������ƿ��� 
//��������: �򵥻��ｻ��ƽ̨ 
//
//2019/4/21 ���½����γ���� 
//�����˺�
//	���IDname=326107105; ����1
//  ����IDname=419719301; ����1
//List����ÿ���������������嵥 

//Person��������ҵĻ���
//������Ϣ���ݿ�
//��������������Ϣ,���������������Ʒ��Ϣʱ�ṩ����
//�Ӷ�����ÿ�����ҵ�list,�������Ʒ����Ϣ
//��¼�󷵻����ҵ�ָ��,���Է������


//���Ǹĳ�˫�����������ִ��Ч��?
//��Ҽ̳������� �� ���� ���� ��ַ ���� ��ַ �ȱ���
//�ܽ��������������ҵ���Ʒ�嵥,�ܹ�����Ͷ����ҽ������� 


//���ҿ��Զ���Ʒ�����ϼ�(����list�������׷��)
//ͬʱ����Ʒ���з���,����ʱ�����ӵĺ���,���㵽��ʱ��
//���ҿ����г�������Ʒ,�����Լ�����Ʒ�嵥��������
//�������Ӷ�������Ʒ������?
//��Ҫ���Ӷ���Ʒ�����Լ�������������

//sellerҲ�� sellerDataBase�Ľڵ�

//�����Ϣ���ݿ�
//���������Ϣ,���ҿ���ע���Ϊ����� 

int main()
{
	int order;
	consumer *point1=nullptr;
	seller *point2=nullptr;
	List wareList;
	sellerDataBase SellerDataBase;
	buyerDataBase BuyerDataBase;
	openingAnimation1();
	Sleep(1500);
	system("CLS"); 
	cout<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n";
	cout<<"                   ----              ��ӭ����nuaa����ϵͳ                  ----               ";
	Sleep(2000);
	system("CLS");
	LogIn(SellerDataBase,BuyerDataBase,point1,point2,wareList);
	return 0;
}


