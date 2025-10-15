#include<iostream>
#include<cstring>
using namespace std;

template <typename T> T myMax(T a, T b){
    T result; 
    result = (a>b)? a:b;
    return result;
}

int main(){

    cout << myMax<int>(3, 7) << endl;
    cout << myMax<double>(3.0, 7.0) << endl;
    cout << myMax<char>('g', 'e')<<endl;
    return 0;
}