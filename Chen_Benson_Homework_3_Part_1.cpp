// Benson Chen
// Homework 3 Part 1
// 10/15/24
#include <iostream>
#include <fstream>
using namespace std;

//Part 1
int main()
{     
    ifstream inFile; //Declares variable inFile
    //Declares variables
    int total_money, transactions;
    char letter;
    int withdrawl;
    int deposit;

    //Opens the text file
    inFile.open("transactions.txt");
    //Grabs the total money, the first letter, and the following value from the text
    inFile >> total_money >> letter >> transactions;

    //For loop for a total of 6 iterations due to the first line of values being grabbed outside the loop
    for(int i = 1; i<=6; i++)
    {   
        //If the character is W
        if(letter == 'W')
        {   
            withdrawl = total_money - transactions; //Calculation for the money in the account after the withdrawl
            cout << "Amount of money in the transaction: $" << transactions << endl; //Prints the money in the transaction
            cout << "Remaining balance after transaction: $" << withdrawl << "\n" << endl; //Prints the remaining money
            total_money = withdrawl; //Sets the remaining withdrawl amount as the new total money in the account
            inFile >> letter >> transactions; //Grabs the next line of values to be processed through the if statments again
        }
        //If the character is D
        if(letter == 'D')
        {   
            deposit = total_money + transactions; //Calculations for the money in the account after the deposit
            cout << "Amount of money in the transaction: $" << transactions << endl; //Prints the money in the transaction
            cout << "Remaining balance after transaction: $" << deposit << "\n" << endl; //Prints the remaining money
            total_money = deposit; //Sets the new amount after the deposit as the new total money in the account
            inFile >> letter >> transactions; //Grabs the next line of values to be processed through the if statments again
        }
    }
    cout << "Total amount of money in the account after all transactions: $" << total_money; //Prints total money after all transactions

    return 0;
}
/*Amount of money in the transaction: $200
Remaining balance after transaction: $4800

Amount of money in the transaction: $800
Remaining balance after transaction: $4000

Amount of money in the transaction: $40
Remaining balance after transaction: $3960

Amount of money in the transaction: $90
Remaining balance after transaction: $4050

Amount of money in the transaction: $100
Remaining balance after transaction: $4150

Amount of money in the transaction: $1000
Remaining balance after transaction: $5150

Amount of money in the transaction: $20
Remaining balance after transaction: $5130

Total amount of money in the account after all transactions: $5130*/

//Part 2