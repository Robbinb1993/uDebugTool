#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

vector<vector<int> > edges;
bool seen[30];
map<ii, int> eSeen;
vector<int> added;

int main() {
   srand(time(0));
   int T = 100;
   printf("%d\n", T);
   while (T--) {
      memset(seen, 0, sizeof(seen));
      added.clear();
      eSeen.clear();
      int N = rand() % 26 + 1;
      edges.assign(N, vector<int>());
      for (int i = 0; i < N; i++) {
         int now;
         do {
            now = rand() % 26;
         } while (seen[now]);
         seen[now] = 1;
         if (rand() % 6 < 5) {
            if (i) {
               int nb = added[rand() % (int)added.size()];
               if (eSeen.find(ii(now, nb)) == eSeen.end()) {
                  eSeen[ii(now, nb)] = eSeen[ii(nb, now)] = 1;
                  printf("(%c,%c)\n", char(now + 'A'), char(nb + 'A'));
               }//if
            }//if
         }//if
         added.push_back(now);
      }//for
      int tot = rand() % 50 + 1;
      for (int i = 0; i < tot; i++)
         printf("*");
      puts("");
      for (int i = 0; i < (int)added.size(); i++) {
         if (i)
            printf(",");
         printf("%c", char(added[i] + 'A'));
      }//for
      puts("");
   }//while
   return 0;
}//main
