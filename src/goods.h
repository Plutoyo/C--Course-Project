#pragma once

class goods //大小固定,方便写入文件之中
{
	private:
		int price;
		int amount;
		char introduction[200];
		char goodsName[100];
		int sellerID;
		long long goodsID;
		int SoldAmount;
		static int Sum;
	public:
		goods *next;
		goods();
		~goods();
		int returnSum();
		void simplePrintGoodsInfo();
		void printGoodsInfo();
		void setPrice(int a);
		void setAmount(int a);
		void setGoodsName(char *p);
		void setIntroduction(char *p);
		void setSellerID(int a);
		char* showGoodsName();
		int showSellerID();
		int returnAmount();
		int showSoldAmount();
		long long showGoodsID();
		void soldOut();
		int showPrice();
};
