#pragma once

class goods //��С�̶�,����д���ļ�֮��
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
