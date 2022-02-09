typedef struct customer{
   int id;// struct variable for ID
   float price;// struct variable for the Total Price of the what the customer bought
   int items;//struct for the number of items user bought
   struct customer *next;// struct variable used to loop throuhh values
}Customer;

void scan_customer();//prototype for Scan
void print_customer();//prototype for print
void add_customer();//prototype for add
void remove_customer();//prototype for remove
void display_q();//prototype for display