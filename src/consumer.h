#pragma once
class consumer:public Person
{
	private:
		int level;
		static int consumerSum;
//		level 来表示买家的等级
	public:
		Date arrive[100];
		long long PurchasedGoods[100];
		long long deliver[100]; 
		consumer *next;
		consumer();
		~consumer();
		int returnSum();
		void search(List &wareList,long long *goodsList);
		
		void empty();
		
		void comment(seller* seller1);
		void buy(sellerDataBase &SellerDataBase,List &wareList,long long wareID);
		void showPurchasedGoods(List &wareList);
		void showBuyerInfo();
		void showSelfInfo();
		void showLevel();
		friend class buyerDataBase;
		friend void seller::SendGoods(buyerDataBase&BuyerDataBase,List&catalogue);
};

