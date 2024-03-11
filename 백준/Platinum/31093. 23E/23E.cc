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
    
    int N, K; cin >> N >> K;
    int cnt[3][3] = {0, };
    
    string s; cin >> s;
    int arr[N];
    for(int i = 0; i < N; i++) {
        if(s[i] == '2') arr[i] = 0;
        if(s[i] == '3') arr[i] = 1;
        if(s[i] == 'E') arr[i] = 2;
    }
    
    int i = 0, j = N-1;
    while(i <= j) {
        cnt[min(arr[i], arr[j])][max(arr[i], arr[j])]++;
        i++; j--;
    }
    
    int ans = (cnt[0][0]+cnt[1][2])*2;
    cout << ans << '\n';
    
    while(K--) {
        // 4 증가
        if(cnt[0][1] && cnt[0][2]) {
            ans += 4;
            cnt[0][0]++; cnt[1][2]++;
            cnt[0][1]--; cnt[0][2]--;
        }
        else if(cnt[1][1] && cnt[2][2]) {
            ans += 4;
            cnt[1][2] += 2;
            cnt[1][1]--; cnt[2][2]--;
        }
        // 2 증가 -> 4 증가 
        else if(cnt[0][1] >= 2 && cnt[2][2]) {
            ans += 2;
            cnt[0][0]++; cnt[1][1]++;
            cnt[0][1] -= 2;
        }
        else if(cnt[0][1] >= 2 && cnt[2][2]) {
            ans += 2;
            cnt[0][2]++; cnt[1][2]++;
            cnt[0][1]--; cnt[2][2]--;
        }
        else if(cnt[0][2] >= 2 && cnt[1][1]) {
            ans += 2;
            cnt[0][0]++; cnt[2][2]++;
            cnt[0][2] -= 2;
        }
        else if(cnt[0][2] >= 2 && cnt[1][1]) {
            ans += 2;
            cnt[0][1]++; cnt[1][2]++;
            cnt[0][2]--; cnt[1][1]--;
        }
        // 2 증가
        else if(cnt[0][1] >= 2) {
            ans += 2;
            cnt[0][0]++; cnt[1][1]++;
            cnt[0][1] -= 2;
        }
        else if(cnt[0][1] && cnt[2][2]) {
            ans += 2;
            cnt[0][2]++; cnt[1][2]++;
            cnt[0][1]--; cnt[2][2]--;
        }
        else if(cnt[0][2] >= 2) {
            ans += 2;
            cnt[0][0]++; cnt[2][2]++;
            cnt[0][2] -= 2;
        }
        else if(cnt[0][2] && cnt[1][1]) {
            ans += 2;
            cnt[0][1]++; cnt[1][2]++;
            cnt[0][2]--; cnt[1][1]--;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
