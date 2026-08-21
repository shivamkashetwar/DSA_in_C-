// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

bool sort(vector<int>arr,int n){
if(n==0 || n==1){
    retur true;
}

   return arr[n-1]>=arr[n-2] && sort(  arr,n-1);
}
int main() {
    vector<int>={1,2,3,4}// Write C++ code here
     
     cout<<sort(arr,arr.size());

    return 0;
}