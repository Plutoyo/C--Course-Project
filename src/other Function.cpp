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

long long CreateRand(long long Max,long long Min)//����������ĺ���
{
	default_random_engine t(time(NULL));
	srand(t()) ;//ͨ��ϵͳʱ���ʼ�����������//������������������,��ÿ��rand()��������ʼֵ��һ��.
	long long n ;
	n=(rand()+t())%(Max-Min+1)+Min ;// rand()Ϊ���������, ����[0,int�����ֵ)֮���������, ��ֵ��ϵͳ��ͬ����ͬ, һ��Ϊ2147483648, ����Ϊ����// ͨ��rand()%181+20ת��Ϊ[20,200]֮������� (ע:rand()%181����[0,180]֮�������)
	return n ; //�����������
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
