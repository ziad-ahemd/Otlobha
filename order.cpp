#include <fstream>
#include <iostream>
#include <string>
#include "order.h"
#include "operations.h"
using namespace std;

void order::addOrder(string resturant_name, string dish, int price) {
  ofstream output("order.txt", ios::app);

  if (!output.is_open()) {
    cerr << "Failed to open file.txt" << endl;
    return;
  }

  else {
    output<<"- Resturant name: " << resturant_name<< " - dish: " << dish<< " - price: " << price << " - # - " << endl;
  } 
  
}



bool order::IsPaid(bool checkout) {
  if (checkout == true) 
		ofstream remove("order.txt");
  else 
    exit(0);
  return checkout;
}


int order::get_total() {
  exist = false;
  total = 0;
	fstream read("order.txt", ios::in | ios::out);
	if(read.fail())
		cout<<"Something went wrong try to add new dish\n";
	else{
		while(!read.eof()){
			read>>temp;      
			if(temp == ("price:")){
				read>>price;
				total += price;        
			}	
		}
	}
	read.close();
  return total;
}

void order::remove_from_cart(string resturant_name){
  exist = false;
	cout<<"Enter the name of the dish you want to remove:\n";
	getline(cin >> ws, dish);
	fstream read("order.txt", ios::in | ios::out);
	if(read.fail())
		cout<<"Something went wrong try to add new dish\n";
	else{
		while(!read.eof()){
			getline(read, temp, '-');      
			if(temp == (" Resturant name: " + resturant_name + " ")){
				len = temp.length();
				start = read.tellg();
				start -= len - 2;
				while(temp != " # "){
					getline(read, temp, '-');
          if (temp == " dish: " + dish + " ")
            exist = true;
					end = read.tellg();
				}
        if (exist)
          break;
        
			}	
		}
		if(!exist)
			cout<<"There is no such a dish\n";
		else{
      cout<<start<<" "<<end<<endl;
			if(start <= 6){
				read.seekg(0, ios::beg);
				for(int i = start; i <= end + 3; i++)
					read<<" ";
				
			}else{
				read.seekg(start - 6, ios::beg);
				for(int i = start; i <= end + 6; i++)
					read<<" ";
			}
			
			cout<<"dish have been removed successfully\n";
		}
	}
	read.close();

}
