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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<int> vec(N);
    
    for(int i = 0; i < N; i++) cin >> vec[i];
    
    if(N > 100) {
        cout << "Yes";
        return 0;
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            for(int k = j+1; k < N; k++) {
                for(int l = k+1; l < N; l++) {
                    if(!(vec[i] ^ vec[j] ^ vec[k] ^ vec[l])) {
                        cout << "Yes";
                        return 0;
                    }
                }
            }
        }
    }
    
    cout << "No";
    
    return 0;
}