#ifndef operations_H
#define operations_H
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class operations
{
public:
    string name;
    string address;
    string phone;
    string category;
    string credit_name;
    string credit_cvv;
    string data[5];
    string temp;
    string s;
    bool exist;
    bool access;
    int start;
    int end;
    int len;

    void valid_data(string file, string &data, string data_type);
    void enter_valid_phone(string file);


    string search(string file, string data_type);
    string* search(string file, string data_type, string name);

	void list(string file);
    void filter(string file);

    string get_name(); 
};
#endif