#include <bits/stdc++.h>
using namespace std;
 
set<string> seen;
vector<int> indices;
vector<char> V;
 
unsigned long long llrand() {
    unsigned long long r = 0;
    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }
    return r & 0xFFFFFFFFFFFFFFFFULL;
}

int main() {
	srand(time(0));
	int T = 1;
	string S;
	printf("%d\n", T);
	for (int i = 0; i < 62; i++)
		indices.push_back(i);
	for (char c = 'a'; c <= 'z'; c++)
		V.push_back(c);
	for (char c = 'A'; c <= 'Z'; c++)
		V.push_back(c);
	for (char c = '0'; c <= '9'; c++)
		V.push_back(c);
	while (T--) {
		int N = llrand() % 100 + 1;
		printf("%d\n", N);
		while (N--) {			
			S = "";
			int tot = llrand() % 10 + 1;
			random_shuffle(indices.begin(), indices.end());
			for (int i = 0; i < tot; i++)
				S.push_back(V[indices[i]]);			
			seen.insert(S);
			printf("%s\n", S.c_str());
		}//while
	}//while
	return 0;
}//main