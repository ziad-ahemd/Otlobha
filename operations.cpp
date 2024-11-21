#include "operations.h"
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


// assigning data after checking that there is no record with the same data

void operations::valid_data(string file, string &data, string data_type){
	fstream read(file, ios::app | ios::in);
	exist = true;
	while(exist){	
		exist = false;
		read.seekg(0, ios::beg);
		cout<<"Enter "<<data_type<<":\n";
		getline(cin >> ws, data);
        
		while(!read.eof()){
			getline(read, temp, '-');
			if(temp == (" " + data_type + ": " + data + " ")){
				exist = true;	
				cout<<"This " + data_type + " is invalid or doublicated\n";
				
			}
		}
	}

  read.close();
}


// checking for valid phone number

void operations::enter_valid_phone(string file){
	fstream read(file, ios::app | ios::in);
	bool not_valid;
	int check = 0;
	cout<<"Enter phone: \n";
	do{
		not_valid = false;
		if(check)
			cout<<"This number is not valid or taken, try anthor one: \n";
		else
			check = 1;
		
		
		getline(cin >> ws, phone);
		read.seekg(0, ios::beg);
		while(!read.eof()){
			getline(read, temp, '-');
			if(temp == (" phone: " + phone + " "))
				not_valid = true;	
		}
		
		
		for(int i = 0; i < phone.length(); i++)
			if(phone[i] < 48 || phone[i] > 57 || phone.length() != 11 || phone[0] != 48 || phone[1] != 49 || (phone[2] > 50 && phone[2] < 53)
			|| phone[2] > 53)
				not_valid = true; 
	}while(not_valid);

    read.close();
}


// showing the list

void operations::list(string file){
	ifstream read(file);
	if(read.fail())
		cout<<"Something went wrong\n";
	else
		while(!read.eof()){	
			getline(read, temp, '-');
			if(temp == " # ")
				cout<<endl;
			else
				cout<<temp<<endl;
		}

	read.close();
}


// search for a resturant by name

string operations::search(string file, string data_type){
	exist = false;
	cout<<"Enter the name of the " + data_type + " you want to search for:\n";
	getline(cin >> ws, name);
	ifstream read(file);
	if(read.fail())
		cout<<"Something went wrong\n";
	else{
		while(!read.eof()){
			getline(read, temp, '-');
			if(temp == (" name: " + name + " ")){
				exist = true;
				this -> name = name;
				s = temp + "\n";
				getline(read, temp, '-');
				while(temp != " # "){
					s += temp + "\n";
					getline(read, temp, '-');
				}
				return s;
			}	
		}
		if(!exist)
			cout<<data_type + " not found\n";
			
	}
	read.close();
	return "";
}


string* operations::search(string file, string data_type, string name){
	exist = false;
	string non = "", *pnon = &non;
	
	int cnt = 1;
	ifstream read(file);
	if(read.fail())
		cout<<"Something went wrong\n";
	else{
		while(!read.eof()){
			getline(read, temp, '-');
			if(temp == (" name: " + name + " ")){
				exist = true;
				this -> name = name;
				data[0] = temp;
				for (int i = 1; i <= 4; i++)
				{
					getline(read, temp, '-');
					data[i] = temp;
				}
				
				return data;
			}	
			
		}
		if(!exist){
			cout<<data_type + " not found\n";
			return pnon;
		}
	}
	read.close();
	return pnon;
}


string operations::get_name(){
	return name;
}

// filtering records by category

void operations::filter(string file){
	exist = false;
	cout<<"Enter category:\n";
	getline(cin >> ws, category);
	ifstream read(file);
	if(read.fail())
		cout<<"Something went wrong\n";
	else{
		while(!read.eof()){
			read>>temp;
			if(temp == "name:"){
				start = read.tellg();
				if (file == "res_list.txt")
					start -= 13;
				else
					start -= 6;
				getline(read, temp, '-');
				getline(read, temp, '-');
				if(temp == (" category: " + category + " ")){
					exist = true;
					read.seekg(start, ios::beg);
					getline(read, temp, '-');
					cout<<temp<<endl;
					while(temp != " # "){
						getline(read, temp, '-');
						if(temp == " # ")
							cout<<endl;
						else
							cout<<temp<<endl;
					}
				}
			}
		}
		if(!exist)
			cout<<"There is no such a category\n";
	}
	read.close();
}
