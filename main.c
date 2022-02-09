#include<stdio.h>
#include<stdlib.h>
#include "Customer.h" //Call to the .h file

/*
AUTHOR: Joshua Wade West
FILENAME: HW13.cpp
SPECIFICATION: Creates a list of customers in a queue that records the customers' ID, PRICE, # of ITEMS
FOR: CS 1412 Lab- Section 502
*/

int main(){
int choice;//used as the  in the while loop
int trigger = 0;

while(trigger == 0){//While loop to output the menu aslong as program is going
printf("\nWhich Command Would You Like to Do\n\n");
printf("Press '1' to Scan in a Customer \n");
printf("Press '2' to Print Out one specific Customer\n");
printf("Press '3' to Add a scanned Customer\n");
printf("Press '4' to Remove the topmost Customer \n");
printf("Press '5' to Display all added Customers and there info\n");
printf("Press '6' to End the Program\n");

scanf("%d",&choice);//THE INPUT FROM THE USER FROM THE MENU
       switch(choice){
           case 1: scan_customer();//Function call to scan in a customer
               break;
           case 2: print_customer();//Function call to print a customer
               break;
           case 3: add_customer();//Function call to add a customer into queue
               break;
           case 4: remove_customer();//function calll to remove a custmer from queue
               break;
           case 5: display_q();//function call to display the queue
               break;
           case 6: trigger = 1;//end the while loop and end the program
           printf("USER HAS ENDED THE PROGRAM");
           break;
    
           default: printf("INVALID INPUT\n");
 }}}