#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

struct meeting {
    int start, finish, members;
    
    bool operator<(meeting &m) {
        if(start != m.start) return start < m.start;
        return finish < m.finish;
    }
};

vector<meeting> meetings;

int calc(int N, int state) {
    int cur = 0, ret = 0;
    for(int i = 0; i < N; i++) {
        if(state & (1<<i)) {
            if(cur > meetings[i].start) return 0;
            ret += meetings[i].members;
            cur = meetings[i].finish;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int s, f, m; cin >> s >> f >> m;
        meetings.push_back({s, f, m});
    }
    
    sort(meetings.begin(), meetings.end());
    
    int ans = 0;
    for(int state = 0; state < 1<<N; state++) {
        ans = max(ans, calc(N, state));
    }
    
    cout << ans;

    return 0;
}