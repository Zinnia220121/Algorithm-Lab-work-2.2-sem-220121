#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int n , int i){
    int largest = i ;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && v[largest]<v[left])
        largest = left ;
    if(right<n && v[largest]<v[right])
        largest = right ;
    if(largest!=i){
        swap(v[largest],v[i]);
        heapify(v,n,largest);
    }
}

void heapSort(vector<int> &v, int n ){
    for(int i = n/2 -1 ; i>=0 ; i-- )
        heapify(v,n,0) ;
    for(int i = n-1;i>=0;i--){
        swap(v[i],v[0]);
        heapify(v,i,0) ;
    }
}

int main(){
    int n; cin >> n ;
    vector<int> v(n) ;
    for(int i = 0 ; i <n ; i++) cin >> v[i] ;

    heapSort(v,n) ;

    for(int i = 0 ; i <n ; i++) cout << v[i] << " " ;
}
