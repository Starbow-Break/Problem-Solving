#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

int numColor = 0;
int color[500001] = {0, };

void solve(int N) {
    numColor++;
    color[1] = 1;
    for(int i = 2; i <= N; i++) {
        if(!color[i]) {
            numColor++;
            for(int j = i; j <= N; j += i) {
                if(!color[j]) color[j] = numColor;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    solve(N);
    cout << numColor << '\n';
    for(int i = 1; i <= N; i++) cout << color[i] << ' ';
    
    return 0;
}