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

bool check(int v) {
    for(int l = 1; l <= 100'000; l++) {
        int k = v-l*(l-1)/2;
        if(k < 0) break;
        if(k%l == 0 && k/l+l <= v) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int v; cin >> v;
        cout << (check(v) ? "Gazua" : "GoHanGang") << '\n';
    }

    return 0;
}