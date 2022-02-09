#include<stdio.h>
#include<stdlib.h>
#include "Customer.h" 
Customer* queue;
//Call for struct Customer and id queue
Customer* data;
//Call for struct Customer and id data


//an Extra Function used to call a specific Customer that has been scanned
Customer* FIND(int INPUT_ID, Customer* INFO_CALL){
   Customer *temp = INFO_CALL;//calls to the saved struct data for a specifc Customer
   while(temp){
       if(temp->id == INPUT_ID)break;//IF struct id = INPUT ID, then stop
       else temp = temp->next;// if struct id != INPUT Id, then move to the next ID
   }
   if(temp)//when all the ids are equal, then return correct data
       return temp;return NULL;
}

////////////////////////////////////////////////////////////////////////

void scan_customer(){//Function for adding Customers

Customer *scan = (Customer*)malloc(sizeof(Customer));//Creates a Pointer for cusotmers and adds an address for them
printf("\n\nEnter an ID for the New Customer: ");
scanf("%d",&scan->id);//scans in a  new id for a new customer

printf("\nEnter the Total Price For Customer %d: ",scan->id);
scanf("%f", &scan->price);//scans in the total price the customer paid

printf("\nEnter Number of Items Ordered For Customer %d: ",scan->id);
scanf("%d", &scan->items);//scans in the number of items the customer bought

if(!data) data = scan;//since its a new customer, data is saved as a new scan


   else {//else the data is placed into temporary, and used to fill in
       Customer* temp=data;
       while(temp->next!=NULL)
        temp = temp->next;
       temp->next = scan;
    }}

////////////////////////////////////////////////////////////////////////

void print_customer(){//Function to print out a specific Customer
   int id;//variable for ID call
   printf("\n\nEnter The ID Of The Customer You Would Like To Print Out\n");
   scanf("%d",&id);//inputs the ID for the Customer
   Customer *temp = FIND(id, queue);// calls to the Find Function to Find the Customers Info and put the values into *temp
   if(temp){//IF ID is Accurate
printf("The Customer's ID Is %d\n",temp->id);//outputs the Customers ID
printf("The Total Price For The Customer Is %.2f\n",temp->price);//outputs the Customers ID total purchase price
printf("The Number Of Items The Customer Is Buying Is %d\n",temp->items);//outputs the # of items the Customer is purchasing
   }
   else
       printf("UNKNOWN CUSTOMER ID\n");//if ID is not == to the one the user inputted
}

/////////////////////////////////////////////////////////////////////////////

void add_customer(){//Function to Add Customer to Queue
   printf("\n\nEnter The ID Of The Customer You Want To Add To Queue: ");
   int id;//cariable for ID call 

   scanf("%d",&id);//user inputs a scanned customers ID

   Customer* Adding = FIND(id,data);// ADDING Variable Used By Finding Function Call

   if(!Adding) {printf("\nUNKNOWN CUSTOMER ID\n");//If Adding's ID =! user input ID, report error
       return;
   }
   Customer* add = (Customer*)malloc(sizeof(Customer));// gives an addres for new struct variable add

   add->id = Adding->id;//inputs Found ID Info into Queue

   add->price = Adding->price; //inputs Found Total Price Info into Queue

   add->items = Adding->items; //inputs Found Items Info into Queue
 
   if(!queue) queue = add; //enters the add values into the variale queue

   else {//if queue matches incorrectly, then moves onto next
       Customer* temp=queue;
       while(temp->next!=NULL)//whilst next has value
           temp = temp->next;
           temp->next = add;
    
    }
    printf("\n\nCustomer Is Added\n\n");
    }

////////////////////////////////////////////////////////////////////////////

void remove_customer(){//Function to remove the Firstmost Customer
   Customer *temp=queue;//Variable temp filled by values found in latest queue
   if(!queue) {
       printf("\nNO ONE LEFT IN QUEUE\n");//if the User asks to remove Customer, but no Customer exists
       return;
   }
   printf("Customer %d has Been removed From Queue\n", queue->id);//tells user that
   queue = queue->next;//moves to next customer in Line
   temp->next = NULL;//next is nulled
   free(temp);//values in temp is cleared
}

///////////////////////////////////////////////////////

void display_q(){//Function To Display All Customers In Queue

   Customer* temp = queue;//inputs the data from queue into temp
   if(!queue) {printf("NO CUSTOMERS IN QUEUE\n");//if queue is void then
       return;
   }
   while(temp) {//While temp is not void
       printf("The Customer's ID Is %d\n",temp->id);//outputs the Customers ID

printf("The Total Price For The Customer Is %.2f\n",temp->price);//outputs the Customers ID total purchase price

printf("The Number Of Items The Customer Is Buying Is %d\n",temp->items);//outputs the # of items the Customer is purchasing

printf("\n\n");

       temp = temp->next;// moves temp onto the next values, as to output the next customer
   }
}