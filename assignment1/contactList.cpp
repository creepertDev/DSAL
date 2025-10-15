//23303
//assignment1
//"Efficient Data Management Using Linked Lists: Implementing Dynamic Operations for Contact Management System" Utilize Singly and Doubly Linked Lists to manage a Contact Management System. The system will support key operations such as: • Creating a contact list dynamically. • Adding new contacts efficiently. • Deleting contacts when no longer needed. • Searching for specific contacts based on name or number. • Reversing the contact list for alternate viewing orders. • Traversing through the list to display all stored contacts.

#include<iostream>
#include<cstring>
using namespace std;


struct contact{
    string name; 
    string phoneNumber;
    string email;
    string address;
    struct contact *next;
};

class contactList{
    //declarations
    private:
    struct contact *head;
    
    public:
    bool validator(struct contact *t);
    bool emailChecker(string email);
    bool phoneNumberChecker(string phoneNumberEntered);
    void insert();
    void insertStart();
    void insertEnd();
    void display();
    void display(struct contact *t);
    void init(); 
    //searches  by name
    string search(string sName);
    void deleteNode();
    void contactReverse();
    
    //input fn to be reused by all other fns
    struct contact *inputFn(){
        struct contact *t;
        t = new(struct contact);
        // cin.clear();
        cout<<"Enter the name : ";
        cin.ignore();
        getline(cin,t->name);
        cout<<"Enter the number : ";
        // cin.ignore();
        cin>>t->phoneNumber;
        cout<<"Enter the email : ";
        cin>>t->email;
        cout<<"Enter the address : ";
        cin.ignore();
        getline(cin, t->address);
        if (!validator(t))
        {
            cout<<"INVALID INPUT";
            delete t;
            return inputFn();
        }
        
        return t;
    }

    //constructor 
    contactList(){
        head = NULL;
    }
};

//delete a node
void contactList::deleteNode(){
    struct contact *s,*t;
    cout<<"Enter contact number to be deleted : ";
    cin.ignore();
    string numberTBD;
    cin>>numberTBD;

    s=head;
    while (strcmp(s->phoneNumber.c_str(),numberTBD.c_str())!=0)
    {
        t = s;
        s = s->next;
    }
    if (s == head)
    {
        head = head->next;
    }
    else{
        t->next = s->next;
    }
    delete s;
}

//email validity checker
bool contactList::emailChecker(string email){
    int atTheRatePos = email.find('@');
    //find function returns -1 by default
    if (atTheRatePos == 0 || atTheRatePos == -1)
    {
        return false;
    }
    int dotPos = email.find('.');
    if(dotPos<(atTheRatePos+2)){
        return false;
    }
    if ((email.length() - dotPos) <= 2)
    {
        return false;
    }
    
    return true;
}

//phone number checker
bool contactList::phoneNumberChecker(string phoneNumberEntered){
    int length = phoneNumberEntered.length();
    if (length==10)
    {
        if (phoneNumberEntered[0]==0)
        {
            return false;
        }
        else {
            return true;
        }
        
    }
    else {
        return false;
    }
    return true;    
}

//validator fn, checking for 10 digit no, first character of the name should not be a number, email id should have a @ followed by a min of 2 characters and then a . after which there should be atleast 2 characters
bool contactList::validator(struct contact *t){
    if(!phoneNumberChecker(t->phoneNumber)){
        return false;
    }
    if (!emailChecker(t->email))
    {
        cout<<"Email invalid";
        return false;
    }
    if(t->name[0] >= '0' && t->name[0] <= '9'){
        cout<<"Name invalid";
        return false;
    }
    return true;
}

//initializing a list
void contactList::init(){
    struct contact *t,*p;

    int cont = 0;
    while (cont == 0)
    {
        t = inputFn();
        t->next = NULL;
        if (head == NULL)
        {
            head = t;
            p = t;
        }
        else{
            p->next = t;
            p = t;
        }
        
        cout<<"Do you want to enter another contact?(0 to continue, anything else to termniate) : ";
        cin>>cont;
    }
    return;
}

//inserting an element after the nth position
void contactList::insert(){
    struct contact *t;
    t = inputFn();
    t->next = NULL;
    cout<<"Enter the location after which it is to be entered";
    int locationN;
    cin>>locationN;
    struct contact *p;
    p = head;
    //search for the n-1 th pos
    for (int i = 0;i<locationN - 1;i++)
    {
        if (p->next == NULL)
        {
            cout<<"OUT OF BOUNDS!! CONTACT NOT SAVED"<<endl;
            return;
        }
        p=p->next;
    }
    t->next = p->next;
    p->next = t;
    return;
}

//inserting an element at the end 
void contactList::insertEnd(){
    struct contact *t,*p;
    t = inputFn();
    t->next=NULL;
    if (head == NULL)
    {
        head = t;
    }
    p=head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = t;    
    return;
}

//inserting an element at the start i.e first node
void contactList::insertStart(){
    struct contact *t,*p;
    t = inputFn();
    t->next=NULL;
    p = head;
    t->next = p;
    head = t;    
    return;
}

//displaying ALL the nodes 
void contactList::display(){
    if(head!=NULL){
        struct contact*p;
        p=head;
        int i = 1;
        cout<<endl<<"-------------------------------PHONEBOOK-------------------------------"<<endl;
        while (p!=NULL)
        {
            cout<<i<<" . "<<p->phoneNumber<<"\t"<<p->name<<"\t"<<p->email<<"\t"<<p->address<<endl;
            p=p->next;
            i++;
        }
        return;
    }
    else{
        cout<<"No elements in the list!!";
        return;
    }
}

