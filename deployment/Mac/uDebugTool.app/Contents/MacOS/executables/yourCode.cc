#include "stdio.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef pair<char, int> ci;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N;
vector<ci> circuits;
vi seen, incCounter, dist, onPath;
vvi edges, incoming;

bool cycleCheck(const int u) {
   seen[u] = 1;
   onPath[u] = 1;
   for (auto& e : edges[u]) {
      if (onPath[e])
         return 1;
      if (!seen[e] && circuits[e].first != 's' && cycleCheck(e))
         return 1;
   }//for
   onPath[u] = 0;
   return 0;
}//cycleCheck

int maxPath() {
   stack<int> S;
   int curr, mx = 0;
   for (int i = 0; i < N; i++)
      if (circuits[i].first != 's' && !incCounter[i])
         S.push(i);
   while (!S.empty()) {
      curr = S.top();
      S.pop();
      for (auto& e : incoming[curr])
         dist[curr] = max(dist[curr], circuits[e].first == 's' ? 0 : dist[e] + circuits[e].second);
      for (auto& e : edges[curr])
         if (!(--incCounter[e]))
            S.push(e);
      mx = max(mx, dist[curr]);
   }//while
   return mx;
}//maxPath

int main() {
   int T, M, w, c1, c2, clk, p;
   char t;
   bool cycle;
   scanf("%d", &T);
   while (T--) {
      scanf("%d %d", &clk, &N);
      edges.assign(N + 5, vi());
      incoming.assign(N + 5, vi());
      seen.assign(N + 5, 0);
      onPath.assign(N + 5, 0);
      circuits.assign(N + 5, ci('0', 0));
      incCounter.assign(N + 5, 0);
      dist.assign(N + 5, 0);
      for (int i = 0; i < N; i++) {
         scanf(" %c %d", &t, &w);
         circuits[i] = ci(t, w);
      }//for
      scanf("%d", &M);
      while (M--) {
         scanf("%d %d", &c1, &c2);
         edges[c1].push_back(c2);
         incoming[c2].push_back(c1);
         if (circuits[c1].first != 's')
            incCounter[c2]++;
      }//while
      cycle = false;

      for (int i = 0; i < N && !cycle; i++)
         if (circuits[i].first == 'a' && !seen[i])
            cycle = cycleCheck(i);
      if (cycle)
         puts("Circuit contains cycle.");
      else {
         p = maxPath();
         if (p > clk)
            puts("Clock period exceeded.");
         else
            printf("Synchronous design. Maximum delay: %d.\n", p);
      }//else
   }//while
   return 0;
}//main
