#include "credit.h"
#include "operations.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;


// assigning credit's numbers after checking if it's valid

void credit::enter_valid_number(string &data, string data_type){
	fstream resfile("credits.txt", ios::app | ios::in);
	bool not_valid;
	int check = 0, size;
	do{
		not_valid = false;
		if(check)
			cout<<"This number is not valid or taken, try anthor one: \n";
		else
			check = 1;
		
		do
        {
	        cout<<"Enter credit's " + data_type + ": \n";
            getline(cin >> ws, data);
        } while (data.empty());
        
		resfile.seekg(0, ios::beg);
		while(!resfile.eof()){
			getline(resfile, temp, '-');
			if(temp == (" " + data_type + ": " + data + " "))
				not_valid = true;	
		}
        if (data_type == "number")
            size = 16;
        else if(data_type == "cvv")
            size = 3;
		
		for(int i = 0; i < data.length(); i++)
			if(data[i] < 48 || data[i] > 57 || data.length() != size)
				not_valid = true; 
	}while(not_valid);
}

// add credit

void credit::add_credit(string accout_name, int balance){
	fstream Accfile("credits.txt", ios::app | ios::in | ios::out);
	
	cout<<"add new credit\n";
	
    this -> credit_name = accout_name;

	credit::enter_valid_number(credit_num, "number");

	credit::enter_valid_number(credit_cvv, "cvv");

    Accfile<<"- name: "<<credit_name<<" - number: "<<credit_num<<" - cvv: "<<credit_cvv<<" - balance: "<<balance<<" - # -"<<endl;
    cout<<"credit have been added\n";
    Accfile.close();
}


// remove credit

void credit::remove_credit(string accout_name){
	bool access = false, dont_stop = true;
	exist = false;
	cout<<"Enter the cvv of the credit you want to remove:\n";
	getline(cin >> ws, credit_cvv);
	fstream read("credits.txt", ios::in | ios::out);
	if(read.fail())
		cout<<"Something went wrong try to add new credit\n";
	else{
        start = 0;
		while(!read.eof() && dont_stop){
            start = read.tellg();
			getline(read, temp, '-');
			if(temp == (" name: " + accout_name + " ")){
                access = true;
				s = temp + "\n";
				while(temp != " # "){
					getline(read, temp, '-');
					s += temp + "\n";
					if(temp == (" cvv: " + credit_cvv + " "))
						exist = true;
					end = read.tellg();
                    dont_stop = false;
				}
			}	
		}
		if(!exist)
			cout<<"There is no such a credit\n";
		else{
			if(!access)
				cout<<"You don't have the access to remove this credit\n";
			else{
				if (start <= 10)
					read.seekg(0, ios::beg);
				else
					read.seekg(start - 5, ios::beg);

				for(int i = start; i <= end + 1; i++)
					read<<" ";	
				
				cout<<"credit have been removed successfully\n";
			}
		}
	}
	read.close();
}

void credit::remove_credit(string accout_name, string credit_cvv){
	bool dont_stop = true;
	fstream read("credits.txt", ios::in | ios::out);
	if(read.fail())
		cout<<"Something went wrong try to add new credit\n";
	else{
        start = 0;
		while(!read.eof() && dont_stop){
            start = read.tellg();
			getline(read, temp, '-');
			if(temp == (" name: " + accout_name + " ")){
				while(temp != " # "){
					getline(read, temp, '-');
					end = read.tellg();
                    dont_stop = false;
				}
			}	
		}
		if (start <= 10)
			read.seekg(0, ios::beg);
		else
			read.seekg(start - 5, ios::beg);

		for(int i = start; i <= end + 1; i++)
			read<<" ";	
		
	}
	read.close();
}