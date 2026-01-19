#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


class Node{
public:
    unordered_map<char,Node*>children;
    int frequency_char;
    bool end_of_word;
    Node(){
        frequency_char=0;
        end_of_word=false;
    }

};

class Trie{

public:

    Node* root=new Node;

    void insert(string key){
        Node* temp=root;

        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node;
            }
            temp->frequency_char++;
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

};


string find_prefix(Trie &T,string key){
    Node* temp=T.root;
    string prefix="";
    for(int i=0;i<key.size();i++){
        prefix=prefix+key[i];
        if(temp->children[key[i]]->frequency_char<=1){
            return prefix;
        }
        else{
            temp=temp->children[key[i]];
        }
    }
    return prefix;
    
}


vector<string> prefix_problem(vector<string>&words){

    Trie T;

    for(int i=0;i<words.size();i++){
        T.insert(words[i]);
    }

    vector<string>prefix;

    for(int i=0;i<words.size();i++){
        string prefix_of_word=find_prefix(T,words[i]);
        prefix.push_back(prefix_of_word);
    }

    return prefix;


}

void printString(vector<string>prefix){
    for(int i=0;i<prefix.size();i++){
        cout<<prefix[i]<<",";
    }
    cout<<endl;
}
int main(){
    vector<string>words={"dog","abcdefkh","zebra","dove","duck","ac"};
    vector<string>prefix=prefix_problem(words);

    printString(prefix);

    return 0;
}