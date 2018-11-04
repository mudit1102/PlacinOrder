#ifndef MARKETPRICEIMPL_H_INCLUDED
#define MARKETPRICEIMPL_H_INCLUDED

#include "MarketPrices.h"
#include "OrderBook.h"

class MarketPriceImpl:public MarketPrices{

   map<string,OrderBook*> orderMap;
   public:
        int onOrderAdd(string pId,string oId,OrderType bidOrOffer,int price) ;
        int onOrderDel(string pId,string oId) ;
        int  print() ;

        //~MarketPriceImpl();

};
#endif // MARKETPRICEIMPL_H_INCLUDED
