#include "payment.h"
#include "credit.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;


int payment::pay(string accout_name, int total){
    bool paied = false, access = false, dont_stop = true;
	exist = false;
    int start, i;
	cout<<"Choose credit by CVV:\n";
	getline(cin >> ws, credit_cvv);
    fstream read("credits.txt", ios::app | ios::in | ios::out);

	if(read.fail())
		cout<<"Something went wrong try to add new credit\n";
	else{
		while(!read.eof() && dont_stop){
			getline(read, temp, '-');
			if(temp == (" name: " + accout_name + " ")){
                access = true;
                data[0] = temp;
                getline(read, temp, '-');
                data[1] = temp;
                getline(read, temp, '-');
                if(temp == (" cvv: " + credit_cvv + " "))
                    exist = true;
                data[2] = temp;
                dont_stop = false;
                read>>temp;
                start = read.tellg();
                read>>balance;
                cout<<balance<<endl;
                if(balance < total){
                    cout<<"You don't have enogh balance\n";
                }
                else if(balance >= total){
                    remove_credit(accout_name, "12");
                    
                    read<<"\n-"<<data[0]<<"-"<<data[1]<<"-"<<data[2]<<"- balance: "<<balance - total<<" - # -";
                    cout<<"successfull payment\n";
                    return 1;
                }
			}	
		}
		if(!exist)
			cout<<"There is no such a credit\n";
		else
			if(!access)
				cout<<"You don't have the access to remove this credit\n";
	}
	read.close();
    return 0;
}
