#pragma once
class sellerDataBase
{
	private:
		seller *Head;
		seller *Last;
	public:
		friend class Administrator; 
		sellerDataBase();
		seller* returnSeller(int a);
		int showSum();
		void print();
		seller* input();
		seller* logIn(int a);
		void FileStore();
		void FlieLeadIn();
};
