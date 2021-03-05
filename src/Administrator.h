#pragma once
class Administrator:public Person 
{
	public:
		void changeConsumer(buyerDataBase& Data,sellerDataBase& Data1);
		void changeSeller(sellerDataBase& Data,List& wareList);
		void deleteSeller(sellerDataBase& Data);
		void deleteConsumer(buyerDataBase& Data);
		void deleteGoods(List&Data);

};
