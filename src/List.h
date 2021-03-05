#pragma once
class List
{
	private:
		goods *Head;
		goods *Last;
	public:
		friend class Administrator;
		List();
		int returnSum();
// 上架需传入卖家的ID,来加入list的链表之中 
		goods* input(int sellerID);

//列出所有商品信息
		void print();
		
		void advice(long long *adList);
//根据部分信息(是否是子串)来展示相关信息
//暂时还未实现
		void search(char *a,long long *goodsList);
		
		void search(char *a);
		
		void search(long long GoodsID);
		
		char * returnRandomGoodsName(); 
		
		int searchSeller(int sellerID);
		
		char * returnName(long long wareID);

//商品购买功能需要完善 
//
		void ChangeSingleSellerGoodsInfo(int sellerID,int t);
		
		int returnSellerID(long long wareID);

		int sell(long long wareID);
		
		goods*  pSkip(goods *p,int a);
		
		void RankSeller();
		
		goods* returnGoodsPoint(long long wareID); 
		
		void showRank10Goods(long long *adList);
		
		void showRank10Goods(int sellerID);
		
		int returnPrice(long long wareID);
		
		void FileStore();
		void FlieLeadIn();
}; 
