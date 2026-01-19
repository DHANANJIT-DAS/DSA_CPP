#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
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

    bool startsWith(string prefix){
        Node* temp=root;

        for(int i=0;i<prefix.size();i++){
            if(temp->children.count(prefix[i])){
                temp=temp->children[prefix[i]];
            }
            else{
                return false;
            }
        }
        return true;
    }
};


int main(){
    vector<string>words={"Dhananjit","Ankan","Ashish"};
    Trie T;
    for(int i=0;i<words.size();i++){
        T.insert(words[i]);
    }
    // cout<<T.search("ankan");

    cout<<T.startsWith("ab");

    return 0;
}