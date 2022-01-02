//
//  function.hpp
//  testFileCustomer
//
//  Created by Apple on 07/12/2021.
//

#ifndef function_hpp
#define function_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "main.h"

using namespace std;

// CUSTOMER
void readFile1Customer(ifstream& filein, Customer& cus);
void readFileCustomer(vector<Customer>& listOfCus);
void writeFileCustomer(vector<Customer>& listOfCus);
int findTheCustomer(string id, vector<Customer> listOfCus);
int getNumsOfNum(int num);
void Output1Customer(Customer& cus);
void OutputTheListOfCustomers(vector<Customer>& listOfCus);
// ITEM
void readFileItem(vector<Item> &listOfItem);
void writeFile1Item(vector<Item> listOfItem);
void writeFileItem(vector<Item> listOfItem);
void outputTheListOfItem(vector<Item> listOfItem);
int lookUpTheItem(string barcode, vector<Item> listOfItem);
void restockItem(vector<Item> &listOfItem);
void sellitem(vector<Item> &listOfItem, vector<Customer> &listOfCustomer);
// STATISTIC
Time getCurrentDay();
int checkType(tradingHistory trad, vector<tradingHistory> lisTrad);
void draw(vector<int> numberOfTankInEachMonth);
void statisticIn4Month();
// MENU
void MainMenu();
void CustomerMenu();
void ItemMenu();
void StatisticMenu();
void Menu();


#endif /* function_hpp */
