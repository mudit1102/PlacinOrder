#ifndef MARKETPRICES_H_INCLUDED
#define MARKETPRICES_H_INCLUDED
#include "Order.h"
class MarketPrices{
  public:

    MarketPrices(){
    }

    virtual int onOrderAdd(string,string ,OrderType ,int ) = 0;
    virtual int onOrderDel(string,string) = 0;
    virtual int print()=0;



};

#endif // MARKETPRICES_H_INCLUDED
