#pragma once
void LogIn(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,consumer *p1,seller *p2,List&wareList);
void BuyerLogInMenu(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,consumer *now,List&wareList);
void BuyersearchMenu(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,consumer *now,List&wareList);
void BuyerAd(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,consumer *now,List&wareList);
void BuyerRank(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,consumer *now,List&wareList);
void BuyerSelfInfo(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,consumer *now,List&wareList);
void showPurchasedGoods(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,consumer *now,List&wareList);
void BuyerMenu(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,consumer *now,List&wareList);
void SellerLogInMenu(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,seller *now,List&wareList);
void PutOnSale(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,seller *now,List&wareList);
void showPutOnSaleGoods(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,seller *now,List&wareList);
void SendGoodsSystem(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,seller *now,List&wareList);
void SellerSelfInfo(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,seller *now,List&wareList);
void SellerShowRank10(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,seller *now,List&wareList);
void SellerSoldGoods(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,seller *now,List&wareList);
void SellerMenu(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,seller *now,List&wareList);
void AdministratorMenu(sellerDataBase&SellerDataBase,buyerDataBase&BuyerDataBase,List&wareList);
void openingAnimation1();
