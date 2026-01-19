#include<iostream>
#include<list>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;



string findOrder(vector<string> &words) {
    
    list<char>* l=new list<char>[26];

    map<char,int>inorder;

    for(int i=0;i<words.size();i++){
        for(int j=0;j<words[i].size();j++){

            inorder[words[i][j]]=0;
        }

    }

    for(int i=0;i<words.size()-1;i++){

        string a=words[i];
        string b=words[i+1];

        int j=0;
        for(j;j<min(a.size(),b.size());j++){
            if(a[j]!=b[j]){

                if( find (l[a[j]-'a'].begin(), l[a[j]-'a'].end(),b[j])==l[a[j]-'a'].end()){
                    l[a[j]-'a'].push_back(b[j]);
                    inorder[b[j]]++;
                }
                break;
            }
        }
        if(j==b.size() && a.size()>j){
            return "";
        }


    }

    

    queue<char>Q;

    for(auto el:inorder){

        if(el.second==0){
            Q.push(el.first);
        }
    }
    
    string ans="";

    while(!Q.empty()){
        char curr=Q.front();
        Q.pop();
        
        ans+=curr;

        list<char>nbr=l[curr-'a'];
        
        for(auto el:nbr){

            inorder[el]--;
            if(inorder[el]==0){
                Q.push(el);
            }
        }
    }

    if(ans.size()!=inorder.size()){
        return "";
    }
    else{
        return ans;
    }
        
}



int main(){
    vector<string>words={"baa", "abcd", "abca", "cab", "cad"};
    cout<<findOrder(words);
    return 0;
}



/*
    A new alien language uses the English alphabet, but the order of letters is unknown. 
    You are given a list of words[] from the alien language’s dictionary, where the words are claimed
    to be sorted lexicographically according to the language’s rules.

    Your task is to determine the correct order of letters in this alien language based on the given words. 
    If the order is valid, return a string containing the unique letters in lexicographically increasing order
    as per the new language's rules. If there are multiple valid orders, return any one of them.

    However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

    A string a is lexicographically smaller than a string b if, at the first position where they differ, 
    the character in a appears earlier in the alien language than the corresponding character in b. 
    If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

    Ex--

    Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
    Output:  'b' → 'd' → 'a' → 'c' is a valid ordering.

*/
