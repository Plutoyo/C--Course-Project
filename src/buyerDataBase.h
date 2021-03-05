#pragma once
class buyerDataBase
{
	private:
		consumer *Head;
		consumer *Last;
	public:
		friend class Administrator;
		buyerDataBase();
		int showSum();
		void print();
		consumer* input();
		
		consumer* logIn(int a);

		consumer * searchBuyer(int a);

		void FileStore();
		void FlieLeadIn();
};

