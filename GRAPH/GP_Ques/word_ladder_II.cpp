#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<climits>
using namespace std;


vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
    vector<vector<string>>ans;

    set<string>S;
    for(int i=0;i<wordList.size();i++){
        S.insert(wordList[i]);
    }

    queue<vector<string>>Q;
    Q.push(vector<string>(1,beginWord));

    int level=0;
    int total_level=INT_MAX;
    set<string>added;
    added.insert(beginWord);

    while(!Q.empty()){

        vector<string>curr=Q.front();
        string lastWord=curr[curr.size()-1];
        Q.pop();

        
        
       
        if(curr.size()>level){

            while(added.size()>0){
                S.erase(*added.begin());
                added.erase(added.begin());
            }
            level=curr.size();
        }


        if(lastWord==endWord){
            ans.push_back(curr);
            total_level=curr.size();
        }
        if(curr.size()==total_level){
            continue;
        }
        

        
        for(int i=0;i<lastWord.size();i++){
            for(char ch='a';ch<='z';ch++){
                string temp=lastWord;
                temp[i]=ch;
                if(S.find(temp)!=S.end()){
                    curr.push_back(temp);
                    Q.push(curr);
                    curr.pop_back();
                    added.insert(temp);
                }
            }
        }


    }


    return ans;

}

/*------------------------------------------------------------------------------------------------------------*/

// more optimized

void make_ans(vector<string>&sequence,vector<vector<string>>&ans,map<string,int>&M,int steps){

    if(steps==-1){
        ans.push_back(sequence);
        return;
    }
    string prev=sequence[steps+1];

    for(auto el:M){
        if(el.second==steps){

            int count=0;
            for(int i=0;i<prev.size();i++){
                if(el.first[i]!=prev[i]){
                    count++;
                }
            }
            if(count==1){
                sequence[steps]=el.first;
                make_ans(sequence,ans,M,steps-1);

            }
        }
    }
}

vector<vector<string>> findLadders2(string beginWord, string endWord, vector<string>& wordList) {

    set<string>S;
    for(int i=0;i<wordList.size();i++){
        S.insert(wordList[i]);
    }

    map<string,int>M;

    M[beginWord]=0;

    queue<string>Q;
    Q.push(beginWord);
    S.erase(beginWord);

    bool a=false;
    while(!Q.empty()){

        string currStr=Q.front();
        int level=M[currStr];
        Q.pop();

        for(int i=0;i<currStr.size();i++){

            for(char ch='a';ch<='z';ch++){
                string temp=currStr;
                temp[i]=ch;
                if(S.find(temp)!=S.end()){
                    M[temp]=level+1;
                    Q.push(temp);
                    S.erase(temp);

                    if(temp==endWord){
                        a=true;
                        break;
                    }

                }
            }
            if(a){
                break;
            }
        }
        if(a){
            break;
        }
    }

    vector<vector<string>>ans;

    if(M.count(endWord)==0){
        return ans;
    }

    int steps=M[endWord];

    vector<string>sequence(steps+1,endWord);

    make_ans(sequence,ans,M,steps-1);

    return ans;


}




int main(){
    return 0;
}