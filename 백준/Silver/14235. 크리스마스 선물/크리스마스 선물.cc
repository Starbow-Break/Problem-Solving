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
    
    int N; cin >> N;
    priority_queue<int, vector<int>, less<int>> pq;
    while(N--) {
        int v; cin >> v;
        if(!v) {
            if(pq.empty()) cout << -1 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            while(v--) {
                int vv; cin >> vv;
                pq.push(vv);
            }
        }
    }

    return 0;
}