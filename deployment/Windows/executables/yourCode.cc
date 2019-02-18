#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define sz 50005
 
using namespace std;
 
vector <int> vt[sz];
int visited[sz], vis[sz];
 
int bfs(int src)
{
    for(int i = 0; i < sz; i++)
        visited[i] = 0;
    int cnt = 0;
    queue<int>Q;
    Q.push(src);
    visited[src] = 1;
    vis[src] = 1;
    cnt++;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int len = vt[u].size();
        for(int i = 0; i < len; i++)
        {
            int v = vt[u][i];
            if(visited[v] == 0)
            {
                vis[v] = 1;
                visited[v] = 1;
                cnt++;
                Q.push(v);
            }
        }
    }
    return cnt;
}
 
int main()
{
    int tc, cs = 1;
    scanf("%d", &tc);
 
    while(tc--)
    {
        for(int i = 0; i < sz; i++)
            vt[i].clear();
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            vt[u].push_back(v);
        }
        for(int i = 0; i < sz; i++)
            vis[i] = 0;
        int ans, gg = -1;
        for(int i = 1; i <= n; i++)
        {
            if(vis[i] == 0)
            {
                int cnt = bfs(i);
                if(cnt > gg)
                {
                    gg = cnt;
                    ans = i;
                }
            }
 
        }
 
        printf("Case %d: %d\n", cs++, ans);
 
    }
 
    return 0;
}