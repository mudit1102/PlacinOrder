#include"OrderBook.h"
#include"MarketPriceImpl.h"
using namespace std;

int main()
{
    MarketPriceImpl *mp = new MarketPriceImpl();

    string pId,oId;
    int t;
    cin>>t;
    while(t--)
    {
      int op;
      int type,price;
      cin>>op;
      //insert
      if(op == 1)
      {
        cin>>pId>>oId;
        cin>>type>>price;
        if(type == 1)
         cout<< mp->onOrderAdd(pId,oId,OrderType::BID,price)<<endl;
        else
          cout<< mp->onOrderAdd(pId,oId,OrderType::OFFER,price)<<endl;
      }
      else if(op==2)
      {
        cin>>pId>>oId;
         cout<<mp->onOrderDel(pId,oId)<<endl;
      }
      else
      {
        cout<<mp->print()<<endl;
      }
    }



    //mp->onOrderAdd("product2", "order3", 1, 99);
    return 0;
}
