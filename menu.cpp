#include "menu.h"
#include "resturant.h"
#include "operations.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


// returning dish name

string menu::get_dish_name(){
	return dish_name;
}


// add new dish

void menu::add_to_menu(string resturant_name){
	bool valid = true;
	file = resturant_name + ".txt";
	fstream resfile(file, ios::app | ios::in);
	
	cout<<"add new dish\n";
	
	menu::valid_data(resturant_name, dish_name, "dish name");
	
	
	cout<<"Enter dish discription: \n";	
	getline(cin >> ws, dish_discription);

    do{
        cout<<"Enter dish category: \n";	
        getline(cin >> ws, dish_category);
    }while(dish_category.empty());

	do{
        cout<<"Enter dish price: \n";	
        getline(cin >> ws, price);
		for (int i = 0; i < price.length(); i++)
			if (price[i] < 48 || price[i] > 57)
				valid = false;
    }while(!valid || price.empty());
	
   resfile<<"- name: "<<dish_name<<" - category: "<<dish_category<<" - discription: "<<dish_discription<<" - price: "<<price<<" - # -"<<endl;
   resfile.close();
   cout<<"dish have been added\n";
}


// remove a dish from the list only by the owner

void menu::remove_from_menu(string resturant_name){
	exist = false;
	cout<<"Enter the name of the dish you want to remove:\n";
	getline(cin >> ws, dish_name);
    file = resturant_name + ".txt";
	fstream read(file, ios::in | ios::out);
	if(read.fail())
		cout<<"Something went wrong try to add new dish\n";
	else{
		while(!read.eof()){
			getline(read, temp, '-');
			if(temp == (" name: " + dish_name + " ")){
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
			cout<<"There is no such a dish\n";
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
            
            cout<<"dish have been removed successfully\n";
		}
	}
	read.close();
}

int menu::get_dish(string resturant_name, string dish_name){
	exist = false;
	string s;
	int i = 0;
    file = resturant_name + ".txt";
    fstream read(file, ios::in);
	if(read.fail())
		cout<<"Something went wrong try to add new dish\n";
	else{
		while(!read.eof()){
			getline(read, temp, '-');
			if(temp == (" name: " + dish_name + " ")){
				exist = true;
				do
				{
					read>>temp;
				} while (temp != "price:");
				read>>price;
				i = stoi(price);
				return i;
			}	
		}
		if(!exist)
			cout<<"There is no such a dish\n";
	}
	read.close();
	return i;
}