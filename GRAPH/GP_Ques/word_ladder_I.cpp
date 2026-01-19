#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<climits>
using namespace std;


int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {  // time complexity=O(N*N*M)
                                                                                       //  space complexity=O(N*N)
    if(startWord==targetWord){
        return 1;
    }

    bool isExist=false;
    for(int i=0;i<wordList.size();i++){
        if(startWord==wordList[i]){
            isExist=true;
            break;
        }
    }
    if(!isExist){
        wordList.push_back(startWord);
    }
    map<string,vector<string>>M;

    

    for(int i=0;i<wordList.size();i++){
        for(int j=0;j<wordList.size();j++){
            string str1=wordList[i];
            string str2=wordList[j];
            int count=0;
            for(int k=0;k<str1.size();k++){
                if(str1[k]!=str2[k]){
                    count++;
                    if(count>1){
                        break;
                    }
                }
            }
            if(count==1){
                M[str1].push_back(str2);
            }

        }
    }

    

    map<string,int>dist;
    
    for(int i=0;i<wordList.size();i++){
        dist[wordList[i]]=INT_MAX;
    }

    dist[startWord]=1;

    queue<pair<string,int>>Q;
    Q.push(make_pair(startWord,1));
    
    while(!Q.empty()){

        string currstr=Q.front().first;
        int currDist=Q.front().second;
        Q.pop();

        vector<string>nbr=M[currstr];

        for(string el:nbr){

            if(dist[el]==INT_MAX){
                dist[el]=currDist+1;
                Q.push(make_pair(el,dist[el]));

                if(el==targetWord){
                    return dist[el];
                }
            }

        }

    }

    
    return 0;
    

        
}




int wordLadderLength2(string startWord, string targetWord, vector<string>& wordList) {
                                                                                        // time complexity=O(N*26*M*log(N))
    if(startWord==targetWord){                                                          // space complexity=O(N)
        return 1;
    }

    set<string>S;
    map<string,bool>M;

    for(int i=0;i<wordList.size();i++){
        S.insert(wordList[i]);
        M[wordList[i]]=false;
    }

    
    M[startWord]=true;

    queue<pair<string,int>>Q;

    Q.push(make_pair(startWord,1));

    while(!Q.empty()){

        string currStr=Q.front().first;
        int currDis=Q.front().second;
        Q.pop();

        for(int i=0;i<currStr.size();i++){
            
            for(char ch='a';ch<='z';ch++){
                string temp=currStr;
                temp[i]=ch;
                if(S.find(temp)!=S.end() && !M[temp]){
                    if(temp==targetWord){
                        return currDis+1;
                    }
                    else{
                        Q.push(make_pair(temp,currDis+1));
                        M[temp]=true;
                    }
                }
            }
        }
        
    }

    return 0;
}


int main(){

    vector<string>wordList={"des","der","dfr","dgt","dfs"};
    cout<<wordLadderLength2("der","dfs",wordList);
    return 0;
}


/*
    Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. 
    Find the length of the shortest transformation sequence from startWord to targetWord.

    Keep the following conditions in mind:

    * A word can only consist of lowercase characters.
    * Only one letter can be changed in each transformation.
    * Each transformed word must exist in the wordList including the targetWord.
    * startWord may or may not be part of the wordList
  
    Note: If no possible way to transform sequence from startWord to targetWord return 0

*/