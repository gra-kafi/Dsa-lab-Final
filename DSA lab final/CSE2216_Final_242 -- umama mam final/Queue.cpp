#include<iostream>
#include<queue>
using namespace std;

//add necessary code here

int main(){
    int x;
    myQueue m;
    while(1){
        cout<<"enter x:";
        cin>>x;
        m.Insert(x);
        m.display();
    }
}

