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
// �ϼ��贫�����ҵ�ID,������list������֮�� 
		goods* input(int sellerID);

//�г�������Ʒ��Ϣ
		void print();
		
		void advice(long long *adList);
//���ݲ�����Ϣ(�Ƿ����Ӵ�)��չʾ�����Ϣ
//��ʱ��δʵ��
		void search(char *a,long long *goodsList);
		
		void search(char *a);
		
		void search(long long GoodsID);
		
		char * returnRandomGoodsName(); 
		
		int searchSeller(int sellerID);
		
		char * returnName(long long wareID);

//��Ʒ��������Ҫ���� 
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
