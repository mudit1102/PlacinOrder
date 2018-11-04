#include<bits/stdc++.h>
#include"Order.h"


string Order::getProductId(){
     return productId;
    }

string Order::getOrderId(){
     return orderId;
    }

OrderType Order::getOrderType() {
     return orderType;
    }

int Order::getPrice() const{
     return price;
    }
