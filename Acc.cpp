#include "Acc.h"
#include "operations.h"
#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<fstream>

int Acc::acc_type = 1;
// log in 
bool Acc::Log_In() {
    string input_username, input_password;
    bool username_found = false;

 
    ifstream read("Acc_list.txt");
    if (read.fail()) {
        cout << "Error accessing account database. Please try again later." << endl;
        return false;
    }


    cout << "Enter your username: \n";
    getline(cin >> ws, input_username);

    bool password_matched = false;
    while (!read.eof()) {
        getline(read, temp, '-');
        if (temp == (" name: " + input_username + " ")) {
            username_found = true;
            cout << "Enter your password: \n";
            cin >> input_password;
            getline(read, temp, '-'); 
            if (temp == (" password: " + input_password + " ")) {
                password_matched = true;
                this -> name = input_username;
				do
				{
					read>>temp;
				} while (temp != "Acctype:");
				getline(read, temp, '-');
				AccType = temp;
				if (AccType == " Restaurant Owner ")
					acc_type = 2;
				else
					acc_type = 1;
				
                break;
            }
        }
    }

    if (!username_found) {
        cout << "Username not found. Please try again." << endl;
        return false;
    }

    if (!password_matched) {
        cout << "Incorrect password. Please try again." << endl;
        return false;
    }

    cout << "Login successful! Welcome, " << input_username << "!" << endl;
    read.close();
    return true;
}


// add new Account
void Acc::add_Acc(){
	fstream Accfile("Acc_list.txt", ios::app | ios::in | ios::out);
	
	cout<<"add new account\n";
	
          valid_data("Acc_list.txt", name, "name");
		  this -> name = name;	
	
	 do {
	 	cout<<"Enter account's password:\n";
        cin>>Password;
        if (Password.length() < 6)
            cout << "Password must be at least 6 characters long. Please try again: \n";
    } while (Password.length() < 6);

	do
	{
		cout<<"Enter address:\n";
		getline(cin >> ws, address);
	} while (address.empty());
	

	enter_valid_phone("Acc_list.txt");

	string type_op;

    do
    {
        cout << "Choose account type:\n1. Customer\n2. Restaurant Owner\n";
        cin>>type_op;
        if((type_op[0] != 49 && type_op[0] != 50) || type_op.empty() || type_op.length() > 1)
            cout<<"Enter a valid option\n";
    } while ((type_op[0] != 49 && type_op[0] != 50) || type_op.empty() || type_op.length() > 1);


    if (type_op[0] == 49){
        AccType="Customer";
		acc_type = 1;
	}
    else if(type_op[0] == 50){
        AccType="Restaurant Owner";
		acc_type = 2;
	}

	
 

    Accfile<<"- name: "<<name<<" - password: "<<Password<<" - Acctype: "<<AccType<<" - phone: "<<phone<<" - address: "<<address<<" - # - "<<endl;
    Accfile.close();
    cout<<"Account have been added\n";
}

int Acc::return_acc_type(){
	return acc_type;
}


// remove
void Acc::remove_Acc() {
	exist = false;
	cout<<"Enter the name of the account you want to remove:\n";
	getline(cin >> ws, name);
	fstream read("Acc_list.txt", ios::in | ios::out);
	if(read.fail())
		cout<<"Something went wrong try to add new account\n";
	else{
		while(!read.eof()){
			getline(read, temp, '-');
			if(temp == (" name: " + name + " ")){
				exist = true;
				len = temp.length();
				start = read.tellg();
				start -= len;
				while(temp != " # "){
					getline(read, temp, '-');
					end = read.tellg();
				}
			}	
		}
		if(!exist)
			cout<<"There is no such an account\n";
		else{
			if(start == 4){
				start = 6;
				end++;
			}
			read.seekg(start - 6, ios::beg);
			for(int i = start; i <= end + 2; i++)
				read<<" ";	                
            cout<<"account have been removed successfully\n";
		}
	}
	read.close();
}

void Acc::remove_Acc(string name){
	access = false;
	exist = false;
	fstream read("Acc_list.txt", ios::in | ios::out);
	if(read.fail())
		cout<<"Something went wrong try to add new account\n";
	else{
		while(!read.eof()){
			getline(read, temp, '-');
			if(temp == (" name: " + name + " ")){
				exist = true;
				len = temp.length();
				start = read.tellg();
				start -= len;
				s = temp + "\n";
				while(temp != " # "){
					getline(read, temp, '-');
					s += temp + "\n";
					end = read.tellg();
				}
			}	
		}
		if(!exist)
			cout<<"There is no such an account\n";
		else{
			if(start == 4){
				start = 6;
				end++;
			}
			read.seekg(start - 6, ios::beg);
			for(int i = start; i <= end + 2; i++)
				read<<" ";	
		}
	}
	read.close();
}


string Acc::get_acc_type(){
    return AccType;
}

string Acc::get_name(){
    return name;
}

 void Acc::update(string name)
 {
	fstream read("Acc_list.txt", ios::in | ios::app);
	string ans, *acc_data;
	acc_data = search("Acc_list.txt", "account", name);
	Acc::remove_Acc(name);
	do
	{
		cout<<"Wich data do you want to update?\n";
		cout<<"1) name         \t\t 2) password\n";
		cout<<"3) account type \t\t 4) phone\n";
		cout<<"5) address\n";
		cin>>ans;
		if((ans[0] != 49 && ans[0] != 50 && ans[0] != 51 && ans[0] != 52 && ans[0] != 53) || ans.empty() || ans.length() > 1)
			cout<<"Enter a valid option\n";
	} while ((ans[0] != 49 && ans[0] != 50 && ans[0] != 51 && ans[0] != 52 && ans[0] != 53) || ans.empty() || ans.length() > 1);

	if (ans[0] == 49){
		valid_data("Acc_list.txt", name, "name");
		acc_data[0] = " name: " + name + " ";
	}
	else if (ans[0] == 50){
		do {
	 	cout<<"Enter account's password:\n";
        cin>>Password;
        if (Password.length() < 6)
            cout << "Password must be at least 6 characters long. Please try again: \n";
    	} while (Password.length() < 6);
    	acc_data[1] = " password: " + Password + " ";
	}
	else if (ans[0] == 51){
		string type_op;
		do
	    {
	        cout << "Choose account type:\n1. Customer\n2. Restaurant Owner\n";
	        cin>>type_op;
	        if((type_op[0] != 49 && type_op[0] != 50) || type_op.empty() || type_op.length() > 1)
	            cout<<"Enter a valid option\n";
	    } while ((type_op[0] != 49 && type_op[0] != 50) || type_op.empty() || type_op.length() > 1);
	
	
	    if (type_op[0] == 49){
	        AccType="Customer";
			acc_type = 1;
		}
	    else if(type_op[0] == 50){
	        AccType="Restaurant Owner";
			acc_type = 2;
		}
	        
		acc_data[2] = " Acctype: " + AccType + " ";
	}
	else if(ans[0] == 52){	
		enter_valid_phone("Acc_list.txt");
		acc_data[3] = " phone: " + phone + " ";
	}else{
		do
		{
			cout<<"Enter address:\n";
			getline(cin  >> ws, address);
		} while (address.empty());
		acc_data[4] = " address: " + address + " ";
	}
	
	for (int i = 0; i < 5; i++)
		read<<"-"<<acc_data[i];
	read<<"- # - ";

	cout<<"Account have been updated successfully\n";
 }