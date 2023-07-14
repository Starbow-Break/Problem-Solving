#include <bits/stdc++.h>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int ans[101] = {0, };
int arr[1001][1001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        int x, y, w, h; cin >> x >> y >> w >> h;
        for(int r = x; r < x+w; r++) {
            for(int c = y; c < y+h; c++) arr[r][c] = i;
        }
    }
    
    for(int r = 0; r <= 1000; r++) {
        for(int c = 0; c <= 1000; c++) {
            if(arr[r][c]) ans[arr[r][c]]++;
        }
    }
    
    for(int i = 1; i <= N; i++) cout << ans[i] << '\n';

    return 0;
}