#include "operations.h"
#include <string>
using namespace std;

class order : public operations
{
private:
  string dish;
  string temp2;
  int total, price;

public:
  void addOrder(string resturant_name, string dish, int price);
  bool IsPaid(bool checkout);
  void remove_from_cart(string resturant_name);
  int get_total();

};
