#pragma once
class consumer;
class sellerDataBase;
class buyerDataBase;
class seller:public Person
{
	private: 
		long long SendGoods1[1000];//买家ID 
		long long SendGoods2[1000];//卖出的商品
		long long SendGoods3[1000];//快递单号 
		static int sellerSum;
		int Score; 
	public:
		friend class Administrator; 
		seller *next;
		seller();
		~seller();
		int returnSum();
		void putOnSale(List&catalogue);
		//传入特征ID,所以可以查询到每个商品的卖家 
		int ListAllGoods(List&catalogue);
		
		void Sell(consumer *point,long long wareID);
		
		void SendGoods(buyerDataBase&BuyerDataBase,List&catalogue); 
////与买家一样,卖家同时也可以搜索商品
		void search(List&catalogue,char *a);
		void empty();
		void increaseScore(int a);
		int returnScore();
		void showAllMerchandiseSold(List &wareList);
		void showSelfInfo();
};

