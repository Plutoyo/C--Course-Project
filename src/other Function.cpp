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

long long CreateRand(long long Max,long long Min)//产生随机数的函数
{
	default_random_engine t(time(NULL));
	srand(t()) ;//通过系统时间初始化随机数种子//如果不设置随机数种子,则每次rand()函数的起始值都一样.
	long long n ;
	n=(rand()+t())%(Max-Min+1)+Min ;// rand()为随机数函数, 产生[0,int型最大值)之间的整数数, 此值依系统不同而不同, 一般为2147483648, 可认为无穷// 通过rand()%181+20转化为[20,200]之间的整数 (注:rand()%181产生[0,180]之间的整数)
	return n ; //返回这个整数
}

int isStr(char *a,char *str)
{
	int i,k=0,isString=0;
	for(i=0;i<strlen(str);i++)
	{
		if(a[k]==str[i])
		{
			if(strlen(a)==1) return isString=1;
			for(k=1;k<strlen(a);k++)
			{
				i++;
				if(a[k]!=str[i])
				{
					break;
					k=0;
				}
				return isString=1;
			}
		}
	}
	return 0;
}
