#pragma once
class Person{
	protected:
		char name[20];
		int age;
		char address[200];//修改后为固定值,方便写入文件之中
		int account;
		int password;
		int ID;
	public:
		friend class Administrator; 
		Person(char *p1,int t1,char *p2,int t2);
		Person();
		void setName(char *p1);
		void setAge(int a);
		void setAccount(int a);
		void setAddress(char *p2);
		void setpassword(int a);
		void setID(int ID);
		char* showName();
		char* showAddress();
		int showPassword();
		int showID();
		void increaseAccount(int a);
		void decreaseAccount(int a);
		int returnAccount();
};
