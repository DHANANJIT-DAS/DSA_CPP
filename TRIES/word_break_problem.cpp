#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


class Node{

public:
    unordered_map<char,Node*>children;
    bool end_of_Word;

    Node(){
        end_of_Word=false;
    }
};

class Trie{

    Node* root=new Node;
public:

    void insert(string key){    // O(L)
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node;
            }
            temp=temp->children[key[i]];
        }
        temp->end_of_Word=true;
    }

    bool search(string key){    // O(L)
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])){
                temp=temp->children[key[i]];
            }
            else{
                return false;
            }
        }
        return temp->end_of_Word;
    }
};


bool isFound(string str,Trie &T){
    if(str.size()==0){
        return true;
    }
    for(int i=1;i<=str.size();i++){
        string first=str.substr(0,i);
        string second=str.substr(i,str.length()-i);
        if(T.search(first)){
            return isFound(second,T);
        }
    }
    return false;

}

bool word_break(vector<string>words,string key){
    Trie T;
    for(int i=0;i<words.size();i++){
        T.insert(words[i]);
    }
    return isFound(key,T);
}

int main(){
    vector<string>words={"I","Love","You"};
    string key="ILoveIndia";
    cout<<word_break(words,key);
    return 0;
}