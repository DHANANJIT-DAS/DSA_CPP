#include<iostream>
#include<vector>
#include<string>
using namespace std;
template<class T>
class Stack{
    vector<T>stack;

    public:

    void push(T val){
        stack.push_back(val);
    }

    void pop(){
        if(! isEmpty()){
            stack.pop_back();
        }
        else{
            return;
        }
    }

    T top(){
        return stack[stack.size()-1];
    }

    bool isEmpty(){
        return stack.size()==0;
    }

};
int main(){

    Stack<string>s;
    s.push("Dhananjit");
    s.push("am");
    s.push("I");
    while(! s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}