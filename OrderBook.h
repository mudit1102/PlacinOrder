#ifndef ORDERBOOK_H_INCLUDED
#define ORDERBOOK_H_INCLUDED
#include"Order.h"

class OrderBook{

  map< string,Order*> offers;
  map< string,Order*> bids;

  int addOffer(Order* order){
     if(order->getOrderType() != OrderType::OFFER || order->getPrice() < 0)
         return 0;
        string str = order->getOrderId();
        offers[str] = order;
        return 1;
  }

  int addBids(Order* order){

   if(order->getOrderType() != OrderType::BID || order->getPrice() < 0)
      return 0;


      string str = order->getOrderId();

      bids[str] = order;


      return 1;
  }

  int deleteBids(Order* order){

      string str = order->getOrderId();
      bids.erase(str);
      return 1;
  }

  int deleteOffers(Order* order){

      string str = order->getOrderId();
      offers.erase(str);
      return 1;
  }

  public:

  OrderBook(){

  }

  bool mapsSize();
  int addOrder(Order* order);
  int deleteOrder(Order* order);
  void printOffers();
  void printBids();


};


#endif // ORDERBOOK_H_INCLUDED
