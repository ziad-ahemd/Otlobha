#include <string>
#include "operations.h"
using namespace std;

class resturant : public operations
{
private:
    string owner;
    string res_data[5];

public:
	
    void add_res(string owner);  
        
    // int filter();
    
    void remove_res();
    void remove_res(string name);
        
    int search_data(string name, string data);
    
    string get_resturant_name();
    
    void update(string name);

    bool is_owner(string resturant_name, string owner);
    
};
