#include"OrderBook.h"

       int OrderBook::addOrder(Order* order){


        if(order->getOrderType() == OrderType::BID)
        {
            return addBids(order);
        }
        else if(order->getOrderType() == OrderType::OFFER)
        {
            return addOffer(order);
        }
        else
             return 0;
      }

      int OrderBook::deleteOrder(Order* order){
        if(offers.find(order->getOrderId()) != offers.end())
          return deleteOffers(order);
        else if(bids.find(order->getOrderId()) != bids.end())
         return deleteBids(order);
        else
         return 0;

      }

  void OrderBook::printOffers(){

   typedef std::function<bool(std::pair<std::string, Order*>, std::pair<std::string, Order*>)> Comparator;

    Comparator compFunctor =
			[](std::pair<std::string, Order*> elem1 ,std::pair<std::string, Order*> elem2)
			{
        Order* od1 = elem1.second;
        Order* od2 = elem2.second;
				return od1->getPrice() < od2->getPrice();
			};

     std::set<std::pair<std::string, Order*>, Comparator> setOfWords(
			offers.begin(), offers.end(), compFunctor);

      for (std::pair<std::string, Order*> element : setOfWords)
		  {

       cout<<element.first<<" "<<(element.second)->getPrice()<<endl;
      }


  }
  void OrderBook::printBids(){


     typedef std::function<bool(std::pair<std::string, Order*>, std::pair<std::string, Order*>)> Comparator;

    Comparator compFunctor =
			[](std::pair<std::string, Order*> elem1 ,std::pair<std::string, Order*> elem2)
			{
        Order* od1 = elem1.second;
        Order* od2 = elem2.second;
				return od1->getPrice() > od2->getPrice();
			};

     std::set<std::pair<std::string, Order*>, Comparator> setOfWords(
			bids.begin(), bids.end(), compFunctor);

      for (std::pair<std::string, Order*> element : setOfWords)
		  {

       cout<<element.first<<" "<<(element.second)->getPrice()<<endl;
      }
  }

  bool OrderBook::mapsSize(){
   if(offers.size() == 0 && bids.size() == 0)
     return true;

    return false;
  }
