#include<bits/stdc++.h>
using namespace std ;

int main(){
    int n ; cin >> n ;
    int Capacity ; cin >> Capacity ;
    vector<int> value(n),weight(n) ;
    for(int i = 0 ; i<n ; ++i) cin>> weight[i] ;
    for(int i = 0 ; i<n ; ++i) cin>> value[i] ;
    vector<pair<double,int>> valueByWeight(n) ;
    for(int i = 0 ; i < n ; i ++){
        valueByWeight[i].first = (double)value[i] / (double)weight[i] ;
        valueByWeight[i].second = i ;
    }
    sort(valueByWeight.begin(),valueByWeight.end(),greater<pair<double,int>>() );
    double totalValue = 0.0 ;
    for(int i=0 ; i<n;++i){
        if(Capacity==0) break ;
        int idx = valueByWeight[i].second ;
        if(weight[idx]<=Capacity){
            Capacity-=weight[idx] ;
            totalValue+=value[idx] ;
        }
        else{
            totalValue+= value[idx]*((double)Capacity/(double)weight[idx]);
            Capacity = 0 ;
        }
    }
    cout << totalValue << endl ;
}
