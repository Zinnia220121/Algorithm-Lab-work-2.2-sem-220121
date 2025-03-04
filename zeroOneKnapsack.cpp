#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int item;
    cin >> item ;
    int capacity;
    cin >> capacity ;
    vector<int> weight(item), value(item) ;
    for(int i = 0 ; i < item ; ++i) cin >> weight[i] ;
    for(int i = 0 ; i < item ; ++i) cin >> value[i] ;

    vector<vector<int>> dp(item+1,vector<int>(capacity+1,0)) ;

    /*
    item -> 4
    Knapsack capacity -> 8
    weight -> 1  3  5  7
    value  -> 2  4  7  10
        0   1   2   3   4   5   6   7   8
    0   0   0   0   0   0   0   0   0   0
    1   0   2   2   2   2   2   2   2   2
    2   0   2   2   4   6   6   6   6   6
    3   0   2   2   4   6   7   9   9   11  dp[row-1][w-weight[row-1]]+value[row-1] ->>                    value[2] ----->  +7
    4   0   2   2   4   6   7   9   10  12
    */
    for(int row=1 ; row<=item ; ++row)
    {
        for(int w=1; w<capacity+1; ++w )
        {
            if(w>=weight[row-1])
                dp[row][w] = max(dp[row-1][w],dp[row-1][w-weight[row-1]]+value[row-1]) ;
            else
                dp[row][w] = dp[row-1][w] ;
        }
    }
    cout << dp[item][capacity] <<endl ;
}
