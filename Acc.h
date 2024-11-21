#include <string>
#include "operations.h"
using namespace std;

class Acc : public operations
{
private:
    string username;
    string Password;
    string AccType;
    static int acc_type;
    string acc_data[5];

public:
    void add_Acc();
    bool Log_In();

    void remove_Acc();
    void remove_Acc(string Name);
    void update(string Name);
    
    string get_acc_type();
    static int return_acc_type();
    string get_name();
    
};