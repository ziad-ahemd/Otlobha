#include <string>
#include "operations.h"
using namespace std;

class menu : public operations
{
private:
        string dish_name;
        string dish_discription;
        string dish_category;
        string resturant_name;
        string price;
        int num;
        string file;
public:				    	
        void add_to_menu(string resturant_name);
                
        void remove_from_menu(string resturant_name);
                
        int get_dish(string resturant_name, string dish_name);
        string get_dish_name();
};

