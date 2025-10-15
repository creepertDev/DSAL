// 23303
// assignment 3
//"Implementing Queues and Stacks Using Linked Lists for Real-World Task Management Systems" This problem involves designing and implementing queues and stacks using linked lists, focusing on their practical applications in real-world scenarios such as: • Task Scheduling System (Queue): Managing tasks in a first-in, first-out (FIFO) order, such as print job scheduling or process management in an operating system. • Undo/Redo Functionality (Stack): Implementing an undo/redo feature in text editors or design software using a last-in, first-out (LIFO) approach.
#include<iostream>
#include<cstring>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

//priority enum declaration
enum taskPriority{
    high = 1,
    medium = 2,
    low = 3
};

//structure to store task
struct element{
    string title; 
    taskPriority priority;
    int weight;
    struct element *next;
};

typedef struct element element;

//class to create a queue 
class queue{
    private:
    //top and end of the queue
    element *top;
    element *end;

    public:
    void loadCSV(string csvFile);
    void saveToCSV(string csvFile);
    taskPriority priorityDecider(int x);
    taskPriority priorityDecider(string x);

    element *getElement(int weight, string title, taskPriority priority);
    void mPush(element *temp);
    int mPop();
    int mPeep();

    queue(){
        //constructor initializes the top and end
        top = NULL;
        end = NULL;
    }
};

//decidin the priority based either using an int or a string
taskPriority queue::priorityDecider(int x){
    switch (x)
    {
    case 1:
        return high;
        break;
    case 2:
        return medium;
        break;
    case 3:
        return low;
        break;
    default:
        return low; 
        break;
    }
}
taskPriority queue::priorityDecider(string x){
    taskPriority p;
    if (x == "High" || x == "high"){
        p = high;
    }
    else if (x == "Medium" || x == "medium"){
        p = medium;
    }
    else if (x == "Low" || x == "low"){ 
        p = low;
    }
    else {
        p = low;
    }
    return p;
}

//loading the data from a csv file
void queue::loadCSV(string csvFile){
    ifstream file(csvFile);
    if(!file.is_open()){
        cout<<"ERROR OPENING FILE"<<endl;
        return;
    }

    string t;
    int i = 0;
    while(getline(file, t)){
        stringstream ss(t);
        string title, time, priority;
        getline(ss, title, ',');
        getline(ss, time, ',');
        getline(ss, priority, ',');
        int timeInt = stoi(time);
        taskPriority p = priorityDecider(priority);
        mPush(getElement(timeInt, title, p));
    }
    file.close();
    cout<<"Data ingested from : "<<csvFile<<endl;
}

//saving the list to a csv file
void queue::saveToCSV(string csvFile){
    ofstream file(csvFile);
    if(!file.is_open()){
        cout<<"ERROR OPENING FILE"<<endl;
    }
    element *temp = top;
    while(temp != NULL){
        string priorityStr;
        switch(temp->priority) {
            case high: 
                priorityStr = "High"; 
                break;
            case medium: 
                priorityStr = "Medium"; 
                break;
            case low: 
                priorityStr = "Low"; 
                break;
        }
        file << temp->title << "," << temp->weight << "," << priorityStr << "\n";
        temp = temp->next;
    }

    file.close();
    cout<<"Data saved to : "<<csvFile<<endl;
}

//creates an element for the queue
element* queue::getElement(int weight, string title, taskPriority priority){
    //declaring a temp element
    element *temp = new element;
    //assigning values to temp element
    temp->title = title;
    temp->weight = weight;
    temp->priority = priority;
    temp->next = NULL;
    
    return temp;
}

//pushes an element into the queue
void queue::mPush(element *temp){
    //since get element returns null if there is no space left
    if(temp == NULL){
        cout<<endl<<"LIST IS FULL!!!"<<endl;
        return; 
    }
    //checking if top is null
    if(top == NULL){
        top = temp;
        end = temp;
    }
    else{
        end->next = temp;
        end = temp;
    }
}

//returns the top of the queue
int queue::mPeep(){
    cout<<"Time : "<<top->weight<<"\t Task : "<<top->title<<"\tPriority :"<<top->priority<<endl;
    return top->weight;
}

//pops the weight from the top of the queue and pops and returns it
int queue::mPop(){
    if(top == NULL){
        cout<<"NO ELEMENTS IN THE LIST"<<endl;
        return 0;
    }
    cout<<"Popped task : "<<top->title<<endl;
    element *temp = new(element);
    temp = top;
    int x;
    x = temp->weight;
    top = temp->next;
    delete temp;
    cout<<"Popped task cleared from memory"<<endl;
    return x;
}


int main(){
    //obj created, constructor called
    queue q;
    
    //while loop for continued operation
    int continueChecker = 0;
    q.loadCSV("csvIngestFile.csv");
    while(continueChecker == 0){
        cout<<"--------------------------------------------TASK MENU--------------------------------------------"<<endl;
        cout<<"Operations : \n\t1.Push task\n\t2.Pop task\n\t3.Peep task"<<endl;
        cout<<"Enter operation : ";
        int operation;
        cin>>operation;
        string tempt;

        //switch case for operations
        switch (operation)
        {
        case 1:
            //entering a new task 
            cout<<"Enter time taken for the task : ";
            int x;
            cin>>x;
            cout<<"Enter the name of the task : ";
            cin.ignore();
            getline(cin, tempt);
            cout<<"Enter priority (1:High, 2:Medium, 3:Low): ";
            int y;
            cin>>y;
            //get element returns type element which is accepted by mPush fn 
            q.mPush(q.getElement(x, tempt,q.priorityDecider(y)));
            cout<<endl;
            cout<<"task entered."<<endl;
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
    q.saveToCSV("csvOutputFile.csv");
    return 0;
}