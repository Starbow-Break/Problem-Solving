#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define push_back pb
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

int birth[1'000'001] = {0, };
int birthSum[1'000'001] = {0, };
int deathSum[1'000'001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b, d, N; cin >> a >> b >> d >> N;
    birthSum[0] = 1; birth[0] = 1;
    for(int i = 1; i <= N; i++) {
        birthSum[i] += birthSum[i-1];
        birthSum[i] %= 1000;
        if(i >= a) {
            birthSum[i] += birthSum[i-a];
            birth[i] += birthSum[i-a];
            birthSum[i] %= 1000;
            birth[i] %= 1000;
        }
        if(i >= b) {
            birthSum[i] += 1000-birthSum[i-b];
            birth[i] += 1000-birthSum[i-b];
            birthSum[i] %= 1000;
            birth[i] %= 1000;
        }
    }
    
    for(int i = d; i <= N; i++) {
        deathSum[i] += deathSum[i-1];
        deathSum[i] += birth[i-d];
        deathSum[i] %= 1000;
    }
    
    cout << (birthSum[N]+1000-deathSum[N])%1000;
    
    return 0;
}