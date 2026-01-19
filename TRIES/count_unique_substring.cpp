#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Node{
public:
    unordered_map<char,Node*>children;
    bool end_of_word;

    Node(){
        end_of_word=false;
    }
};

class Trie{

    Node* root;
public:

    Trie(){
        root=new Node;
    }

    void insert(string key){
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node;
            }
            temp=temp->children[key[i]];
        }
        temp->end_of_word=true;
    }


    bool search(string key){
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])){
                temp=temp->children[key[i]];
            }
            else{
                return false;
            }
        }
        return temp->end_of_word;
    }

    int count_Node_rec(Node* root){
        int count=0;
        for(auto x:root->children){
            count=count+count_Node_rec(x.second);
        }
        return count+1;
    }

    int count_Node(){

        return count_Node_rec(root);
    }

};


int find_unique_substring(string word){   // total no of unique prefix of sufix of the word
    Trie T;
    for(int i=0;i<word.size();i++){
        T.insert(word.substr(i));
    }

    return T.count_Node();

}
int main(){

    string word="abc";

    int substring_count=find_unique_substring(word);
    cout<<substring_count;
    return 0;
}