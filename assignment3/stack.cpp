//23303
//assignment 3
<<<<<<< HEAD
//"Implementing Queues and Stacks Using Linked Lists for Real-World Task Management Systems" This problem involves designing and implementing queues and stacks using linked lists, focusing on their practical applications in real-world scenarios such as: • Task Scheduling System (Queue): Managing tasks in a first-in, first-out (FIFO) order, such as print job scheduling or process management in an operating system. • Undo/Redo Functionality (Stack): Implementing an undo/redo feature in text editors or design software using a last-in, first-out (LIFO) approach.
#include<iostream>
#include<cstring>

=======
#include<iostream>
#include<cstring>
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
using namespace std;


//structure to store data 
struct element{
<<<<<<< HEAD
    string data;
=======
    int data;
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
    struct element *next;
};

typedef struct element element;

//class to create a stack 
class stack{
    private:
    //top of the stack
    element *top;

    public:
<<<<<<< HEAD
    element *getElement(string data);
    void mPush(element *temp);
    string mPop();
    string mPeep();
=======
    element *getElement(int data);
    void mPush(element *temp);
    int mPop();
    int mPeep();
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
    void mInitialize();

    stack(){
        //constructor initializes the top and runs the initialize function
        top = NULL;
        mInitialize();
    }
};

//creates an element for the stack
<<<<<<< HEAD
element* stack::getElement(string data){
=======
element* stack::getElement(int data){
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
    //declaring a temp element
    element *temp;
    temp = new(element);
    //assigning values to temp element
    temp->data = data;
    temp->next = NULL;
    
    return temp;
}

//pushes an element into the stack
void stack::mPush(element *temp){
    //since get element returns null if there is no space left
    if(temp == NULL){
        cout<<endl<<"LIST IS FULL!!!"<<endl;
        return; 
    }
    //checking if top is null
    if(top == NULL){
        top = temp;
    }
    else{
        temp->next = top;
        top = temp;
    }
}

//initializing list, used in constructor
void stack::mInitialize(){
    int continueChecker = 0;
    while(continueChecker == 0){
<<<<<<< HEAD
        cout<<"enter string that will enter the stack : ";
        string x;
        cin.ignore();
        getline(cin, x);
=======
        cout<<"enter integer that will enter the stack : ";
        int x;
        cin>>x;
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
        mPush(getElement(x));
        cout<<"enter 0 to continue, any other integer to end : ";
        cin>>continueChecker;
        cout<<endl;
    }
}

//returns the top of the stack
<<<<<<< HEAD
string stack::mPeep(){
=======
int stack::mPeep(){
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
    cout<<top->data<<endl;
    return top->data;
}

//pops the data from the top of the stack and pops and returns it
<<<<<<< HEAD
string stack::mPop(){
    cout<<"Popped data : "<<top->data<<endl;
    element *temp = new(element);
    temp = top;
    string x;
=======
int stack::mPop(){
    cout<<"Popped data : "<<top->data<<endl;
    element *temp = new(element);
    temp = top;
    int x;
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
    x = temp->data;
    top = temp->next;
    delete temp;
    cout<<"Popped data cleared from memory"<<endl;
    return x;
}

int main(){
    //obj created, constructor called
    stack q;
    
    //while loop for continued operation
    int continueChecker = 0;
    while(continueChecker == 0){
        cout<<"--------------------------------------------STACK MENU--------------------------------------------"<<endl;
        cout<<"Operations : \n\t1.Push data\n\t2.Pop data\n\t3.Peep data"<<endl;
        cout<<"Enter operation : ";
        int operation;
        cin>>operation;
<<<<<<< HEAD
        string x;

=======
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3

        //switch case for operations
        switch (operation)
        {
        case 1:
            cout<<endl<<"Enter Data : ";
<<<<<<< HEAD
            cin.ignore();
            getline(cin, x);
=======
            int x;
            cin>>x;
>>>>>>> 3926075278d2e563d2f14a0bd4d300e6c0b2daa3
            //get element returns type element which is accepted by mPush fn 
            q.mPush(q.getElement(x));
            cout<<endl;
            cout<<"Data entered."<<endl;
            break;
        case 2: 
            q.mPop();
            break;
        case 3:
            q.mPeep();
            break;
        default:
            cout<<"INVALID ENTRY!!!"<<endl;
            break;
        }
        

        cout<<"enter 0 to continue, any other integer to end : ";
        cin>>continueChecker;
        cout<<endl;
    }
}