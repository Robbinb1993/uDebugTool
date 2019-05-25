#include <bits/stdc++.h>
using namespace std;
 
struct Edge {
   int id, from, to, used;
   Edge() {}
   Edge(const int f, const int t) {
      from = f; to = t; used = 0;
   }
};
 
int n;
vector<vector<Edge>> edges;
int degree[30];
int out[30];
vector<Edge> L;
vector<string> words[26][26];
 
void genEulerPath(const int u, const Edge& e) {
   for (int i = 0; i < (int)edges[u].size(); i++) {
      if (!edges[u][i].used) {
         edges[u][i].used = 1;
         genEulerPath(edges[u][i].to, edges[u][i]);
      }
   }
   L.push_back(e);
}
 
bool check(const int st) {
   for (int i = 0; i < 26; i++)
      for (auto& e : edges[i])
         e.used = 0;
   L.clear();
   genEulerPath(st, Edge());
   L.pop_back();
 
   if ((int)L.size() != n)
      return false;
   auto it = L.rbegin();
   auto prv = it;
   it++;
   bool flag = 1;
   while (it != L.rend() && flag) {
      if (prv->to != it->from)
         flag = 0;
      prv = it++;
   }
   if (!flag)
      return false;
   return true;
}
 
int main() {
   int T, odd;
   scanf("%d", &T);
   char S[30];
   for (int t = 1; t <= T; t++) {
      for (int i = 0; i < 26; i++)
         for (int j = 0; j < 26; j++)
            words[i][j].clear();
      scanf("%d", &n);
      memset(degree, 0, sizeof(degree));
      edges.assign(30, vector<Edge>());
      int st;
      for (int i = 0; i < n; i++) {
         scanf(" %s", S);
         int len = strlen(S);
         words[S[0] - 'a'][S[len - 1] - 'a'].push_back(S);
         degree[S[0] - 'a']++;
         degree[S[len - 1] - 'a']++;
         edges[S[0] - 'a'].push_back(Edge(S[0] - 'a', S[len - 1] - 'a'));
         st = S[0] - 'a';
      }
      int odd = 0;
      vector<int> oddv;
      for (int i = 0; i < 26; i++) {
         if (degree[i] & 1) {
            oddv.push_back(i);
            odd++;
         }
      }
 
      if ((odd != 0  && odd != 2) || (odd == 2 && (!check(oddv[0]) && !check(oddv[1]))) || (odd == 0 && !check(st)))
         printf("Case %d: No\n", t);
      else {
         printf("Case %d: Yes\n", t);
         Edge e = L.back();
         L.pop_back();
         printf("%s", words[e.from][e.to].back().c_str());
         words[e.from][e.to].pop_back();
         while (!L.empty()) {
            e = L.back();
            L.pop_back();
            printf(" %s", words[e.from][e.to].back().c_str());
            words[e.from][e.to].pop_back();
         }
         puts("");
      }
   }
   return 0;
}