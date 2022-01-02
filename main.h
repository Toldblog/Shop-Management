//
//  main.h
//  testFileCustomer
//
//  Created by Apple on 18/12/2021.
//

#ifndef main_h
#define main_h
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Time {
    int day;
    int month;
    int year;
};
struct tradingHistory {
    Time time;
    string type;
    int numOfTanks;
    float totalPrice;
    string alreadyPaid;
};
struct Customer {
    string name;
    string location;
    string phoneNumber;
    string ID;
    int tradingtime;
    vector<tradingHistory> listOfTradingHistory;
};
struct Item {
    string barcode;
    float price;
    string name;
    int stockLevel;
};


#endif /* main_h */
