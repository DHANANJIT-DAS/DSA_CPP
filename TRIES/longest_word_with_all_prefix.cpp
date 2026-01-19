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

public:

    Node* root=new Node;


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

void find_string(Node* root,string &ans,string temp){

    for(auto x:root->children){
        if(x.second->end_of_Word==true){
            temp=temp+x.first;
            if(temp.size()==ans.size() && temp<ans || temp.size()>ans.size()){
                ans=temp;
            }
            find_string(x.second,ans,temp);
            temp=temp.substr(0,temp.size()-1);
        }
    }

}
string longest_word(vector<string>words){
    Trie T;
    for(int i=0;i<words.size();i++){
        T.insert(words[i]);
    }
    string ans="";
    string temp="";
    find_string(T.root,ans,temp);
    return ans;
}

int main(){
    vector<string>words={"a","bananna","ap","app","appl","apple","apply"};

    string ans=longest_word(words);
    cout<<ans;
    return 0;
}