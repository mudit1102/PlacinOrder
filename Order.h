#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED
#include<bits/stdc++.h>
using namespace std;

enum OrderType{ BID=1,OFFER,INVALID};

class Order{

 private:
 string productId;
 string orderId;
 OrderType orderType;
 int price;

 public:
    Order():Order(NULL,NULL){
    }

    Order(string pId,string oId,OrderType type = OrderType::INVALID,int amt = 0):productId(pId),orderId(oId),orderType(type),price(amt){
    }
    string getProductId();
    string getOrderId();
    OrderType getOrderType();
    int getPrice() const;
    void display(){
     cout<<productId<<" "<<orderId<<" "<<orderType<<" "<<price<<endl;
    }
};


#endif // ORDER_H_INCLUDED
