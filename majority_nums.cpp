#include <iostream>
#include <climits> // Required for INT_MAX and INT_MIN
#include <algorithm> // Required for std::min and std::max

using namespace std;


void reverse(int arr[],int sz){
int start=0;
int end=sz-1;
while(start<end){
    swap(arr[start],arr[end]);
    start++;
    end--;
}
}
int main(){
    int arr[]={1,2,3,45,5,6,7};
   int sz=7;
    reverse(arr,sz);
    
    for(int i=0;i<sz;i++){
        cout<<arr[i]<<"";
    }
    
    return 0;
}