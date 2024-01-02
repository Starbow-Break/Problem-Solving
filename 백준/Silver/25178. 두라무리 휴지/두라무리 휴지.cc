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
    string s1, s2; cin >> s1 >> s2;
    string t1 = "", t2 = "";
    int cnt1[26] = {0, }, cnt2[26] = {0, };
    
    for(auto &c: s1) {
        cnt1[c-'a']++;
        if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            t1 += c;
        }
    }
    
    for(auto &c: s2) {
        cnt2[c-'a']++;
        if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            t2 += c;
        }
    }
    
    bool check = (s1[0] == s2[0] && s1[N-1] == s2[N-1] && t1 == t2);
    
    for(int i = 0; i < 26; i++) {
        if(cnt1[i] != cnt2[i]) check = false;
    }
    
    cout << (check ? "YES" : "NO");
    
    return 0;
}