//displaying a node passed to the display function
void contactList::display(struct contact *t){
    cout<<endl<<"Record found :"<<endl;
    cout<<t->phoneNumber<<"\t"<<t->name<<"\t"<<t->email<<"\t"<<t->address<<endl;
}

//searchng for a particular contact using a name
string contactList::search(string sName){
    struct contact*p;
    p=head;
    while (p!= NULL && strcmp(p->name.c_str(),sName.c_str())!=0)
    {
        p=p->next;
        
    }
    if (p == NULL)
    {
        cout<<"CONTACT NOT FOUND!!"<<endl;
        return 0;
    }
    
    display(p);
    return p->phoneNumber;
}

//reversing a list
void contactList::contactReverse(){
    struct contact *c,*t,*r;
    t = NULL;
    r = NULL;
    c = head;
    if (head->next == NULL)
    {
        return;
    }
    while (c != NULL)
    {
        t = c->next;
        c -> next = r;
        r = c;
        c = t;
    }
    head = r;
    return;    
}

int main(){
    contactList phoneBook;
    cout<<"-------------------------------PHONEBOOK-------------------------------"<<endl;
    //checker or initialization
    bool initCheck = false;
    if (initCheck == false)
    {
        phoneBook.init();
        initCheck = true;
    }
    //temp string for the name input incase user exercises option 5 in switch case below
    string temp;

    //while loop with is running checker, runs till number other than 0 is entered 
    int isRunning = 0;
    while (isRunning == 0)
    {
        cout<<"Enter the operation:"<<endl<<"\t1.Add contact anywhere\n\t2.Add Contact at the end\n\t3.Add contact at the start\n\t4.Display Contacts\n\t5.Search by name\n\t6.Reverse the contact list\n\t7.Delete a contact"<<endl;
        int j;
        cin>>j;
        
        switch (j)
        {
        case 1:
            phoneBook.insert();
            break;
        case 2:
            phoneBook.insertEnd();
            break;
        case 3:
            phoneBook.insertStart();
            break;
        case 4:
            phoneBook.display();
            break;
        case 5:
            cout<<"Enter the name : ";
            cin>>temp;
            phoneBook.search(temp);
            break;
        case 6:
            phoneBook.contactReverse();
            break;
        case 7:
            phoneBook.deleteNode();
            break;
        default:
            cout<<"INVALID INPUT"<<endl;
            break;
        }
        
        cout<<"Continue operations ? (0 to continue, anything else to termniate) : ";
        cin>>isRunning;
    }
    return 0;
}


/*-------------------------------PHONEBOOK-------------------------------
Enter the name : John
Enter the number : 1234567890
Enter the email : john@example.com
Enter the address : 123 Main St
Do you want to enter another contact?(0 to continue, anything else to termniate) : 0
Enter the name : Jane
Enter the number : 9876543210
Enter the email : jane@example.com
Enter the address : 456 Oak Ave
Do you want to enter another contact?(0 to continue, anything else to termniate) : 1
Enter the operation:
1.Add contact anywhere
2.Add Contact at the end
3.Add contact at the start
4.Display Contacts
5.Search by name
6.Reverse the contact list
7.Delete a contact
4
-------------------------------PHONEBOOK-------------------------------
1 . 1234567890	John	john@example.com	123 Main St
2 . 9876543210	Jane	jane@example.com	456 Oak Ave
Continue operations ? (0 to continue, anything else to termniate) : 0
Enter the operation:
1.Add contact anywhere
2.Add Contact at the end
3.Add contact at the start
4.Display Contacts
5.Search by name
6.Reverse the contact list
7.Delete a contact
5
Enter the name : John
Record found :
1234567890	John	john@example.com	123 Main St
Continue operations ? (0 to continue, anything else to termniate) : 0
Enter the operation:
1.Add contact anywhere
2.Add Contact at the end
3.Add contact at the start
4.Display Contacts
5.Search by name
6.Reverse the contact list
7.Delete a contact
6
Continue operations ? (0 to continue, anything else to termniate) : 0
Enter the operation:
1.Add contact anywhere
2.Add Contact at the end
3.Add contact at the start
4.Display Contacts
5.Search by name
6.Reverse the contact list
7.Delete a contact
4
-------------------------------PHONEBOOK-------------------------------
1 . 9876543210	Jane	jane@example.com	456 Oak Ave
2 . 1234567890	John	john@example.com	123 Main St
Continue operations ? (0 to continue, anything else to termniate) : 0
Enter the operation:
1.Add contact anywhere
2.Add Contact at the end
3.Add contact at the start
4.Display Contacts
5.Search by name
6.Reverse the contact list
7.Delete a contact
7
Enter contact number to be deleted : 1234567890
Continue operations ? (0 to continue, anything else to termniate) : 0
Enter the operation:
1.Add contact anywhere
2.Add Contact at the end
3.Add contact at the start
4.Display Contacts
5.Search by name
6.Reverse the contact list
7.Delete a contact
4
-------------------------------PHONEBOOK-------------------------------
1 . 9876543210	Jane	jane@example.com	456 Oak Ave
Continue operations ? (0 to continue, anything else to termniate) : 1*/