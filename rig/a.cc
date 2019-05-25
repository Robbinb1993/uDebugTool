#include <bits/stdc++.h>
using namespace std;

int main() {
	int T = 10;
	printf("%d\n", T);
	for (int t = 1; t <= T; t++) {
		vector<string> V;		
		int N = rand() % 100 + 1;
		printf("%d\n", N);
		for (int i = 0; i < N; i++) {
			string S = "";
			if (i)
				S += V.back().back();
			for (int j = 0; j < 10; j++)
				S += char(rand() % 26 + 'a');
			V.push_back(S);
		}
		random_shuffle(V.begin(), V.end());
		for (auto& s : V)
			printf("%s\n", s.c_str());
	}
	return 0;
}