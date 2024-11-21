#include <iostream>
#include <bits/stdc++.h>
#include "Acc.h"
#include "operations.h"
#include "resturant.h"
#include "menu.h"
#include "order.h"
#include "credit.h"
#include "payment.h"
#include "feedback.h"
using namespace std;

void common_menu();
void resturant_menu();
void menues_menu(string resturant_name);
void order_menu(string resturant_name);
void owners_res_menu();
void owner_menues_menu(string resturant_name);


string user_name, resturant_name;
int acc_type;

// Authenticating the user

void main_menu(){
	Acc a;
	credit c;
	string ans;
	do
	{
		cout<<"\n=============================\n";
		cout<<"1) login \t\t 2) create account\n";
		cin>>ans;
		if((ans[0] != 49 && ans[0] != 50) || ans.empty() || ans.length() > 1)
			cout<<"Enter a valid option\n";
	} while ((ans[0] != 49 && ans[0] != 50) || ans.empty() || ans.length() > 1);
	if (ans[0] == 49){
		int flag = a.Log_In();
		while(!flag)
			main_menu();
	}
	else
		a.add_Acc();

	user_name = a.get_name();
	common_menu();
}


// profile page

void common_menu(){
	Acc a;
	credit c;
	string ans;
	acc_type = a.return_acc_type();

	do
	{
		cout<<"\n=====================================\n";
		cout<<"1) update accout \t\t 2) remove account\n";
		cout<<"3) logout        \t\t 4) resturants\n";
		cout<<"5) add credit    \t\t 6) remove credit\n";
		
		cin>>ans;
		if((ans[0] < 49 || ans[0] > 54) || ans.empty() || ans.length() > 1)
			cout<<"Enter a valid option\n";
	} while ((ans[0] < 49 || ans[0] > 54) || ans.empty() || ans.length() > 1);
	if(ans[0] == 49){
		a.update(user_name);
		common_menu();
	}
	else if(ans[0] == 50){
		a.remove_Acc(user_name);
		main_menu();
	}
	else if (ans[0] == 51){
		main_menu();
	}
	else if(ans[0] == 52){
		if(acc_type == 1){
			resturant_menu();
		}
		else if(acc_type == 2){
			owners_res_menu();
		}
	}
	else if(ans[0] == 53){
		c.add_credit(user_name, 500);
		common_menu();
	}
	else if(ans[0] == 54){
		c.remove_credit(user_name);
		common_menu();
	}
}


// resturant page

void resturant_menu(){
	resturant r;
	string ans, check;
	do
	{
		cout<<"\n===================================================\n";
		cout<<"1) show resturant list \t\t 2) search for a resturant\n";
		cout<<"3) filter resturants   \t\t 4) choose resturant\n";
		cout<<"5) previous\n";
		cin>>ans;
		if((ans[0] < 49 || ans[0] > 53) || ans.empty() || ans.length() > 1)
			cout<<"Enter a valid option\n";
	} while ((ans[0] < 49 || ans[0] > 53) || ans.empty() || ans.length() > 1);
	if (ans[0] == 49){
		r.list("res_list.txt");
		resturant_menu();
	}
	else if(ans[0] == 50){
		check = r.search("res_list.txt", "resturant");
		resturant_name = r.get_resturant_name();
		cout<<check;
		if (check.empty())
			resturant_menu();
		else{
			do
			{
				cout<<"\n----------------------------------\n";
				cout<<"1) choose resturant \t\t 2) previous\n";
				cin>>ans;
				if((ans[0] != 49 && ans[0] != 50) || ans.empty() || ans.length() > 1)
					cout<<"Enter a valid option\n";
			} while ((ans[0] != 49 && ans[0] != 50) || ans.empty() || ans.length() > 1);
			if (ans[0] == 49)
				menues_menu(resturant_name);
			else
				resturant_menu();
		}
		
	}
	else if(ans[0] == 51){
		r.filter("res_list.txt");
		resturant_menu();
	}
	else if(ans[0] == 52){
		string resturant_name, *temp;

		cout<<"Enter the name of the resturant: \n";
		getline(cin >> ws, resturant_name);
		temp = r.search("res_list.txt", "resturant", resturant_name);
		if(*temp == "")
			resturant_menu();
		
		menues_menu(resturant_name);
	}
	else
		common_menu();
}


// menu page

