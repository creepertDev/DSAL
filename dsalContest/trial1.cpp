#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define strLen 11

struct list{
    char listed;
    int count;
    struct list *next;
};

typedef class list list;

class checkerObj{
    string enteredStr;
    list *headVovels = NULL;
    list *headConsonants = NULL;
    char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    
    public:
    
    void checkerFn();
    
    void enterElement(char tempChar, bool flag);
    void displayLists();
    checkerObj(string m){
        enteredStr = m;
        checkerFn();
        displayLists();
    };
};

void checkerObj::enterElement(char tempChar, bool flag){
    list *temp;
    temp = new(list);
    temp->listed = tempChar;
    temp->count = 1;
    temp->next = NULL;
    
    if(flag){
        if(headVovels == NULL){
            headVovels = temp;
        }
        else{
            list *c;
            c = headVovels;
            while(c->next != NULL){
                c = c->next;
            }
            ++headVovels->count;
            c->next = temp;            
        }
    }
    else{
        if(headConsonants == NULL){
            headConsonants = temp;
        }
        else{
            list *t;
            t = headConsonants;
            while(t->next != NULL){
                t = t->next;
            }
            ++headConsonants->count;
            t->next = temp;            
        }
    }
    return;
}

void checkerObj::checkerFn(){
    for(size_t i=0;i<enteredStr.length();i++){
        bool isVovel = false;
        
        for(int j=0;j<10;j++){
            if(enteredStr[i]==vowels[j]){
                isVovel = true;
                break;
            }
        }
        enterElement(enteredStr[i], isVovel);
    }
}

void checkerObj::displayLists(){
    list *c,*t;
    c = headVovels;
    t = headConsonants;
    cout<<"Vowels: = ";
    while(c!=NULL){
        cout<<c->listed;
        if(c->next!= NULL){
            cout<<"-->";
        }
        c=c->next;
    }
    cout<<" Consonents: = ";
    while(t!=NULL){
        cout<<t->listed;
        if(t->next!= NULL){
            cout<<"-->";
        }
        t=t->next;
    }
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string input;
    cin>>input;
    
    checkerObj checkerFns(input);
    
    return 0;
}
