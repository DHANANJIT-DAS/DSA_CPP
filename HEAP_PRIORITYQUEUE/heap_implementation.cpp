#include<iostream>
#include<vector>
#include<string>
using namespace std;


template<class T>
class Heap{
    
    vector<T>heap;

    void heapify(int parIdx){
        if(parIdx>=heap.size()){
            return;
        }
        int left=parIdx*2+1;
        int right=parIdx*2+2;
        int maxIdx=parIdx;

        if(left<heap.size()&& heap[left]>heap[maxIdx]){
            maxIdx=left;
        }
        if(right<heap.size()&& heap[right]>heap[maxIdx]){
            maxIdx=right;
        }
        swap(heap[maxIdx],heap[parIdx]);

        if(maxIdx!=parIdx){
            heapify(maxIdx);
        }else{
            return;
        }

    }
    
public:
    void push(T val){
        heap.push_back(val);
        int childIdx=heap.size()-1;
        int parIdx=(childIdx-1)/2;
        while(heap[childIdx]>heap[parIdx] && parIdx>=0){
            swap(heap[childIdx],heap[parIdx]);
            childIdx=parIdx;
            parIdx=(childIdx-1)/2;
        }
    }

    void pop(){
        swap(heap[0],heap[heap.size()-1]);
        heap.pop_back();

        heapify(0);
    }

    T top(){
        return heap[0];
    }

    bool empty(){
        return heap.size()==0;
    }


};

int main(){
    Heap<string> H;
    H.push("hi");
    H.push("hellow");
    H.push("dhananjit");
    H.push("ankan");
    H.push("nivvi");
    H.push("anushka");

    while(!H.empty()){
        cout<<H.top()<<" ";
        H.pop();
    }

    return 0;
}