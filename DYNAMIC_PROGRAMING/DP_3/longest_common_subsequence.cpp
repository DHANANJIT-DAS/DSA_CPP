#include<iostream>
#include<vector>
#include<string>
using namespace std;


// by recursion

int longest_common_subsequence(string a,string b){

    if(a.size()==0 || b.size()==0){
        return 0;
    }


    if(a[a.size()-1]==b[b.size()-1]){
        return 1+longest_common_subsequence(a.substr(0,a.size()-1),b.substr(0,b.size()-1));
    }
    else{
        return  max( longest_common_subsequence(a,b.substr(0,b.size()-1)),longest_common_subsequence(a.substr(0,a.size()-1),b));
    }


}


int main(){

    string a="bfd";
    string b="hbf";

    cout<<longest_common_subsequence(a,b);
    return 0;
}