#include<iostream>
#include<stack>
#include<string>
using namespace std;

struct node{
    int x;
    string s;
};

typedef struct node node;

ostream & operator<<(ostream & outs, node & nodeE){
    return outs<<nodeE.s<<", "<<nodeE.x<<endl;
}

int main(){
    stack<node> x;
    node y;
    y.s = "yes ths is a node";
    y.x = 10;
    x.push(y);
    cout<<x.top()<<endl;
}