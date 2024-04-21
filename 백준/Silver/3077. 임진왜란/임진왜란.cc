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

unordered_map<string, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        string s; cin >> s;
        mp.insert({s, i});
    }
    
    vector<int> answer;
    
    for(int i = 1; i <= N; i++) {
        string s; cin >> s;
        auto t = mp.find(s);
        
        answer.pb(t->se);
    }
    
    int a = 0, b = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(answer[i] < answer[j]) a++;
            b++;
        }
    }
    
    cout << a << '/' << b; 
    
    return 0;
}