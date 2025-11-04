// 23303
/*To design and implement a secure system for storing user credentials using hashing techniques
and to demonstrate collision resolution using chaining and open addressing*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <iomanip>
#include <functional>
#include <cstring>
using namespace std;

// defining the size of hash table
#define tableSize 10

// structure for a node in the linked list (used for chaining)
struct node
{
    char data[50];
    struct node *next;
    
    // default constructor to initialize next pointer
    node()
    {
        next = NULL;
    }
};

// defining node as a type
typedef struct node node;

// class for hash table using chaining collision resolution
class hashTableChaining
{
private:
    // array of pointers to head nodes for each bucket
    node *head[tableSize];
    
    // hash function to calculate index from key
    int hashFunction(const char *key);

public:
    // function to insert a value into hash table
    void insert(const char *value);
    
    // function to search for a value in hash table
    bool search(const char *value);
    
    // function to remove a value from hash table
    void remove(const char *value);
    
    // function to display entire hash table
    void display();
    
    // function to ingest data from CSV file
    void csvIngest(const string &filename);
    
    // constructor to initialize all head pointers to NULL
    hashTableChaining()
    {
        for (int i = 0; i < tableSize; i++)
        {
            head[i] = NULL;
        }
    }
};

// class for hash table using open addressing collision resolution
class hashTableOpenAddressing
{
private:
    // array to store the data
    char table[tableSize][50];
    
    // array to track which slots are occupied
    bool occupied[tableSize];

    // hash function to calculate index from key
    int hashFunction(const char *key);

public:
    // function to insert a value into hash table
    void insert(const char *value);
    
    // function to search for a value in hash table
    bool search(const char *value);
    
    // function to remove a value from hash table
    void remove(const char *value);
    
    // function to display entire hash table
    void display();
    
    // function to ingest data from CSV file
    void csvIngest(const string &filename);
    
    // constructor to initialize all slots as empty
    hashTableOpenAddressing()
    {
        for (int i = 0; i < tableSize; i++)
        {
            table[i][0] = '\0';
            occupied[i] = false;
        }
    }
};

// hash function for chaining - calculates sum of ASCII values mod table size
int hashTableChaining::hashFunction(const char *key)
{
    int sum = 0;
    
    // iterate through each character and add ASCII value
    for (int i = 0; key[i] != '\0'; i++)
    {
        sum += key[i];
    }
    
    // return the index using modulo operation
    return sum % tableSize;
}

// insert function for chaining - adds new node at beginning of chain
void hashTableChaining::insert(const char *value)
{
    // calculate the hash index for this value
    int index = hashFunction(value);
    
    // create a new node
    node *newNode = new node;
    strcpy(newNode->data, value);
    
    // insert at the beginning of the chain (head insertion)
    newNode->next = head[index];
    head[index] = newNode;
}

// search function for chaining - traverses chain to find value
bool hashTableChaining::search(const char *value)
{
    // calculate the hash index for this value
    int index = hashFunction(value);
    
    // start from the head of the chain at this index
    node *temp = head[index];
    
    // traverse the linked list
    while (temp)
    {
        // check if current node contains the value
        if (strcmp(temp->data, value) == 0)
        {
            return true;
        }
        temp = temp->next;
    }
    
    // value not found in the chain
    return false;
}

// remove function for chaining - deletes node from chain
void hashTableChaining::remove(const char *value)
{
    // calculate the hash index for this value
    int index = hashFunction(value);
    
    // pointers to traverse the chain
    node *temp = head[index];
    node *prev = NULL;

    // find the node to be deleted
    while (temp != NULL && strcmp(temp->data, value) != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    
    // if value not found, return
    if (temp == NULL)
    {
        return;
    }
    
    // if node to be deleted is the head
    if (prev == NULL)
    {
        head[index] = temp->next;
    }
    else
    {
        // link previous node to next node
        prev->next = temp->next;
    }
    
    // delete the node
    delete temp;
}

// display function for chaining - shows entire hash table structure
void hashTableChaining::display()
{
    cout << "\n---Hash Table (Chaining)---\n";
    
    // iterate through each bucket
    for (int i = 0; i < tableSize; i++)
    {
        cout << "[" << i << "] -> ";
        
        // traverse the chain at this bucket
        node *temp = head[i];
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

// CSV ingest function for chaining - reads data from file and inserts
void hashTableChaining::csvIngest(const string &filename)
{
    // open the CSV file
    ifstream file(filename.c_str());
    
    // check if file opened successfully
    if (!file.is_open())
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    
    string line;
    
    // read file line by line
    while (getline(file, line))
    {
        // use stringstream to parse CSV
        stringstream ss(line);
        string token;
        
        // extract each comma-separated token
        while (getline(ss, token, ','))
        {
            // insert each token into hash table
            insert(token.c_str());
        }
    }
    
    cout << "Data ingested into chaining hash table from " << filename << endl;
    
    // close the file
    file.close();
    return;
}

// hash function for open addressing - same as chaining
int hashTableOpenAddressing::hashFunction(const char *key)
{
    int sum = 0;
    
    // iterate through each character and add ASCII value
    for (int i = 0; key[i] != '\0'; i++)
    {
        sum += key[i];
    }
    
    // return the index using modulo operation
    return sum % tableSize;
}

// insert function for open addressing - uses linear probing
void hashTableOpenAddressing::insert(const char *value)
{
    // calculate the initial hash index
    int index = hashFunction(value);
    int start = index;
    
    // linear probing to find empty slot
    do
    {
        // if slot is empty, insert here
        if (!occupied[index])
        {
            strcpy(table[index], value);
            occupied[index] = true;
            return;
        }
        
        // move to next slot (circular)
        index = (index + 1) % tableSize;
        
    } while (index != start); // stop if we've checked all slots
    
    // table is full if we return to starting position
    cout << "Table is full! cannot insert" << endl;
}

// search function for open addressing - uses linear probing
bool hashTableOpenAddressing::search(const char *value)
{
    // calculate the initial hash index
    int index = hashFunction(value);
    int start = index;
    
    // linear probing to search
    do
    {
        // if slot is occupied and contains our value
        if (occupied[index] && strcmp(table[index], value) == 0)
        {
            return true;
        }
        
        // if we hit an empty slot, value doesn't exist
        if (!occupied[index])
        {
            return false;
        }
        
        // move to next slot (circular)
        index = (index + 1) % tableSize;
        
    } while (index != start); // stop if we've checked all slots
    
    // value not found
    return false;
}

// remove function for open addressing - marks slot as unoccupied
void hashTableOpenAddressing::remove(const char *value)
{
    // calculate the initial hash index
    int index = hashFunction(value);
    int start = index;
    
    // linear probing to find value
    do
    {
        // if slot is occupied and contains our value
        if (occupied[index] && strcmp(table[index], value) == 0)
        {
            // mark slot as unoccupied
            occupied[index] = false;
            table[index][0] = '\0';
            cout << value << " deleted." << endl;
            return;
        }
        
        // move to next slot (circular)
        index = (index + 1) % tableSize;
        
    } while (index != start); // stop if we've checked all slots
    
    // value not found
    cout << value << " not found" << endl;
    return;
}

// display function for open addressing - shows table contents
void hashTableOpenAddressing::display()
{
    cout << endl << "---Hash Table (Open Addressing)---" << endl;
    
    // iterate through each slot
    for (int i = 0; i < tableSize; i++)
    {
        cout << "[" << i << "] : ";
        
        // check if slot is occupied
        if (occupied[i])
        {
            cout << table[i];
        }
        else
        {
            cout << "Empty";
        }
        cout << endl;
    }
    return;
}

// CSV ingest function for open addressing - reads data from file
void hashTableOpenAddressing::csvIngest(const string &filename)
{
    // open the CSV file
    ifstream file(filename.c_str());
    
    // check if file opened successfully
    if (!file.is_open())
    {
        cout << "Error opening file : " << filename << endl;
        return;
    }
    
    string line;
    
    // read file line by line
    while (getline(file, line))
    {
        // use stringstream to parse CSV
        stringstream ss(line);
        string token;
        
        // extract each comma-separated token
        while (getline(ss, token, ','))
        {
            // insert each token into hash table
            insert(token.c_str());
        }
    }
    
    cout << "Data ingested into open addressing hash table from " << filename << endl;
    
    // close the file
    file.close();
}

int main()
{
    // creating hash table objects for both methods
    hashTableChaining chainingTable;
    hashTableOpenAddressing openAddressTable;
    
    // ingesting data from CSV file into both tables
    chainingTable.csvIngest("users.csv");
    openAddressTable.csvIngest("users.csv");
    
    // displaying both hash tables
    chainingTable.display();
    openAddressTable.display();
    
    // searching for a value in chaining table
    cout << "\nSearching for 'user1' in chaining table: " 
         << (chainingTable.search("user1") ? "FOUND" : "NOT FOUND") << endl;

    return 0;
}