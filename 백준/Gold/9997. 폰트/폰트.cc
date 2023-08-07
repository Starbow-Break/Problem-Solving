#include <bits/stdc++.h>
#define repeat(cnt) for(int i = 0; i < cnt; i++)
#define pb push_back
#define all(vec) vec.begin(), vec.end();
#define rall(vec) vec.rbegin(), vec.rend();
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
using int128 = __int128_t;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

int N; 
vector<int> words;

int solve(int idx = 0, int status = 0) {
    if(status == (1<<26)-1) {
        return pow(2, N-idx);
    }
    
    if(idx == N) return 0;
    
    int ret = 0;
    ret += solve(idx+1, status | words[idx]);
    ret += solve(idx+1, status);
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    repeat(N) {
        string word; cin >> word;
        int status = 0;
        for(auto &c: word) {
            status |= 1<<(c-'A');
        }
        words.pb(status);
    }
    
    cout << solve();

    return 0;
}