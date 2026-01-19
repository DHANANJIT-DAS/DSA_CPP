#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;



class Node{

public:
    unordered_map<char,Node*>children;
    bool end_of_word;
    vector<string>words;

    Node(){
        end_of_word=false;
    }
};

class Trie{

public:
    Node* root=new Node;

    void insert(string sortedWord,string original){
        Node* temp=root;

        for(int i=0;i<sortedWord.size();i++){
            if(temp->children.count(sortedWord[i])==0){
                temp->children[sortedWord[i]]=new Node;
            }
            temp=temp->children[sortedWord[i]];
        }
        temp->end_of_word=true;
        temp->words.push_back(original);

    }

};


void getOrder(Node* root,vector<vector<string>>&ans){
    if(root->end_of_word){
        ans.push_back(root->words);
    }
    for(auto x:root->children){
        getOrder(x.second,ans);
    }
}


vector<vector<string>> group_Anagrams(vector<string>words){
    Trie T;

    for(int i=0;i<words.size();i++){
        string str=words[i];
        sort(str.begin(),str.end());
        T.insert(str,words[i]);
    }

    vector<vector<string>>ans;

    getOrder(T.root,ans);
    
    return ans;
}







void print(vector<string>words){
    for(int i=0;i<words.size();i++){
        cout<<words[i]<<",";
    }
    cout<<endl;
}
int main(){
    vector<string>words={"bat","eat","tea","tan","ate"};

    vector<vector<string>> groupAnagrams=group_Anagrams(words);
    for(int i=0;i<groupAnagrams.size();i++){
        print(groupAnagrams[i]);
    }
    

    return 0;
}








    