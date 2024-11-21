#include "resturant.h"
#include "operations.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


// getting the name of the resturant

string resturant::get_resturant_name(){
	return name;	
}


// add new resturant

void resturant::add_res(string owner){
	fstream resfile("res_list.txt", ios::app | ios::in);
	cout<<"add new resturant\n";
	
	valid_data("res_list.txt", name, "name");
	this -> name = name;
	string file = name + ".txt";
	ofstream new_menu(file);
	
	cout<<"Enter resturant category: \n";	
	getline(cin >> ws, category);
	
	enter_valid_phone("res_list.txt");

	
	cout<<"Enter resturant address\n";
	getline(cin, address);
	
    resfile<<"- name: "<<name<<" - category: "<<category<<" - owner: "<<owner<<" - phone: "<<phone<<" - address: "<<address<<" - # -"<<endl;
    resfile.close();
    cout<<"resturant have been added\n";
}


// remove a resturant from the list only by the owner

void resturant::remove_res(){
	exist = false;
	cout<<"Enter the name of the resturant you want to remove:\n";
	getline(cin >> ws, name);
	fstream read("res_list.txt", ios::in | ios::out);
	if(read.fail())
		cout<<"Something went wrong try to add new resturant\n";
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
			cout<<"There is no such a resturant\n";
		else{
			if(start == 6){
				read.seekg(0, ios::beg);
				for(int i = start; i <= end + 1; i++)
					read<<" ";
				
			}else{
				read.seekg(start - 10, ios::beg);
				for(int i = start; i <= end + 2; i++)
					read<<" ";	
			}
			
			cout<<"Resturant have been removed successfully\n";
		}
	}
	read.close();
}

void resturant::remove_res(string name){
	access = false;
	exist = false;
	fstream read("res_list.txt", ios::in | ios::out);
	if(read.fail())
		cout<<"Something went wrong try to add new resturant\n";
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
			cout<<"There is no such a resturant\n";
		else{
			if(start == 6){
				read.seekg(0, ios::beg);
				for(int i = start; i <= end + 1; i++)
					read<<" ";
				
			}else{
				read.seekg(start - 10, ios::beg);
				for(int i = start; i <= end + 2; i++)
					read<<" ";	
			}		
		}
	}
	read.close();
}

 bool resturant::is_owner(string resturant_name, string owner){
	access = false;
	exist = false;
	fstream read("res_list.txt", ios::in | ios::out);
	if(read.fail())
		cout<<"Something went wrong try to add new resturant\n";
	else{
		while(!read.eof()){
			getline(read, temp, '-');
			if(temp == (" name: " + resturant_name + " ")){
				exist = true;
				while(temp != " # "){
					getline(read, temp, '-');
					if(temp == (" owner: " + owner + " "))
						access = true;
				}
			}	
		}
		if(!exist)
			cout<<"There is no such a resturant\n";
		else{
			if(!access){
				cout<<"You are not the owner of this resturant\n";
				return false;
			}
			else
				return true;
		}
	}
	read.close();
	return false;
 }


// updating resturant information

void resturant::update(string name)
{
	fstream read("res_list.txt", ios::in | ios::app);
	string ans, *res_data;
	res_data = search("res_list.txt", "resturant", name);

	resturant::remove_res(name);
	do
	{
		cout<<"Wich data do you want to update?\n";
		cout<<"1) name \t\t 2) category\n";
		cout<<"3) phone \t\t 4) address\n";
		cin>>ans;
		if((ans[0] != 49 && ans[0] != 50 && ans[0] != 51 && ans[0] != 52) || ans.empty() || ans.length() > 1)
			cout<<"Enter a valid option\n";
	} while ((ans[0] != 49 && ans[0] != 50 && ans[0] != 51 && ans[0] != 52) || ans.empty() || ans.length() > 1);

	if (ans[0] == 49){
		valid_data("res_list.txt", name, "name");
		res_data[0] = " name: " + name + " ";
	}
	else if (ans[0] == 50){
		getline(cin, category);
		res_data[1] = " category: " + category + " ";
	}
	else if (ans[0] == 51){
		enter_valid_phone("res_list.txt");
		res_data[3] = " phone: " + phone + " ";
	}
	else{
		valid_data("res_list.txt", address, "address");
		res_data[4] = " address: " + address + " ";
	}
	for (int i = 0; i < 5; i++)
		read<<"-"<<res_data[i];
	read<<"- # -";
	cout<<"Resturant have been updated successfully\n";
}