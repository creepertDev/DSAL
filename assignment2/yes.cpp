<<<<<<< HEAD
// 23303
// searching and sorting

#include <iostream>
#include <cstring>
using namespace std;
#define maxClassSize 6
#include <fstream>
#include <sstream>
#include <string>

// struct student containing integer, string and float
struct student
{
=======
//23303
//searching and sorting

#include<iostream>
#include<cstring>
using namespace std;
#define maxClassSize 6
#include<fstream>
#include<sstream>
#include<string>

//struct student containing integer, string and float
struct student{
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
    int rollNo;
    string name;
    float sgpa;
};

<<<<<<< HEAD
// declareing node as a type
typedef struct student node;

// list containing all the functions
class list
{
public:
    // private:
=======
//declareing node as a type 
typedef struct student node;

//list containing all the functions
class list{
    public:
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
    node classroom[maxClassSize];
    int n;

    // public:
    void loadCSV(string csvFile);
    void saveToCSV(string csvFile);
    int partition(node classR[maxClassSize], int l, int h);
<<<<<<< HEAD
    void quicksort(node classR[maxClassSize], int l, int h);
=======
    void quicksort(node classR[maxClassSize], int l , int h);
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
    node getNode(node t);
    void displayNode(node t);
    void displayNode(string t);
    void mbubbleSort();
    node mlinearSeach(int key);
    node mBinarySeach(int key);
    void insertionSorting();
    void bigListEntering();
    void swap(node &a, node &b);
};

<<<<<<< HEAD
// swap functions for two nodes, call by reference
void list::swap(node &a, node &b)
{
=======
//swap functions for two nodes, call by reference
void list::swap(node &a, node &b){
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
    node temp = a;
    a = b;
    b = temp;
    return;
<<<<<<< HEAD
    cout << "Swapped nodes : " << endl;
    displayNode(a);
    displayNode(b);
}

// partition function for quicksort according to sgpa
int list::partition(node classR[maxClassSize], int l, int h)
{
    float pivot = classR[l].sgpa;
    int i = l + 1;
    int j = h;

    while (true)
    {
        while (i <= h && classR[i].sgpa >= pivot)
        {
            i++;
        }
        while (j >= l + 1 && classR[j].sgpa < pivot)
        {
            j--;
        }
        if (i >= j)
        {
            break;
        }
        swap(classR[i], classR[j]);
        cout << "Swapped nodes : " << endl;
        displayNode(classR[i]);
        displayNode(classR[j]);
    }
    swap(classR[l], classR[j]);
    cout << "Swapped nodes : " << endl;
    displayNode(classR[l]);
    displayNode(classR[j]);
    return j;
}

// quicksort function called recursively
void list::quicksort(node classR[maxClassSize], int l, int h)
{
    if (l < h)
    {
        int p = partition(classR, l, h);
        quicksort(classR, l, p - 1);
        quicksort(classR, p + 1, h);
    }
}

// loading csv file from the file "csvFile"
void list::loadCSV(string csvFile)
{
    ifstream file(csvFile);
    if (!file.is_open())
    {
        cout << "ERROR OPENING FILE" << endl;
=======
}

//partition function for quicksort
int list::partition(node classR[maxClassSize], int l , int h){
    float pivot = classR[l].sgpa;
    int i = l+1;
    int j = h;

    while(true){
        while(i<=h && classR[i].sgpa>=pivot){
            i++;
        }
        while(j>=l+1 && classR[j].sgpa<pivot){
            j--;
        }
        if(i>=j){
            break;
        }
        swap(classR[i], classR[j]);
    }
    swap(classR[l], classR[j]);

    return j;
}

//quicksort function called recursively
void list::quicksort(node classR[maxClassSize], int l , int h){
    if(l<h){
        int p = partition(classR, l, h);
        quicksort(classR, l, p-1);
        quicksort(classR, p+1, h);
    }
}

//loading csv file from the file "csvFile"
void list::loadCSV(string csvFile){
    ifstream file(csvFile);
    if (!file.is_open()){
        cout<<"ERROR OPENING FILE"<<endl;
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
        return;
    }

    string t;
    int i = 0;
<<<<<<< HEAD
    while (getline(file, t) && i < maxClassSize)
    {
=======
    while(getline(file,t) && i<maxClassSize){
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
        stringstream ss(t);
        string roll, name, sgpaStr;

        getline(ss, roll, ',');
        getline(ss, name, ',');
        getline(ss, sgpaStr, ',');

        classroom[i].rollNo = stoi(roll);
        classroom[i].name = name;
        classroom[i].sgpa = stof(sgpaStr);
<<<<<<< HEAD
        // no need to further the textpointer as it already does it with "getline", only array index needs to be furthered
        i++;
    }
    file.close();
    cout << "Data ingested from " << csvFile << endl;
    return;
}

// function to save list to a csv file
void list::saveToCSV(string csvFile)
{
    ofstream file(csvFile);
    if (!file.is_open())
    {
        cout << "ERROR OPENING FILE" << endl;
        return;
    }

    // traversing array to print to a file
    for (int i = 0; i < maxClassSize; i++)
    {
        file << classroom[i].rollNo << ",";
        file << classroom[i].name << ",";
        file << classroom[i].sgpa << "\n";
    }
    file.close();
    cout << "Data saved to : " << csvFile << endl;
}

// entering nodes into a list, defunct function, made redundant by file handling
void list::bigListEntering()
{
    for (int i = 0; i < maxClassSize; i++)
    {
=======
        //no need to further the textpointer as it already does it with "getline", only array index needs to be furthered
        i++;
    }
    file.close();
    cout<<"Data ingested from "<<csvFile<<endl;
    return;
}

//function to save list to a csv file
void list::saveToCSV(string csvFile){
    ofstream file(csvFile);
    if(!file.is_open()){
        cout<<"ERROR OPENING FILE"<<endl;
        return;
    }

    //traversing array to print to a file
    for(int i=0;i<maxClassSize;i++){
        file<<classroom[i].rollNo<<",";
        file<<classroom[i].name<<",";
        file<<classroom[i].sgpa<<"\n";
    }
    file.close();
    cout<<"Data saved to : "<<csvFile<<endl;
}

//entering nodes into a list, defunct function, made redundant by file handling 
void list::bigListEntering(){
    for(int i=0;i<maxClassSize;i++){
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
        getNode(classroom[i]);
    }
}

<<<<<<< HEAD
// binary search, searches by dividing into halves, only works when list is sorted, implemented for roll numbers
node list::mBinarySeach(int key)
{
    int l = 0;
    int h = maxClassSize - 1;
    while (l < h)
    {
        int m = (l + h) / 2;

        if (key == classroom[m].rollNo)
        {
            cout << endl
                 << "Record found!!!" << endl;
            return classroom[m];
        }
        else if (key < classroom[m].rollNo)
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    // not found handling
    if (l < h + 1)
    {
        cout << "NOT FOUND" << endl;
        // returns last element if end bound if the entered key is greater than the last roll number, otherwsie returns the first element
        if (key > classroom[maxClassSize - 1].rollNo)
        {
            return classroom[maxClassSize - 1];
        }
        else
        {
            return classroom[0];
        }
    }
    return classroom[0];
}

// insertion sorting
void list::insertionSorting()
{
    for (int i = 1; i < maxClassSize - 1; i++)
    {
        node temp = classroom[i];
        int j = i - 1;
        while (classroom[j].rollNo > temp.rollNo && j >= 0)
        {
            classroom[j + 1] = classroom[j];
            cout << "Swapped nodes : " << endl;
            displayNode(classroom[i]);
            displayNode(classroom[j]);
            j--;
        }
        classroom[j + 1] = temp;
    }
}

// bubble sorting
void list::mbubbleSort()
{
    for (int j = 0; j < maxClassSize - 1; j++)
    {
        for (int i = 0; i < maxClassSize - 1; i++)
        {
            if (classroom[i].rollNo > classroom[i + 1].rollNo)
            {
                swap(classroom[i], classroom[i + 1]);
                cout << "Swapped nodes : " << endl;
                displayNode(classroom[i]);
                displayNode(classroom[i + 1]);
            }
        }
    }
}

// linear search
node list::mlinearSeach(int key)
{
    if (key > maxClassSize)
    {
        cout << "Invalid roll number !!" << endl;
        node t;
        t.rollNo = -1;
        t.name = "";
        t.sgpa = 0.0;
        return t;
    }
    for (int i = 0; i < n; i++)
    {
        if (classroom[i].rollNo == key)
        {
            cout << "Found !!" << endl;
            return classroom[i];
        }
    }
    cout << "Not found !!" << endl;
    node t;
    t.rollNo = -1;
    t.name = "";
    t.sgpa = 0.0;
    return t;
}

node list::getNode(node t)
{
    cout << "Enter the roll number : ";
    cin >> t.rollNo;
    cout << "Enter the name : ";
    cin.ignore();
    cin >> t.name;
    cout << "Enter the SGPA : ";
    cin >> t.sgpa;
    return t;
}

void list::displayNode(node t)
{
    cout << "Roll no : " << t.rollNo << " Name : " << t.name << " SGPA: " << t.sgpa << endl;
}

void list::displayNode(string t)
{
    int i = 0;
    node temp = classroom[i];
    while (strcmp(temp.name.c_str(), t.c_str()) != 0)
    {
        temp = classroom[i];
        i++;
    }

    cout << "Roll no : " << temp.rollNo << " Name : " << temp.name << " SGPA: " << temp.sgpa << endl;
}

int main()
{
    list listOne;
    listOne.loadCSV("csvFileIngest.csv");

    // is running condition and switch case operation
    // is sorted condition since binary search cannot run on a unsorted dataset
    int isRunning = 0;
    bool sorted = false;
    while (isRunning == 0)
    {
        cout << "--------------------------STUDENT MANAGEMENT SYSTEM--------------------------" << endl;
        cout << "\t1. Sorting with quicksort according to sgpa\n\t2. Insertion sorting\n\t3. Bubble sort\n\t4. Searching using linear search" << endl
             << endl
             << "Enter operation : ";
        int operation;
        cin >> operation;
        switch (operation)
        {
        case 1:
            // sorts according to sgpa
            listOne.quicksort(listOne.classroom, 0, maxClassSize - 1);
            sorted = true;
            break;
        case 2:
            // according to roll number
=======
//binary search, searches by dividing into halves, only works when list is sorted, implemented for roll numbers
node list::mBinarySeach(int key){
    int l = 0; 
    int h = maxClassSize - 1;
    while(l < h){
        int m = (l+h)/2;
        
        if(key == classroom[m].rollNo){
            cout<<endl<<"Record found!!!"<<endl;
            return classroom[m];
        }
        else if(key<classroom[m].rollNo){
            h = m-1;
        }
        else{
            l = m+1;
        }
    }
    //not found handling
    if(l<h+1){
        cout<<"NOT FOUND"<<endl;
        //returns last element if end bound if the entered key is greater than the last roll number, otherwsie returns the first element
        if(key>classroom[maxClassSize-1].rollNo){
            return classroom[maxClassSize-1];
        }
        else{
            return classroom[0];
        }
    }
    return classroom[0];
}

//insertion sorting 
void list::insertionSorting(){
    for(int i=1; i<maxClassSize-1; i++){
        node temp = classroom[i];
        int j = i-1;
        while(classroom[j].rollNo>temp.rollNo && j>=0){
            classroom[j+1] = classroom[j];
            j--;
        }
        classroom[j+1] = temp;
    }
}

//bubble sorting 
void list::mbubbleSort(){
    for (int j=0;j<maxClassSize-1;j++){
        for(int i = 0; i<maxClassSize-1;i++){
            if(classroom[i].rollNo > classroom[i+1].rollNo){
                node temp = classroom[i];
                classroom[i] = classroom[i+1];
                classroom[i+1] = temp;
            }
        }
    }
}

//linear search
node list::mlinearSeach(int key){
    for(int i=0; i<n; i++){
        if(classroom[i].rollNo == key){
            cout<<"Found !!"<<endl;
            return classroom[i];
        }
    }
}

node list::getNode(node t){
    cout<<"Enter the roll number : ";
    cin>>t.rollNo;
    cout<<"Enter the name : ";
    cin.ignore();
    cin>>t.name;
    cout<<"Enter the SGPA : ";
    cin>>t.sgpa;
    return t;    
}

void list::displayNode(node t){
    cout<<"Roll no : "<<t.rollNo<<" Name : "<<t.name<<" SGPA: "<<t.sgpa<<endl;
}

void list::displayNode(string t){
    int i =0;
    node temp = classroom[i];
    while (strcmp(temp.name.c_str(), t.c_str())!=0){
        temp = classroom[i];
        i++;
    }
    
    cout<<"Roll no : "<<temp.rollNo<<" Name : "<<temp.name<<" SGPA: "<<temp.sgpa<<endl;
}

int main(){
    list listOne;
    listOne.loadCSV("csvFileIngest.csv");

    //is running condition and switch case operation
    int isRunning = 0;
    bool sorted = false;
    while(isRunning == 0){
        cout<<"--------------------------STUDENT MANAGEMENT SYSTEM--------------------------"<<endl;
        cout<<"\t1. Sorting with quicksort\n\t2. Insertion sorting\n\t3. Bubble sort\n\t4. Searching using linear search"<<endl<<endl<<"Enter operation : ";
        int operation;
        cin>>operation;
        switch (operation)
        {
        case 1:
            listOne.quicksort(listOne.classroom, 0, maxClassSize-1);
            sorted = true;
            break;
        case 2:
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
            listOne.insertionSorting();
            sorted = true;
            break;
        case 3:
<<<<<<< HEAD
            // according to roll number
=======
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
            listOne.mbubbleSort();
            sorted = true;
            break;
        case 4:
<<<<<<< HEAD
            int key;
            cout << "Enter the key : ";
            cin >> key;
            listOne.displayNode(listOne.mlinearSeach(key));
            break;
        case 5:
            if (sorted == true)
            {
                int key;
                cout << "Enter the key : ";
                cin >> key;
                listOne.mBinarySeach(key);
            }
            else
            {
                cout << "ERROR : LIST NEEDS TO BE SORTED BEFORE BINARY SEARCH" << endl;
            }
            break;
        default:
            cout << "INVALID CASE" << endl;
            break;
        }

        cout << "Do you want to continue ? (0 for continuing and any other integer to terminate) : ";
        cin >> isRunning;
    }

=======
            int key; 
            cout<<"Enter the key : ";
            cin>>key;
            listOne.mlinearSeach(key);
            break;
        case 5:
            if(sorted == true){
                int key; 
                cout<<"Enter the key : ";
                cin>>key;
                listOne.mBinarySeach(key);
            }
            else{
                cout<<"ERROR : LIST NEEDS TO BE SORTED BEFORE BINARY SEARCH"<<endl;
            }
            break;
        default:
            cout<<"INVALID CASE"<<endl;
            break;
        }

        cout<<"Do you want to continue ? (0 for continuing and any other integer to terminate) : ";
        cin>>isRunning;
    }
    
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
    // listOne.insertionSorting();
    // listOne.quicksort(listOne.classroom, 0, maxClassSize-1);
    listOne.saveToCSV("csvFileOutput.csv");

<<<<<<< HEAD
=======


>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
    // listOne.displayNode(listOne.classroom[1]);
    // listOne.insertionSorting();
    // listOne.displayNode(listOne.classroom[1]);
    // listOne.mBinarySeach(3);
    // listOne.displayNode(listOne.mBinarySeach(6));

    return 0;
}