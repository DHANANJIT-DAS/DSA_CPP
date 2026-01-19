#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;

string first_nonrepeating_letter(string str){
    queue<char>q;
    vector<int>frequency(26,0);
    string ans="";

    for(int i=0;i<str.size();i++){
        char ch=str[i];
        q.push(ch);
        frequency[ch-'a']++;

        while(!q.empty() && frequency[q.front()-'a']>1){
            q.pop();
        }
        if(!q.empty()){
            ans=ans+q.front();
        }
        else{
            ans=ans+"-1";
        }
        
        
    }
    return ans;
}
int main(){
    string str="dfsffdsfdfsfzadasda";
    string ans=first_nonrepeating_letter(str);
    cout<<str<<endl;
    cout<<ans<<endl;
    return 0;
}