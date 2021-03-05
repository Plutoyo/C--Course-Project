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

//2019/4/7 开始程序设计课设 
//课设主题: 简单货物交易平台 
//
//2019/4/21 大致结束课程设计 
//测试账号
//	买家IDname=326107105; 密码1
//  卖家IDname=419719301; 密码1
//List类是每个卖家卖东西的清单 

//Person是卖家买家的基类
//卖家信息数据库
//储存所有卖家信息,并且在买家搜索商品信息时提供调用
//从而调用每个卖家的list,而获得商品的信息
//登录后返回卖家的指针,可以方便操作


//考虑改成双向链表来提高执行效率?
//买家继承至基类 有 姓名 年龄 地址 密码 地址 等变量
//能进行搜索所有卖家的商品清单,能够购买和对卖家进行评论 


//卖家可以对商品进行上架(即对list链表进行追加)
//同时对商品进行发货,调用时间增加的函数,估算到货时间
//卖家可以列出所有商品,并对自己的商品清单进行搜索
//后期增加对所有商品的搜索?
//需要增加对商品销量以及销售量的排行

//seller也是 sellerDataBase的节点

//买家信息数据库
//储存买家信息,并且可以注册成为新买家 

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
	cout<<"                   ----              欢迎进入nuaa购物系统                  ----               ";
	Sleep(2000);
	system("CLS");
	LogIn(SellerDataBase,BuyerDataBase,point1,point2,wareList);
	return 0;
}


