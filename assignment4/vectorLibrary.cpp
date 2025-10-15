#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main (){
	int n;
    cout<<"Enter number of inputs : ";
    cin>>n;

	vector <int> ivec(n);

    for(int i = 0;i<n;i++){
        cout<<"Enter number "<<i+1<<" : ";
        cin>>ivec[i];
    }

    sort(ivec.begin(), ivec.end());
    for(int i = 0;i<n;i++){
        cout<<ivec[i]<<" , ";
    }
    
}