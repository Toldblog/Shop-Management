//
//  function.cpp
//  testFileCustomer
//
//  Created by Apple on 07/12/2021.
//
#include "function.hpp"
#include "main.h"


int mainMenu = 0; // 0 Menu, 1 customerMenu, 2 itemMenu, 3 statisticMenu, 4 exit
int customerMenu = 0; // 1 cusomter info menu with ID, 2 list of customer, 3 back to menu
int itemMenu = 0; // 1 restock item, 2 get list of item, 3 sell item, 4 back to menu
int statisticMenu = 0; // 1 statistic in 4 month, 2 back to menu

// CUSTOMER
void readFile1Customer(ifstream& filein, Customer& cus) {
    string temp;
    getline(filein, cus.name, '\n');
    getline(filein, cus.location, '\n');
    getline(filein, cus.phoneNumber, '\n');
    getline(filein, cus.ID, '\n');
    filein >> cus.tradingtime;
    getline(filein , temp);
    for(int i = 1; i <= cus.tradingtime ;++i) {
        tradingHistory trad;
        filein >> trad.time.day >> trad.time.month >> trad.time.year;
        filein.ignore();
        getline(filein, trad.type, ' ');
        //cout << trad.type;
        filein >> trad.numOfTanks;
        filein >> trad.totalPrice;
        filein.ignore();
        getline(filein, trad.alreadyPaid, '\n');
        cus.listOfTradingHistory.push_back(trad);
    }
}
void readFileCustomer(vector<Customer>& listOfCus) {
    ifstream filein;
    filein.open("//Users//apple//Library//Mobile Documents//com~apple~CloudDocs//Documents//Tài Liệu Đại Học năm nhất//CS161//ReadWritefileC++//testFileCustomer//testFileCustomer//customer.txt", ios_base::in);
    int n;
    string temp;
    filein >> n;
    getline(filein , temp);
    for(int i = 0; i < n; ++i) {
        Customer cus;
        readFile1Customer(filein, cus);
        listOfCus.push_back(cus);
    }
    filein.close();
}
void writeFileCustomer(vector<Customer>& listOfCus) {
    ofstream fileout;
    fileout.open("//Users//apple//Library//Mobile Documents//com~apple~CloudDocs//Documents//Tài Liệu Đại Học năm nhất//CS161//ReadWritefileC++//testFileCustomer//testFileCustomer//customer.txt", ios_base::out);
    fileout << listOfCus.size() << endl;
    for(int i = 0; i < listOfCus.size(); ++i) {
        fileout << listOfCus[i].name << endl;
        fileout << listOfCus[i].location << endl;
        fileout <<listOfCus[i].phoneNumber << endl;
        fileout << listOfCus[i].ID << endl;
        fileout << listOfCus[i].tradingtime << endl;
        for(int j = 0; j < listOfCus[i].tradingtime; ++j) {
            fileout << listOfCus[i].listOfTradingHistory[j].time.day << " " << listOfCus[i].listOfTradingHistory[j].time.month << " " << listOfCus[i].listOfTradingHistory[j].time.year << " ";
            fileout << listOfCus[i].listOfTradingHistory[j].type << " " << listOfCus[i].listOfTradingHistory[j].numOfTanks << " " << listOfCus[i].listOfTradingHistory[j].totalPrice << " " << listOfCus[i].listOfTradingHistory[j].alreadyPaid  << endl;
            
        }
    }
    fileout.close();
}
int findTheCustomer(string id, vector<Customer> listOfCus) {
    bool find = false;
    int i = 0;
    while(!find) {
        if(listOfCus[i].ID == id) {
            find = true;
            return i;
        }
        ++i;
    }
    return -1;
}
int getNumsOfNum(int num) {
    int i = 0;
    while(num > 0) {
        num /= 10;
        ++i;
    }
    return i;
}
void Output1Customer(Customer& cus) {
    cout << "Name: " << cus.name << endl;
    cout << "Location: " << cus.location << endl;
    cout << "PhoneNumber: " << cus.phoneNumber << endl;
    cout << "ID: " << cus.ID << endl;
    cout << "TIME ------- TYPE --- QUANTITY --- TOTAL --- PAID" << endl;
    for(int i = 0; i < cus.listOfTradingHistory.size(); ++i) {
        cout <<  cus.listOfTradingHistory[i].time.day << " " << cus.listOfTradingHistory[i].time.month << " " << cus.listOfTradingHistory[i].time.year;
        int k = 13 - (getNumsOfNum(cus.listOfTradingHistory[i].time.day) + getNumsOfNum(cus.listOfTradingHistory[i].time.month) +getNumsOfNum(cus.listOfTradingHistory[i].time.year) + 2);
        for(int i = 1; i <= k; ++i)
        {
            cout << " ";
        }
        cout << cus.listOfTradingHistory[i].type;
        k = 12 - (int)cus.listOfTradingHistory[i].type.length();
        for(int i = 1; i <= k; ++i)
        {
            cout << " ";
        }
        cout << cus.listOfTradingHistory[i].numOfTanks;
        k = 10 - getNumsOfNum(cus.listOfTradingHistory[i].numOfTanks);
        for(int i = 1; i <= k; ++i)
        {
            cout << " ";
        }
        cout << cus.listOfTradingHistory[i].totalPrice;
        k = 10 - getNumsOfNum(cus.listOfTradingHistory[i].totalPrice);
        for(int i = 1; i <= k; ++i)
        {
            cout << " ";
        }
        cout <<  cus.listOfTradingHistory[i].alreadyPaid << endl;
    }
}
void OutputTheListOfCustomers(vector<Customer>& listOfCus) {
    cout << "=============== CUSTOMER ===============" << endl;
    cout << endl;
    for(int i = 0; i < listOfCus.size(); ++i) {
        Output1Customer(listOfCus[i]);
        cout << endl;
    }
}
// ITEM
void readFileItem(vector<Item> &listOfItem) {
    ifstream filein;
    filein.open("/Users/apple/Library/Mobile Documents/com~apple~CloudDocs/Documents/Tài Liệu Đại Học năm nhất/CS161/ReadWritefileC++/testFileCustomer/testFileCustomer/item.txt", ios_base::in);
    Item item;
    int n;
    string temp;
    filein >> n;
    getline(filein, temp);
    for(int i = 0; i < n; ++i) {
        getline(filein, item.barcode, ' ');
        getline(filein, item.name, ' ');
        filein >> item.price;
        filein >> item.stockLevel;
        getline(filein, temp); // ignore enter
        listOfItem.push_back(item);
    }
    filein.close();
}
void writeFileItem(vector<Item> listOfItem) {
    ofstream fileout;
    fileout.open("/Users/apple/Library/Mobile Documents/com~apple~CloudDocs/Documents/Tài Liệu Đại Học năm nhất/CS161/ReadWritefileC++/testFileCustomer/testFileCustomer/item.txt", ios_base::out);
    fileout << listOfItem.size() << endl;
    for(int i = 0; i < listOfItem.size(); ++i) {
        fileout << listOfItem[i].barcode << " " << listOfItem[i].name << " " << listOfItem[i].price << " " << listOfItem[i].stockLevel << endl;
    }
    fileout.close();
}
void outputTheListOfItem(vector<Item> listOfItem) {
    cout << "------------------- ITEM -------------------" << endl;
    cout << "BARCODE ---- NAME ---- PRICE ---- STOCK LEVEL" << endl;
    for(int i = 0; i < listOfItem.size(); ++i) {
        cout << listOfItem[i].barcode << "         ";
        cout << listOfItem[i].name;
        int size = (int)listOfItem[i].name.size();
        for(int i = 0; i < 11 - size; ++i) {
            cout << " ";
        }
        cout << listOfItem[i].price;
        for(int i = 0; i < 11; ++i) {
            cout << " ";
        }
        cout << listOfItem[i].stockLevel << endl;
    }
}
int lookUpTheItem(string barcode, vector<Item> listOfItem) {
    for(int i = 0; i < listOfItem.size(); ++i) {
        if(barcode == listOfItem[i].barcode) {
            return i;
        }
    }
    return -1;
}
void restockItem(vector<Item> &listOfItem) {
    int n;
    cout << "------------------- RESTOCK ITEM -------------------" << endl;
    cout << "How many type of gas tank you want to restock ";
    cin >> n;
    while(n > 0) {
        cout << "Enter the barcode of gas ";
        string barcodetemp;
        cin.ignore();
        getline(cin, barcodetemp);
        if(lookUpTheItem(barcodetemp, listOfItem) != -1) {
            int position = lookUpTheItem(barcodetemp, listOfItem);
            cout << "We have " << listOfItem[position].stockLevel << " " << listOfItem[position].name <<" left in out shop" << endl;
            cout << "How many gas tanks you want to restock ";
            int num;
            cin >> num;
            listOfItem[position].stockLevel += num;
            cout <<"Restock " << num << " tanks type " << listOfItem[position].name << " success" << endl;
            writeFileItem(listOfItem);
            
        }
        else {
            Item newitem;
            int yes;
            cout << "This type is new in our shop, do you want to stock to our shop?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cin >> yes;
            if(yes == 1) {
                cout << "Enter the barcode ";
                cin.ignore();
                getline(cin, newitem.barcode);
                cout << "Enter the name ";
                //cin.ignore();
                getline(cin, newitem.name);
                cout << "Enter the price ";
                cin >> newitem.price;
                cout << "Enter the number of tanks you want to stock ";
                cin >> newitem.stockLevel;
                listOfItem.push_back(newitem);
                writeFileItem(listOfItem);
            }
        }
        --n;
    }
}
void sellitem(vector<Item> &listOfItem, vector<Customer> &listOfCustomer) {
    cout << "========== SELL ITEM ==========" << endl;
    cin.ignore();
    cout << "Enter the barcode of the item ";
    string barcodetemp;
    getline(cin, barcodetemp);
    if(lookUpTheItem(barcodetemp, listOfItem) != -1) {
        int posofitem = lookUpTheItem(barcodetemp, listOfItem);
        cout << "How many " << listOfItem[posofitem].name <<  " tanks the customer want to buy ";
        int num, total;
        cin >> num;
        if(num > listOfItem[posofitem].stockLevel) {
            cout << "There are " << listOfItem[posofitem].stockLevel << " left in our shop" << endl;
            cout << "We don't have enough tanks that customer required" << endl;
        }
        else {
            listOfItem[posofitem].stockLevel -= num;
            total = num * listOfItem[posofitem].price;
            cout << "Total price is: " << total << endl;
            tradingHistory trad;
            cout << "Time: ";
            cin.ignore();
            cin >> trad.time.day >> trad.time.month >> trad.time.year;
            cin.ignore(1);
            trad.type = listOfItem[posofitem].name;
            trad.numOfTanks = num;
            trad.totalPrice = total;
            trad.alreadyPaid = "Paid";
            cout << "Ask the customer did he or she buy gas at our shop before?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            int confirm;
            cin >> confirm;
            if(confirm == 1) {
                string barcodetemp;
                cout << "Enter the ID of the customer ";
                string id;
                cin.ignore();
                getline(cin, id);
                cout << "Paid or Debt" << endl;
                cout << "1. Paid" << endl;
                cout << "2. Debt" << endl;
                int paid;
                cin >> paid;
                if(paid == 2) {
                    trad.alreadyPaid = "Debt"; }
                int posofcus = findTheCustomer(id, listOfCustomer);
                listOfCustomer[posofcus].listOfTradingHistory.push_back(trad);
                ++listOfCustomer[posofcus].tradingtime;
                writeFileItem(listOfItem);
                writeFileCustomer(listOfCustomer);
            }
            else {
                cout << "===== NEW CUSTOMER =====" << endl;
                Customer cus;
                cout << "Name : ";
                cin.ignore();
                getline(cin,cus.name);
                cout << "Location : ";
                getline(cin, cus.location);
                
                cout << "Phone Numbers : ";
                getline(cin, cus.phoneNumber);
                cout << "ID : ";
                getline(cin, cus.ID);
                cus.tradingtime = 1;
                cus.listOfTradingHistory.push_back(trad);
                listOfCustomer.push_back(cus);
                writeFileItem(listOfItem);
                writeFileCustomer(listOfCustomer);
            }
        }
    }
    else {
        cout << "We dont have that type in our shop" << endl;
    }
}
// STATISTIC
Time getCurrentDay(){
    Time a;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    a.year = 1900 + ltm->tm_year;
    a.month = 1 + ltm->tm_mon;
    a.day = ltm->tm_mday;
    return a;
}
int checkType(tradingHistory trad, vector<tradingHistory> lisTrad) {
    for(int i = 0; i < lisTrad.size(); ++i) {
        if(trad.type == lisTrad[i].type)
            return i;
    }
    return -1;
}
void draw(vector<int> numberOfTankInEachMonth) {
    Time currentDay = getCurrentDay();
    int maxNum = 0;
    //cout << "The number of tanks in ";
    for(int i = 0; i < numberOfTankInEachMonth.size(); ++i){
        //cout << currentDay.month + i - 3 << "th " << numberOfTankInEachMonth[i] << ", ";
        if(numberOfTankInEachMonth[i] > maxNum)
            maxNum = numberOfTankInEachMonth[i];
    }
    cout << endl;
    char array[42][81];
    for(int i = 0; i <= 40; ++i) {
        array[i][0] = '|';
        for(int j = 1; j <= 80; ++j) {
            array[i][j] = ' ';
            if(i == 40) array[i][j] = '-';
        }
        array[40][0]= ' ';
    }
    int k = 0;
    for(int i = 10; i < 80; i += 20) {
        float percent = (float)numberOfTankInEachMonth[k] / (float)maxNum *100 / 2.5;
        ++k;
        int t = (int)percent;
        for(int j = 39; j >= 40 - t; --j) {
            array[j][i] = '*';
        }
    }
    cout << "100%" << endl;
    for(int i = 0; i < 41; ++i) {
        for(int j = 0; j < 81; ++j) {
            cout << array[i][j];
        }
        cout << endl;
    }
    int temp = 0;
    for(int i = 0; i < 80; ++i){
        if(i == 10 + 20*temp) {
            cout << currentDay.month + temp - 3;
            ++temp;
            ++i;
        }
        else cout << ' ';
    }
    cout << "Month";
    cout << endl;
    
}
void statisticIn4Month(){
    Time currentDay = getCurrentDay();
    vector<Customer> listOfCustomer;
    vector<tradingHistory> listOfTypeIn5Month;
    vector<int> numberOfTankInEachMonth;
    readFileCustomer(listOfCustomer);
    //int calcu;
    //cout << "How many month you want to calculate ";
    //cin >> calcu;
    for(int k = currentDay.month; k > currentDay.month - 4; --k) {
        int sumOfTank = 0;
        for(int i = 0; i < listOfCustomer.size(); ++i){
            for(int j = 0 ; j < listOfCustomer[i].tradingtime; ++j) { // find in trading history of 1 customer
                if(listOfCustomer[i].listOfTradingHistory[j].time.year == currentDay.year && listOfCustomer[i].listOfTradingHistory[j].time.month == k) { // find the same month and year
                    
                    int pos = checkType(listOfCustomer[i].listOfTradingHistory[j], listOfTypeIn5Month); // find the same type
                    if(pos >= 0) {
                        listOfTypeIn5Month[pos].numOfTanks += listOfCustomer[i].listOfTradingHistory[j].numOfTanks;
                    }
                    else if(pos == -1) {
                        listOfTypeIn5Month.push_back(listOfCustomer[i].listOfTradingHistory[j]);
                    }
                    sumOfTank += listOfCustomer[i].listOfTradingHistory[j].numOfTanks;
                }
                
            }
        }
        numberOfTankInEachMonth.push_back(sumOfTank);
    }
    float sum = 0;
    for(int i = 0; i < listOfTypeIn5Month.size(); ++i) {
        //cout << listOfTypeIn5Month[i].type << " has the sum = " << listOfTypeIn5Month[i].numOfTanks << endl;
        sum += listOfTypeIn5Month[i].numOfTanks;
    }
    vector<int> percent;
    cout << "Total " << sum << endl;
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    for(int i = 0; i < listOfTypeIn5Month.size(); ++i) {
        listOfTypeIn5Month[i].numOfTanks = (float)(listOfTypeIn5Month[i].numOfTanks * 100) / sum;
        cout <<  listOfTypeIn5Month[i].type << ' ' << listOfTypeIn5Month[i].numOfTanks << '%';
        if(i != listOfTypeIn5Month.size() - 1) cout << ',';
        cout << ' ';
    }
    cout << endl;
    cout << "The number of tanks in ";
    for(int i = 0; i < numberOfTankInEachMonth.size(); ++i) {
        cout << currentDay.month + i - 3 << "th " << numberOfTankInEachMonth[- i + 3];
        if(i != numberOfTankInEachMonth.size() - 1) cout << ',';
        cout << ' ';
        percent.push_back((numberOfTankInEachMonth[-i+3]*100 / sum));
    }
    cout << endl;
    draw(percent);
}

