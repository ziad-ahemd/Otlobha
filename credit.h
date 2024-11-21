#ifndef credit_H
#define credit_H
#include <iostream>
#include "operations.h"
#include <string>
using namespace std;

class credit : public operations
{
private:
	string credit_name;
	string credit_num;
	string credit_cvv;
	long long int balance;

public:
	void enter_valid_number(string &data, string data_type);

	void add_credit(string accout_name, int balance);

	void remove_credit(string accout_name);
	void remove_credit(string accout_name, string credit_cvv);
};
#endif