void menues_menu(string resturant_name){
	resturant r;
	menu m;
	order o;
	string ans, check;
	do
	{
		cout<<"\n=====================================\n";
		cout<<"1) show menu   \t\t   2) search in menu\n";
		cout<<"3) filter menu \t\t   4) go to cart\n";
		cout<<"5) previous\n";
		cin>>ans;
		if((ans[0] < 49 || ans[0] > 53) || ans.empty() || ans.length() > 1)
			cout<<"Enter a valid option\n";
	} while ((ans[0] < 49 || ans[0] > 53) || ans.empty() || ans.length() > 1);
	if (ans[0] == 49){
		m.list(resturant_name + ".txt");
		menues_menu(resturant_name);
	}
	else if(ans[0] == 50){
		check = m.search(resturant_name + ".txt", "dish");
		cout<<check;
		if (check.empty())
			menues_menu(resturant_name);
		else{
			do
			{
				cout<<"\n-----------------------------\n";
				cout<<"1) add to cart \t\t 2) previous\n";
				cin>>ans;
				if((ans[0] != 49 && ans[0] != 50) || ans.empty() || ans.length() > 1)
					cout<<"Enter a valid option\n";
			} while ((ans[0] != 49 && ans[0] != 50) || ans.empty() || ans.length() > 1);
			if (ans[0] == 49){
				o.addOrder(resturant_name, m.get_name(), m.get_dish(resturant_name, m.get_name()));
				menues_menu(resturant_name);
			}
			else
				menues_menu(resturant_name);
		}
	}
	else if(ans[0] == 51){
		m.filter(resturant_name + ".txt");
		menues_menu(resturant_name);
	}
	else if(ans[0] == 52)
		order_menu(resturant_name);
	else
		resturant_menu();
}


// finishing order and preceed to payment

void order_menu(string resturant_name){
	resturant r;
	Acc a;
	feedback f;
	menu m;
	payment p;
	order o;
	string ans;
	do
	{
		cout<<"\n==========================================\n";
		cout<<"1) show cart     \t\t    2) remove from cart\n";
		cout<<"3) pay           \t\t    4) add feedback\n";
		cout<<"5) show feedbacks\t\t    6) previous\n";
		cin>>ans;
		if((ans[0] < 49 || ans[0] > 54) || ans.empty() || ans.length() > 1)
			cout<<"Enter a valid option\n";
	} while ((ans[0] < 49 || ans[0] > 54) || ans.empty() || ans.length() > 1);
	if (ans[0] == 49){
		o.list("order.txt");
		order_menu(resturant_name);
	}
	else if(ans[0] == 50){
		o.remove_from_cart(resturant_name);
		order_menu(resturant_name);
	}
	else if(ans[0] == 51){
		if(p.pay(user_name, o.get_total())){
		 	o.IsPaid(true);
		}
		order_menu(resturant_name);
	}
	else if(ans[0] == 52){
		f.add_feedback(user_name, resturant_name);
		order_menu(resturant_name);
	}else if(ans[0] == 53)
	{
		f.list("feedbacks.txt");
		order_menu(resturant_name);
	}
	else if(ans[0] == 54){
		menues_menu(resturant_name);
	}

}


// updating resturant page by owners

void owners_res_menu(){
	Acc a;
	resturant r;
	string ans, check;
	do
	{
		cout<<"\n===================================================\n";
		cout<<"1) add resturant          \t\t 2) show resturant list\n";
		cout<<"3) search for a resturant \t\t 4) filter resturants\n";
		cout<<"5) previous\n";
		cin>>ans;
		if((ans[0] < 49 || ans[0] > 53) || ans.empty() || ans.length() > 1)
			cout<<"Enter a valid option\n";
	} while ((ans[0] < 49 || ans[0] > 53) || ans.empty() || ans.length() > 1);
	if (ans[0] == 49)
	{
		r.add_res(user_name);
		resturant_name = r.get_resturant_name();
		do
			{
				cout<<"\n------------------------------------------\n";
				cout<<"1) update resturant \t\t 2) remove resturant\n";
				cout<<"3) continue to menu \t\t 4) previous\n";
				cin>>ans;
				if((ans[0] < 49 || ans[0] > 52) || ans.empty() || ans.length() > 1)
					cout<<"Enter a valid option\n";
			} while ((ans[0] < 49 || ans[0] > 52) || ans.empty() || ans.length() > 1);
		
			if (ans[0] == 49){
				r.update(resturant_name);
				owners_res_menu();
			}
			else if (ans[0] == 50){
				r.remove_res(resturant_name);
				owners_res_menu();
			}
			else if (ans[0] == 51)
				owner_menues_menu(resturant_name);
			else
				owners_res_menu();

	}else if (ans[0] == 50)
	{
		r.list("res_list.txt");
		owners_res_menu();
	}else if (ans[0] == 51)
	{
		check = r.search("res_list.txt", "resturant");
		resturant_name = r.get_resturant_name();
		cout<<check;
		if (check.empty())
			owners_res_menu();
		else{
			do
			{
				cout<<"\n------------------------------------------\n";
				cout<<"1) update resturant \t\t 2) remove resturant\n";
				cout<<"3) continue to menu \t\t 4) previous\n";
				cin>>ans;
				if((ans[0] < 49 || ans[0] > 52) || ans.empty() || ans.length() > 1)
					cout<<"Enter a valid option\n";
			} while ((ans[0] != 49 && ans[0] != 50 && ans[0] != 51 && ans[0] != 52) || ans.empty() || ans.length() > 1);
		
			if (ans[0] == 49){
				if (r.is_owner(resturant_name, user_name))
					r.update(resturant_name);
				
				owners_res_menu();
			}
			else if (ans[0] == 50){
				if (r.is_owner(resturant_name, user_name))
					r.remove_res(resturant_name);

				owners_res_menu();
			}
			else if (ans[0] == 51)
				owner_menues_menu(resturant_name);
			else
				owners_res_menu();
		
		}
	}else if(ans[0] == 52){
		r.filter("res_list.txt");
		owners_res_menu();
	}else
		common_menu();
}



