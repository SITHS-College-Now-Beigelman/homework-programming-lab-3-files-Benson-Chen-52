// Benson Chen
// Homework 3 Part 2
// 10/15/24

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{   
    //Declares the variables to be used
    ifstream inFile;
    ofstream outFile;
    float total_money, transactions;
    char letter;
    float withdrawl;
    float deposit;
    float withdrawl_amount = 0, deposit_amount = 0;
    int number_of_withdrawl = 0, number_of_deposit = 0;

    inFile.open("transactions.txt"); //Opens the input file
    outFile.open("Balance_sheet.txt"); //Opens the output file

    //Grabs first line of values from the input file
    inFile >> total_money >> letter >> transactions;

    //Cout statement
    cout << "Obtaining Transactions History.....";
    //Setsup the format for the first line as well as to what decimal point the values should go to
    outFile << "TYPE" << setw(12) << setfill('.') << "AMOUNT" << setw(20) << "BALANCE" << setprecision(2) << endl;

    //While loop that continues until it reaches 'eof' End Of File
    while(!inFile.eof())
    {   
        //If the character is W
        if(letter == 'W')
        {   
            withdrawl = total_money - transactions; //Calculations for the money in the account after the withdrawl
            outFile << fixed << showpoint; //Setups up the output by making it decimal form and showing the two 00 that follows
            //Prints the type of transaction, the amount in the transaction, and the updated amount in the account
            //Uses setw and setfill to manipulate the output to be aligned and look more professional
            outFile << letter << setw(15) << setfill('.') << transactions << setw(20) << withdrawl << endl;
            total_money = withdrawl; //Sets the remaining withdrawl amount as the new total money in the account
            withdrawl_amount += transactions; //Adds the amount of money in each withdrawl transaction
            number_of_withdrawl++; //Keeps track of the number of withdrawls done
            inFile >> letter >> transactions; //Grabs the next line of values to be processed through the if statments again 
        }
        //If the character is D
        if(letter == 'D')
        {   
            deposit = total_money + transactions; //Calculations for the money in the account after the deposit
            outFile << fixed << showpoint; //Setups up the output by making it decimal form and showing the two 00 that follows
            //Prints the type of transaction, the amount in the transaction, and the updated amount in the account
            //Uses setw and setfill to manipulate the output to be aligned and look more professional
            outFile << letter << setw(15) << setfill('.') << transactions << setw(20) << deposit << endl;
            total_money = deposit; //Sets the new deposit amount as the new total money in the account
            deposit_amount += transactions; //Adds the amount of money in each deposit transaction
            number_of_deposit++; //Keeps track of the number of deposits done
            inFile >> letter >> transactions; //Grabs the next line of values to be processed through the if statments again 
        }
    }
    outFile << "\n \n"; //Setup spaces
    outFile << "ENDING BALANCE: $" << total_money << endl; //Prints the ending balance
    outFile << "TOTAL NUMBER OF WITHDRAWLS: " << number_of_withdrawl << endl; //Prints number of withdrawls
    outFile << "TOTAL WITHDRAWL AMOUNT: $" << withdrawl_amount << endl; //Prints the total amount withdrawn
    outFile << "TOTAL NUMBER OF DEPOSITS: " << number_of_deposit << endl; //Prints the number of deposits
    outFile << "TOTAL DEPOSIT AMOUNT: $" << deposit_amount << endl; //Prints the total deposited amount
    return 0;
}
/*TYPE......AMOUNT.............BALANCE
W.........200.00.............4800.00
W.........800.00.............4000.00
W..........40.00.............3960.00
D..........90.00.............4050.00
D.........100.00.............4150.00
D........1000.00.............5150.00
W..........20.00.............5130.00

 
ENDING BALANCE: $5130.00
TOTAL NUMBER OF WITHDRAWLS: 4
TOTAL WITHDRAWL AMOUNT: $1060.00
TOTAL NUMBER OF DEPOSITS: 3
TOTAL DEPOSIT AMOUNT: $1190.00
*/