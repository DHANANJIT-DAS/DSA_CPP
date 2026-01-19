#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void printList(list<int>ll){
    list<int>:: iterator itr;
    for(itr=ll.begin();itr !=ll.end();itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;
}


int main(){
    list<int>ll;

    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);
    ll.push_back(9);
    ll.push_back(10);
    ll.push_front(2);
    ll.push_front(1);
    printList(ll);
    cout<<ll.size()<<endl;
    cout<<ll.front()<<endl;
    cout<<ll.back();
    

    
    return 0;
}


// In STL we can't access head pointer and cant modify the list with pointer