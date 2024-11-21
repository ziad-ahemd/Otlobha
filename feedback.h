#include "operations.h"
#include <iostream>
#include <string>
using namespace std;

class feedback : public operations
{
private:
  string user_name;
  string resturant_name;
  string feedback;

public:
  void add_feedback(string user_name, string resturan_name);
};