void owner_menues_menu(string resturant_name){
	resturant r;
	Acc a;
	menu m;

	string ans, check;
	do
	{
		cout<<"\n====================================\n";
		cout<<"1) show menu       \t\t 2) add to menu\n";
		cout<<"3) search in menu  \t\t 4) filter menu\n";
		cout<<"5) remove from menu\t\t 6) previous\n";
		cin>>ans;
		if((ans[0] != 49 && ans[0] != 50 && ans[0] != 51 && ans[0] != 52 && ans[0] != 53 && ans[0] != 54) || ans.empty() || ans.length() > 1)
			cout<<"Enter a valid option\n";
	} while ((ans[0] != 49 && ans[0] != 50 && ans[0] != 51 && ans[0] != 52 && ans[0] != 53 && ans[0] != 54) || ans.empty() || ans.length() > 1);
	if (ans[0] == 49)
	{		
		m.list(resturant_name + ".txt");
		owner_menues_menu(resturant_name);
	}else if (ans[0] == 50)
	{
		if (!r.is_owner(resturant_name, user_name))
			owner_menues_menu(resturant_name);
		m.add_to_menu(resturant_name);
		
		do
		{
			cout<<"\n-----------------------------\n";
			cout<<"1) remove dish \t\t 2) previous\n";
			cin>>ans;
			if((ans[0] != 49 && ans[0] != 50) || ans.empty() || ans.length() > 1)
				cout<<"Enter a valid option\n";
		} while ((ans[0] != 49 && ans[0] != 50) || ans.empty() || ans.length() > 1);
	
		if (ans[0] == 49){
			if (!r.is_owner(resturant_name, user_name))
				owner_menues_menu(resturant_name);

			m.remove_from_menu(resturant_name);
			owner_menues_menu(resturant_name);
		}
		else
			owner_menues_menu(resturant_name);
	}
	else if (ans[0] == 51)
	{
		check = m.search(resturant_name + ".txt", "dish");
		cout<<check;
		if (check.empty())
			owner_menues_menu(resturant_name);
		else{
			do
			{
				cout<<"\n-----------------------------\n";
				cout<<"1) remove dish \t\t 2) previous\n";
				cin>>ans;
				if((ans[0] != 49 && ans[0] != 50) || ans.empty() || ans.length() > 1)
					cout<<"Enter a valid option\n";
			} while ((ans[0] != 49 && ans[0] != 50) || ans.empty() || ans.length() > 1);
		
			if (ans[0] == 49){
				if (r.is_owner(resturant_name, user_name))
					m.remove_from_menu(resturant_name);

				owner_menues_menu(resturant_name);
			}
			else
				owner_menues_menu(resturant_name);
		
		}
	}else if(ans[0] == 52){
		m.filter(resturant_name + ".txt");
		owner_menues_menu(resturant_name);
	}
	else if(ans[0] == 53){
		if (r.is_owner(resturant_name, user_name))
			m.remove_from_menu(resturant_name);

		owner_menues_menu(resturant_name);
	}
	else
		owners_res_menu();
}

int main() {
	main_menu();
	return 0;
}