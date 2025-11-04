/*Department maintains student database. The file contains roll number, name,
division and address. Implement a CPP program to -
1. Create a sequential file to store and maintain student data.
2. It should allow the user to add and delete information of students.
3. Display information of particular student.
i. If the student record does not exist an appropriate message is displayed.
ii. If student record is found it should display the student details*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

// structure for a student record
struct studentRecord
{
    int rollNumber;
    string name;
    float gpa;

    // default constructor to initialize values
    studentRecord()
    {
        rollNumber = -1;
        name = "";
        gpa = 0.0;
    }
};

// defining node
typedef struct studentRecord student;

// defining a class to handle file operations for student records
class studentDatabase
{
private:
    // filename for the database
    string filename;

public:
    // defining all the functions
    void addRecord();
    void displayAllRecords();
    void displayRecord(int rollNumber);
    void deleteRecord(int rollNumber);
    void displayFunctions();
    bool searchRecord(int rollNumber, student &s);

    // constructor to initialize filename
    studentDatabase(string fname = "studentRecords.csv")
    {
        filename = fname;
    }
};

// adding a new record to existing file
void studentDatabase::addRecord()
{
    // opening file in append mode to add at the end
    ofstream file(filename, ios::app);
    
    // check if file opened successfully
    if (!file.is_open())
    {
        cout << "ERROR OPENING FILE! File may not exist. Create file first." << endl;
        return;
    }

    student s;
    cout << "\n--- Add New Student ---" << endl;
    
    // accepting student details
    cout << "Enter Roll Number: ";
    cin >> s.rollNumber;
    cin.ignore();
    
    cout << "Enter Name: ";
    getline(cin, s.name);
    
    cout << "Enter GPA: ";
    cin >> s.gpa;
    cin.ignore();

    // writing to CSV file
    file << s.rollNumber << ","
         << s.name << ","
         << s.gpa << "\n";

    // closing the file
    file.close();
    cout << "Student record added successfully!" << endl;
}

// searching for a specific student record by roll number
bool studentDatabase::searchRecord(int rollNumber, student &s)
{
    // opening file in read mode
    ifstream file(filename);
    
    // check if file opened successfully
    if (!file.is_open())
    {
        cout << "ERROR OPENING FILE!" << endl;
        return false;
    }

    string line;
    // reading file line by line
    while (getline(file, line))
    {
        // using stringstream to parse CSV line
        stringstream ss(line);
        string rollNumberString, nameString, gpaString;
        
        // parsing comma separated values
        getline(ss, rollNumberString, ',');
        getline(ss, nameString, ',');
        getline(ss, gpaString, ',');

        // converting roll number string to integer
        int roll = stoi(rollNumberString);
        
        // check if this is the record we're looking for
        if (roll == rollNumber)
        {
            // found the record! populate the student structure
            s.rollNumber = roll;
            s.name = nameString;
            s.gpa = stof(gpaString);
            
            file.close();
            return true;
        }
    }

    // record not found
    file.close();
    return false;
}

// displaying a particular student record
void studentDatabase::displayRecord(int rollNumber)
{
    student s;
    
    // search for the record
    if (searchRecord(rollNumber, s))
    {
        // record found! display it
        cout << "\n--- Student Record Found ---" << endl;
        cout << "Roll Number: " << s.rollNumber << endl;
        cout << "Name: " << s.name << endl;
        cout << "GPA: " << s.gpa << endl;
    }
    else
    {
        // record not found
        cout << "\nStudent with Roll Number " << rollNumber << " NOT FOUND!" << endl;
    }
}

// displaying all student records from file
void studentDatabase::displayAllRecords()
{
    // opening file in read mode
    ifstream file(filename);
    
    // check if file opened successfully
    if (!file.is_open())
    {
        cout << "ERROR OPENING FILE!" << endl;
        return;
    }

    cout << "\n=== All Student Records ===" << endl;
    cout << setw(10) << "Roll No" << setw(20) << "Name"
         << setw(10) << "GPA" << endl;
    cout << string(40, '-') << endl;

    string line;
    bool recordsFound = false;
    
    // reading file line by line
    while (getline(file, line))
    {
        recordsFound = true;
        
        // using stringstream to parse CSV line
        stringstream ss(line);
        string rollNumberString, nameString, gpaString;
        
        // parsing comma separated values
        getline(ss, rollNumberString, ',');
        getline(ss, nameString, ',');
        getline(ss, gpaString, ',');

        // displaying the record
        cout << setw(10) << rollNumberString
             << setw(20) << nameString
             << setw(10) << gpaString << endl;
    }

    // check if any records were found
    if (!recordsFound)
    {
        cout << "No records found in the database!" << endl;
    }

    // closing the file
    file.close();
}

// deleting a student record by roll number
void studentDatabase::deleteRecord(int rollNumber)
{
    // opening original file in read mode
    ifstream file(filename);
    
    // check if file opened successfully
    if (!file.is_open())
    {
        cout << "ERROR OPENING FILE!" << endl;
        return;
    }

    // creating temporary file to store records except the deleted one
    ofstream tempFile("temp.csv");
    
    // check if temp file created successfully
    if (!tempFile.is_open())
    {
        cout << "ERROR CREATING TEMPORARY FILE!" << endl;
        file.close();
        return;
    }

    string line;
    bool recordFound = false;

    // reading original file line by line
    while (getline(file, line))
    {
        // using stringstream to parse CSV line
        stringstream ss(line);
        string rollNumberString, nameString, gpaString;
        
        // parsing comma separated values
        getline(ss, rollNumberString, ',');
        getline(ss, nameString, ',');
        getline(ss, gpaString, ',');

        // converting roll number string to integer
        int roll = stoi(rollNumberString);

        // check if this is the record to be deleted
        if (roll == rollNumber)
        {
            recordFound = true;
            cout << "Deleting record of: " << nameString << endl;
            // skip writing this record to temp file (effectively deleting it)
        }
        else
        {
            // write this record to temp file (keeping it)
            tempFile << rollNumberString << ","
                     << nameString << ","
                     << gpaString << "\n";
        }
    }

    // closing both files
    file.close();
    tempFile.close();

    // delete original file and rename temp file to original filename
    remove(filename.c_str());
    rename("temp.csv", filename.c_str());

    // display appropriate message
    if (recordFound)
    {
        cout << "Student record deleted successfully!" << endl;
    }
    else
    {
        cout << "Student with Roll Number " << rollNumber << " NOT FOUND!" << endl;
    }
}

// displaying menu of available operations
void studentDatabase::displayFunctions()
{
    cout << "\n---------------------------------STUDENT DATABASE---------------------------------" << endl;
    cout << "1. Add Student Record" << endl;
    cout << "2. Display Particular Student" << endl;
    cout << "3. Display All Students" << endl;
    cout << "4. Delete Student Record" << endl;
    cout << "5. Exit" << endl;
}

int main()
{
    // creating an object of studentDatabase class
    studentDatabase database("studentRecords.csv");

    // variable for while statement
    int continueVar = 0;
    
    while (continueVar == 0)
    {
        // displays all the functions
        database.displayFunctions();
        
        cout << "Enter the operation to be performed: ";
        int op;
        cin >> op;
        
        // temp variable to store roll number for operations
        int rollNo = 0;
        
        switch (op)
        {
        case 1:
            // option to add a new record
            database.addRecord();
            break;
            
        case 2:
            // option to search and display a particular record
            cout << "Enter Roll Number to search: ";
            cin >> rollNo;
            database.displayRecord(rollNo);
            break;
            
        case 3:
            // option to display all records
            database.displayAllRecords();
            break;
            
        case 4:
            // option to delete a record
            cout << "Enter Roll Number to delete: ";
            cin >> rollNo;
            database.deleteRecord(rollNo);
            break;
            
        case 5:
            // option to exit the program
            cout << "Exiting program..." << endl;
            continueVar = 1;
            break;
            
        default:
            // default case if operation is invalid
            cout << "INVALID OPERATION!" << endl;
            break;
        }

        // ask user if they want to continue
        if (continueVar == 0)
        {
            cout << "\nDo you want to continue? (0 to continue, any other integer to exit): ";
            cin >> continueVar;
        }
    }

    return 0;
}