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
    
    int back = 0;
    int cnt[10000] = {0, };
    
    int N; cin >> N;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        cnt[v]++;
        sum += v;
        back = max(v, back);
    }
    
    bool isPos = sum == N*(N-1)/2;
    for(int i = 0; i < N && isPos; i++) {
        while(cnt[back] == 0) back--;
        
        if(back+i >= N) {
            isPos = false;
            break;
        }
        
        cnt[back]--;
        
        int remain = back;
        if(remain < cnt[0]) {
            isPos = false;
            break;
        }
        
        for(int j = 0; j <= back; j++) {
            if(cnt[j]) {
                int num = cnt[j];
                while(remain && num) {
                    remain--; num--;
                }
                
                while(num--) {
                    cnt[j]--; cnt[j-1]++;
                }
            }
        }
    }
    
    cout << (isPos ? 1 : -1);
    
    return 0;
}
