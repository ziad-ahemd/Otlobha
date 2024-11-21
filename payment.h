#include <string>
#include "operations.h"
#include "credit.h"
using namespace std;

class payment :  public credit
{
private:
	string credit_name;
	string credit_cvv;
	long long int balance;

public:
	int pay(string accout_name, int total);
};
