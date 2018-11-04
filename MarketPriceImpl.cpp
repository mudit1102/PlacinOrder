#include"MarketPriceImpl.h"

int MarketPriceImpl::onOrderAdd(string pId,string oId,OrderType bidOrOffer,int price){
           string productId(pId);
           Order *order = new Order(pId,oId,bidOrOffer,price);
           OrderBook *obook = NULL;

           if(orderMap.find(productId) == orderMap.end())
             {
                 obook = new OrderBook();
                 orderMap[productId] = obook;

             }
            else
                {
                  obook = orderMap[productId];

                }

            if(obook->addOrder(order) == 0)
                return 0;

            orderMap[productId] = obook;
            return 1;
        }

int MarketPriceImpl::onOrderDel(string pId,string oId){

           string productId(pId);
            if(orderMap.find(productId) == orderMap.end())
             return 0;

           Order  order(pId,oId);
           OrderBook *obook = orderMap[productId];
           if(obook->deleteOrder(&order) == 0)
              return 0;

           if(obook->mapsSize())
            orderMap.erase(productId);
          else
           orderMap[productId] = obook;

           return 1;
       }

int MarketPriceImpl::print(){
          if(orderMap.size() == 0)
             return 0;
          map<string,OrderBook*>::iterator it;
          for(it=orderMap.begin();it!=orderMap.end();it++){
            OrderBook *obook = NULL;
            cout<<it->first<<":"<<endl;
            cout<<"Buy:"<<endl;
            obook = it->second;
            obook->printBids();
            cout<<"Sell:"<<endl;
            obook->printOffers();
    }
    return 1;
}
/*
MarketPriceImpl::~MarketPriceImpl(){
   cout<<"Destrcutor "<<endl;
} */
