// GithubWeek3code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> //allows creation/use of inputfilestream and outputfilestream
#include <algorithm>

using namespace std;

int main()
{
    //initialize the variables
    string itemname = "";
    string itemfragile = "";
    double ordertotal = 0;
    string destination = "";
    double shippingcost = 0;
    double fragilefee = 0;

    //ifstream order; //declares infilestream variable
    ofstream order; //declares outfilestream variable
    order.open("Order.txt");

    cout << "Please enter the item name (no spaces)" << setw(11) << setfill('.') << ":"; //input prompt
    cin >> itemname; //sets the string var itemname to the value of the input
    transform(itemname.begin(), itemname.end(), itemname.begin(), ::toupper); //converts to uppercase letters



    cout << "Is the item fragile? (y = yes, n = no)" << setw(11) << setfill('.') << ":";;
    cin >> itemfragile;
    transform(itemfragile.begin(), itemfragile.end(), itemfragile.begin(), ::toupper);

    //determine if shipping fee for fragile item
    if (itemfragile == "Y") {
        fragilefee = 2.00;
    }
    else if (itemfragile == "N") {
        fragilefee = 0;

    }
    else {
        cout << "Invalid entry, exiting";
        return 1;
    }



    cout << "Please enter your order total" << setw(20) << setfill('.') << ":";;
    cin >> ordertotal;



    cout << "Please enter destination. (usa/can/aus/pluto)" << setw(10) << setfill('.') << ":";;
    cin >> destination;
    transform(destination.begin(), destination.end(), destination.begin(), ::toupper);


    //calculate the costs of shipping
    if (ordertotal < 50) {
        if (destination == "USA" || destination == "usa")
        {
            shippingcost = 6.00 + fragilefee;
        }

        else if (destination == "CAN" || destination == "can")
        {
            shippingcost = 8.00 + fragilefee;
        }

        else if (destination == "AUS" || destination == "aus")
        {
            shippingcost = 10.00 + fragilefee;
        }
        else if (destination == "PLUTO" || destination == "pluto")
        {
            shippingcost = 20.00 + fragilefee;
        }
        else {
            cout << "Invalid entry, exiting";
            return 1;
        }
    }
    else if (ordertotal >= 50.01 && ordertotal <= 100) {
        if (destination == "USA" || destination == "usa")
        {
            shippingcost = 9.00 + fragilefee;
        }

        else if (destination == "CAN" || destination == "can")
        {
            shippingcost = 12.00 + fragilefee;
        }
        else if (destination == "AUS" || destination == "aus")
        {
            shippingcost = 14.00 + fragilefee;
        }
        else if (destination == "PLUTO" || destination == "pluto")
        {
            shippingcost = 20.00 + fragilefee;
        }
        else {
            cout << "Invalid entry, exiting";
            return 1;
        }

    }
    else if (ordertotal >= 100.01 && ordertotal <= 150) {
        if (destination == "USA" || destination == "usa")
        {
            shippingcost = 12.00 + fragilefee;
        }
        else if (destination == "CAN" || destination == "can")
        {
            shippingcost = 15.00 + fragilefee;
        }
        else if (destination == "AUS" || destination == "aus")
        {
            shippingcost = 17.00 + fragilefee;
        }
        else if (destination == "PLUTO" || destination == "pluto")
        {
            shippingcost = 20.00 + fragilefee;
        }
        else {
            cout << "Invalid entry, exiting";
            return 1;
        }

    }
    else if (ordertotal > 150) {
        shippingcost = 0.00 + fragilefee; //free

    }
    else {
        cout << "Invalid entry, exiting";
        return 1;
    }

    cout << endl;

    //2nd part
    //transform(itemname.begin(), itemname.end(), itemname.begin(), ::toupper); //convert to uppercase

    cout << "Your item is" << setw(32) << setfill('.') << itemname << endl;
    cout << "Your shipping cost is" << setw(15) << setfill('.') << setprecision(2) << fixed << "$" << shippingcost << endl;
    cout << "Your are shipping to" << setw(18) << setfill('.') << destination << endl;
    cout << "Your total shipping costs are" << setw(7) << setfill('.') << setprecision(2) << fixed << "$" << ordertotal + shippingcost << endl;

    cout << endl;
    cout << setw(45) << setfill('-') << "Thank you!";

    //write to the order.txt
    //NOTE it writes to the file when the console is done due to the inputs needed


    order << "Your item is" << setw(32) << setfill('.') << itemname << endl;
    order << "Your shipping cost is" << setw(15) << setfill('.') << setprecision(2) << fixed << "$" << shippingcost << endl;
    order << "Your are shipping to" << setw(18) << setfill('.') << destination << endl;
    order << "Your total shipping costs are" << setw(7) << setfill('.') << setprecision(2) << fixed << "$" << ordertotal + shippingcost << endl;

    order << endl;
    order << setw(45) << setfill('-') << "Thank you!";







    order.close();
    return 0;
}

