#include <iostream>
using namespace std;
//initialzing user info and while loops flags
int user1_pass, user1_balance, input_pass, wrong_pass, transaction, other_value, deposite, other_services;
bool banking, options, secure;

int main(){
//assigning user info and while loops flags
    user1_pass = 1234;
    user1_balance = 0;//if the custmer don't have balance he can deposite later
    wrong_pass = 4;//the custmer can miss the password with the limit of 4 times
    banking = options = secure = true;
//the app
    while(banking){
        cout<<"=============================\n";
        cout<<"\t    ATM\n";
        cout<<"=============================\n";
        cout<<"enter 4 digit password\n";
//verifing the password
        while (secure)
        {
            cin>>input_pass;
            if(input_pass != user1_pass){
                wrong_pass--;
                cout<<"=============================\n";
                if (wrong_pass == 0)
                {
                    cout<<"you have reached the limit of tries";
                    return 0;
                }else{
                    cout<<"password is incorrect \nplease try againg\n";
                }
                continue;
            }else{break;}
        }
//menue
        while (options)
        {
            cout<<"=============================\n";
            cout<<"1) $50\t 2) $100\n";
            cout<<"3) $200\t 4) $500\n";
            cout<<"5) 1000\t 6) other value\n";
            cout<<"7) other service\n";
            cin>>transaction;
            switch (transaction)
            {
            case 1:
                cout<<"=============================\n";
                if (user1_balance < 50)
                {
                    cout<<"not enogh balance\n";
                }else{
                    cout<<"you have withdrawed $50 sucsessfully\n";
                    user1_balance -= 50;
                }
                break;

            case 2:
                cout<<"=============================\n";
                if (user1_balance < 100)
                {
                    cout<<"not enogh balance\n";
                }else{
                    cout<<"you have withdrawed $100 sucsessfully\n";
                    user1_balance -= 100;
                }
                break;
            
            case 3:
                cout<<"=============================\n";
                if (user1_balance < 200)
                {
                    cout<<"not enogh balance\n";
                }else{
                    cout<<"you have withdrawed $200 sucsessfully\n";
                    user1_balance -= 200;
                }
                break;

            case 4:
                cout<<"=============================\n";
                if (user1_balance < 500)
                {
                    cout<<"not enogh balance\n";
                }else{
                    cout<<"you have withdrawed $500 sucsessfully\n";
                    user1_balance -= 500;
                }
                break;

            case 5:
                cout<<"=============================\n";
                if (user1_balance < 1000)
                {
                    cout<<"not enogh balance\n";
                }else{
                    cout<<"you have withdrawed $1000 sucsessfully\n";
                    user1_balance -= 1000;
                }
                break;

            case 6:
                cout<<"How much do you want to withdraw?\n";
                cin>>other_value;
                cout<<"=============================\n";
                if (user1_balance < other_value)
                {
                    cout<<"not enogh balance\n";
                }else{
                    cout<<"you have withdrawed $"<<other_value<<" sucsessfully\n";
                    user1_balance -= other_value;
                }                        
                break;

            case 7:
                cout<<"=============================\n";
                cout<<"1) Account balance\t 2) deposite\n";
                cin>>transaction;
                switch (transaction)
                {
                case 1:
                    cout<<"=============================\n";
                    cout<<"your account balance is: "<<user1_balance<<"\n";
                    break;
                
                case 2:
                    cout<<"=============================\n";
                    cout<<"How much do you want to deposite?\n";
                    cin>>deposite;
                    user1_balance += deposite;
                    cout<<"sucsessfull transaction\nyour account balance is: $"<<user1_balance<<"\n";
                    break;
                
                default:
                    cout<<"=============================\n";
                    cout<<"Enter a valid value only 1 or 2\n";
                    break;
                }
                break;
                
            default:
                cout<<"Enter a valid value from 1 to 7\n";
                continue;
            }
//checking for other services
            cout<<"other services?\n";
            cout<<"1) yes \t 2) no\n";
            cin>>other_services;
            if(other_services == 1){
                continue;
            }else if(other_services == 2){
                break;
            }                                   
        }
        continue;
    }
}