#ifndef JUICEMACHINE_H
#define JUICEMACHINE_H

class cashRegister
{
public:
    int getCurrentBalance() const;
    //This function shows the balance of the cash register
    void acceptAmount(int amountIn);
    //This function reads in the payment amount of the user and updates
    //the register balance
    cashRegister(int cashIn = 500);
    //Constructor
    //This sets the balance of the register to a specified amount
    //Default value is 500 provided no variable amount is
private:
    int cashOnHand;
    //Variable to store the balance of the register
};

class dispenserType
{
public:
    int getNoOfItems() const;
        //Function shows the inventory 
    int getCost() const;
        //Function shows the cost of an item
    void makeSale();
        //Function decrements inventory by 1
    dispenserType(int setNoOfItems =50 , int setCost = 50);
        //Constructor
        //Sets inventory of each item and cost of each item to 50 by default
        //Or to values specified by user
private:
    int numberOfItems;
        //Variable stores inventory of each item
    int cost;
        //Variable stores cost of each item
};

#endif