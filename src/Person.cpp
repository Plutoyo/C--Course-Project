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
Person::Person(char *p1,int t1,char *p2,int t2)
{
	age=0;
	strcpy(name,p1);
	strcpy(address,p2);
	account=0;
	password=0;
	ID=CreateRand(999999999,100000000);
}
Person::Person()
{
	age=0;
	account=0;
	ID=CreateRand(999999999,100000000); 
}

void Person::setID(int ID)
{
	this->ID=ID;
}
void Person::setName(char *p1)
{
	strcpy(name,p1);
}
void Person::setAge(int a)
{
	age=a; 
} 
void Person::setAccount(int a)
{
	account=a;
}
void Person::setAddress(char *p2)
{
	strcpy(address,p2);
}
void Person::setpassword(int a)
{
	password=a;
}
char* Person::showName()
{
	return name; 
}
char* Person::showAddress()
{
	return address; 
}
int Person::showPassword()
{
	return password;
}
int Person::showID()
{
	return ID;
}
void Person::increaseAccount(int a)
{
	account+=a; 
}

void Person::decreaseAccount(int a)
{
	account-=a; 
} 

int Person::returnAccount()
{
	return account; 
}
