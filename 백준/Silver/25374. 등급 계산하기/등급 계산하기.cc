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

int cutline[10];
int percentage[10] = {0, 4, 11, 23, 40, 60, 77, 89, 96, 100};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<int> score(100);
    
    for(int i = 0; i < 100; i++) cin >> score[i];
    
    sort(rall(score));
    
    for(int i = 1; i <= 9; i++) {
        cutline[i] = score[percentage[i]-1];
    }
    
    int cnt[10] = {0, };
    for(int i = 0; i < 100; i++) {
        for(int j = 1; j <= 9; j++) {
            if(score[i] >= cutline[j]) {
                cnt[j]++;
                break;
            }
        }
    }
    
    for(int j = 1; j <= 9; j++) {
        cout << cnt[j] << '\n';
    }
    
    return 0;
}