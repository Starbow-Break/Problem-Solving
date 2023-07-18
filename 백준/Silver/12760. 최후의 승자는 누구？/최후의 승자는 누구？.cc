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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    int score[101] = {0, };
    vector<int> card[101];
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            int v; cin >> v;
            card[i].push_back(v);
        }
        sort(card[i].rbegin(), card[i].rend());
    }
    
    for(int j = 0; j <= M; j++) {
        int t = 0;
        for(int i = 1; i <= N; i++) {
            t = max(t, card[i][j]);
        }
        for(int i = 1; i <= N; i++) {
            if(card[i][j] == t) score[i]++;
        }
    }
    
    int t = 0;
    for(int i = 1; i <= N; i++) {
        t = max(t, score[i]);
    }
    for(int i = 1; i <= N; i++) {
        if(score[i] == t) {
            cout << i << ' ';
        }
    }

    return 0;
}