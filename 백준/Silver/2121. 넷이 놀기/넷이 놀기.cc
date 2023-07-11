#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

vector<pii> pts;

bool check(pii p) {
    int i = 0, j = pts.size()-1;
    
    while(i <= j) {
        int mid = i+j >> 1;
        if(pts[mid] == p) return true;
        
        if(pts[mid] < p) i = mid+1;
        else j = mid-1;
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, A, B; cin >> N >> A >> B;
    while(N--) {
        int a, b; cin >> a >> b;
        pts.push_back({a, b});
    }
    
    sort(pts.begin(), pts.end());
    
    int ans = 0;
    for(auto &p: pts) {
        pii p1 = {p.x+A, p.y};
        pii p2 = {p.x, p.y+B};
        pii p3 = {p.x+A, p.y+B};
        
        if(check(p1) && check(p2) && check(p3)) ans++;
    }
    
    cout << ans;

    return 0;
}