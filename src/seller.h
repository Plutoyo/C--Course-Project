#pragma once
class consumer;
class sellerDataBase;
class buyerDataBase;
class seller:public Person
{
	private: 
		long long SendGoods1[1000];//���ID 
		long long SendGoods2[1000];//��������Ʒ
		long long SendGoods3[1000];//��ݵ��� 
		static int sellerSum;
		int Score; 
	public:
		friend class Administrator; 
		seller *next;
		seller();
		~seller();
		int returnSum();
		void putOnSale(List&catalogue);
		//��������ID,���Կ��Բ�ѯ��ÿ����Ʒ������ 
		int ListAllGoods(List&catalogue);
		
		void Sell(consumer *point,long long wareID);
		
		void SendGoods(buyerDataBase&BuyerDataBase,List&catalogue); 
////�����һ��,����ͬʱҲ����������Ʒ
		void search(List&catalogue,char *a);
		void empty();
		void increaseScore(int a);
		int returnScore();
		void showAllMerchandiseSold(List &wareList);
		void showSelfInfo();
};

