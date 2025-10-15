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

#define tableSize 10

struct node
{
    char data[50];
    struct node *next;
    node()
    {
        next = NULL;
    }
};

typedef struct node node;

class hashTableChaining
{
private:
    node *head[tableSize];
    int hashFunction(const char *key);

public:
    void insert(const char *value);
    bool search(const char *value);
    void remove(const char *value);
    void display();
    void csvIngest(const string &filename);
    hashTableChaining()
    {
        for (int i = 0; i < tableSize; i++)
        {
            head[i] = NULL;
        }
    }
};

class hashTableOpenAddressing
{
private:
    char table[tableSize][50];
    bool occupied[tableSize];

    int hashFunction(const char *key);

public:
    void insert(const char *value);
    bool search(const char *value);
    void remove(const char *value);
    void display();
    void csvIngest(const string &filename);
    hashTableOpenAddressing()
    {
        for (int i = 0; i < tableSize; i++)
        {
            table[i][0] = '\0';
            occupied[i] = false;
        }
    }
};

int hashTableChaining::hashFunction(const char *key)
{
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        sum += key[i];
    }
    return sum % tableSize;
}

void hashTableChaining::insert(const char *value)
{
    int index = hashFunction(value);
    node *newNode = new node;
    strcpy(newNode->data, value);
    head[index] = newNode;
}

bool hashTableChaining::search(const char *value)
{
    int index = hashFunction(value);
    node *temp = head[index];
    while (temp)
    {
        if (strcmp(temp->data, value) == 0)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void hashTableChaining::remove(const char *value)
{
    int index = hashFunction(value);
    node *temp = head[index];
    node *prev = NULL;

    while (temp != NULL && strcmp(temp->data, value) != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }
    if (prev == NULL)
    {
        head[index] = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    delete temp;
}

void hashTableChaining::display()
{
    cout << "\n---Hash Table (Chainging)---\n";
    for (int i = 0; i < tableSize; i++)
    {
        cout << "[" << i << "] -> ";
        node *temp = head[i];
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

void hashTableChaining::csvIngest(const string &filename)
{
    ifstream file(filename.c_str());
    if (!file.is_open())
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string token;
        while (getline(ss, token, ','))
        {
            insert(token.c_str());
        }
    }
    cout << "Data ingested into chaining hash table form " << filename << endl;
    file.close();
    return;
}

int hashTableOpenAddressing::hashFunction(const char *key)
{
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        sum += key[i];
    }
    return sum % tableSize;
}

void hashTableOpenAddressing::insert(const char *value)
{
    int index = hashFunction(value);
    int start = index;
    do
    {
        if (!occupied[index])
        {
            strcpy(table[index], value);
            occupied[index] = true;
            return;
        }
        index = (index + 1) % tableSize;
    } while (index != start);
    cout << "Table is full! cannot insert";
}

bool hashTableOpenAddressing::search(const char *value)
{
    int index = hashFunction(value);
    int start = index;
    do
    {
        if (occupied[index] && strcmp(table[index], value) == 0)
        {
            return true;
        }
        if (!occupied[index])
        {
            return false;
        }
        index = (index + 1) % tableSize;
    } while (index != start);
    return false;
}

void hashTableOpenAddressing::remove(const char *value)
{
    int index = hashFunction(value);
    int start = index;
    do
    {
        if (occupied[index] && strcmp(table[index], value) == 0)
        {
            occupied[index] = false;
            table[index][0] = '\0';
            cout << value << "deleted." << endl;
            return;
        }
        index = (index + 1) % tableSize;
    } while (index != start);
    cout << value << "not found" << endl;
    return;
}

void hashTableOpenAddressing::display()
{
    cout << endl
         << "---Hash Table (Open Addressing)---" << endl;
    for (int i = 0; i < tableSize; i++)
    {
        cout << "[" << i << "] : ";
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

void hashTableOpenAddressing::csvIngest(const string &filename)
{
    ifstream file(filename.c_str());
    if (!file.is_open())
    {
        cout << "Error opening file : " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string token;
        while (getline(ss, token, ','))
        {
            insert(token.c_str());
        }
    }
    cout << "Data ingested into open addressing hash table from " << filename << endl;
    file.close();
}

int main()
{
    hashTableChaining chainingTable;
    hashTableOpenAddressing openAddressTable;
    chainingTable.csvIngest("users.csv");
    openAddressTable.csvIngest("users.csv");
    chainingTable.display();
    openAddressTable.display();
    chainingTable.search("user1");

    return 0;
}