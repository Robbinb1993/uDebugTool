#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 3e5 + 10;
const int pr_sz = 1e6 + 10;
const double eps = 1e-9;

#define sqr( a ) ( ( a ) * ( a ) )

int t, cs;
int k;
ll n;
unsigned int dp[55][55];

int mat_sz = 2;
struct Matrix {
    unsigned int a[55][55];
    void clear() {
        memset(a, 0, sizeof(a));
    }
    void one() {
        for( int i=0; i<mat_sz; i++ ) {
            for( int j=0; j<mat_sz; j++ ) {
                a[i][j] = i == j;
            }
        }
    }
    Matrix operator + (const Matrix &b) const {
        Matrix tmp;
        tmp.clear();
        for (int i = 0; i <  mat_sz; i++) {
            for (int j = 0; j < mat_sz; j++) {
                tmp.a[i][j] = a[i][j] + b.a[i][j];
            }
        }
        return tmp;
    }
    Matrix operator * (const Matrix &b) const {
        Matrix tmp;
        tmp.clear();
        for (int i = 0; i < mat_sz; i++) {
            for (int j = 0; j < mat_sz; j++) {
                for (int k = 0; k < mat_sz; k++) {
                    tmp.a[i][k] += ( a[i][j] * b.a[j][k] );
                }
            }
        }
        return tmp;
    }
    Matrix pw(ll x) {
        Matrix ans, num = *this;
        ans.one();
        while (x > 0) {
            if (x & 1) {
                ans = ans * num;
            }
            num = num * num;
            x >>= 1;
        }
        return ans;
    }
} mat;

unsigned int solve() {
        mat.clear();
        for( int i=0; i<=k; i++ ) {
                for( int j=0; j<=i; j++ ) {
                        mat.a[i][j] = dp[i][i - j];
                }
        }
        for( int i=0; i<=k; i++ ) {
                mat.a[k + 1][i] = dp[k][k - i];
        }
        mat.a[k + 1][k + 1] = 1;
        mat = mat.pw( n - 1ll );
        unsigned int ans = 0;
        for( int i=0; i<=k+1; i++ ) ans += mat.a[k+1][i];
        return ans;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        for( int i=0; i<55; i++ ) {
                for( int j=0; j<=i; j++ ) {
                        if( j == 0 || j == i ) dp[i][j] = 1;
                        else dp[i][j] = ( dp[i-1][j] + dp[i-1][j-1] );
                }
        }

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%lld %d", &n, &k );

                mat_sz = k + 2;

                printf( "Case %d: %u\n", cs, solve() );
        }

        return 0;
}