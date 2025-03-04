#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5+2 ;
bool visited[N] ;
vector<int> adjLst[N] ;


void bfs(int srt)
{
    queue<int> q ;
    visited[srt] = true ;
    q.push(srt) ;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " " ;
        for(int a: adjLst[node])
        {
            if(!visited[a])
            {
                visited[a] = true ;
                q.push(a);
            }
        }
    }

}

void dfs(int srt)
{
    stack<int> s;
    s.push(srt) ;

    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        if(!visited[node])
        {
            visited[node]= true ;
            cout << node <<" " ;
            for(int a: adjLst[node])
            {
                if(!visited[a])
                {
                    s.push(a);
                }
            }
        }
    }
}

int main()
{
    int v,e;
    cin>>v>>e;
    for(int i = 0 ; i <e ; i++)
    {
        int a,b ;
        cin >> a >> b ;
        adjLst[a].push_back(b);
        adjLst[b].push_back(a);

    }
    int srt;cin >>srt;
    //bfs(srt);
   dfs(srt);

}