// MENU
void MainMenu() {
    cout << "=============== MAIN MENU ===============" << endl;
    cout << endl;
    cout << "1. CUSTOMER MENU" << endl;
    cout << "2. ITEM MENU" << endl;
    cout << "3. STATISTIC MENU" << endl;
    cout << "4. EXIT" << endl;
    cin >> mainMenu;
}
void CustomerMenu() {
    cout << "=============== CUSTOMER MENU ===============" << endl;
    cout << endl;
    cout << "1. Get information of a customer" << endl;
    cout << "2. Get all information of customer" << endl;
    cout << "3. Back to main menu" << endl;
    int select = 0;
    cin >> select;
    if(select == 3) {
        customerMenu = 0;
        mainMenu = 0;
    }
    else
        customerMenu = select;
}
void ItemMenu() {
    cout << "=============== ITEM MENU ===============" << endl;
    cout << endl;
    cout << "1. Restock item" << endl;
    cout << "2. List of items" << endl;
    cout << "3. Sell item" << endl;
    cout << "4. Back to main menu" << endl;
    int select = 0;
    cin >> select;
    if(select == 4) {
        itemMenu = 0;
        mainMenu = 0;
    }
    else
        itemMenu = select;
}
void StatisticMenu() {
    cout << "============ STATISTIC ============" << endl << endl;
    cout << "1. Do Statistic analysis in 4 closest months" << endl;
    cout << "2. Back to main menu" << endl;
    int select = 0;
    cin >> select;
    if(select == 2) {
        statisticMenu = 0;
        mainMenu = 0;
    }
    else
        statisticMenu = select;
}
void Menu(){
    while(true) {
        switch (mainMenu) {
            case 0: { // mainMenu
                MainMenu();
            }
                break;
            case 1: { // customerMenu
                CustomerMenu();
                switch (customerMenu) {
                    case 1: { // get information of 1 customer
                        vector <Customer> listOfCustomer;
                        readFileCustomer(listOfCustomer);
                        cout << "======== FIND CUSTOMER ========" << endl;
                        cout << "Enter the ID of the cutomer: ";
                        string id;
                        cin.ignore();
                        getline(cin, id, '\n');
                        if(findTheCustomer(id, listOfCustomer) != -1)
                        {
                            Output1Customer(listOfCustomer[findTheCustomer(id, listOfCustomer)]);
                        }
                        else
                            cout << "The customer can't be defined";
                        mainMenu = 1;
                    }
                        break;
                    case 2: { // get list
                        vector <Customer> listOfCustomer;
                        readFileCustomer(listOfCustomer);
                        OutputTheListOfCustomers(listOfCustomer);
                        mainMenu = 1;
                    }
                        break;
                }
            }
                break;
            case 2: { // itemMenu
                ItemMenu();
                switch (itemMenu) {
                    case 1: { // restock
                        vector<Item> listofitem;
                        readFileItem(listofitem);
                        restockItem(listofitem);
                        mainMenu = 2;
                    }
                        break;
                    case 2: { // get list
                        vector<Item> listofitem;
                        readFileItem(listofitem);
                        outputTheListOfItem(listofitem);
                        mainMenu = 2;
                    }
                        break;
                    case 3: { // sell
                        vector<Customer> listofcustomer;
                        vector<Item> listofitem;
                        readFileCustomer(listofcustomer);
                        readFileItem(listofitem);
                        sellitem(listofitem, listofcustomer);
                        mainMenu = 2;
                    }
                        break;
                }
            }
                break;
            case 3: {
                StatisticMenu();
                switch (statisticMenu) {
                    case 1:
                        statisticIn4Month();
                        break;
                }
            }
                break;
            case 4: // EXIT Programing
                exit(0);
                break;
        }
    }
}

