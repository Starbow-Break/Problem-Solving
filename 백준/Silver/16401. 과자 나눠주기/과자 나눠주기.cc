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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int M, N; cin >> M >> N;
    vector<int> snack;
    
    while(N--) {
        int l; cin >> l;
        snack.push_back(l);
    }
    
    int i = 1, j = 1'000'000'000;
    while(i <= j) {
        int mid = i+j >> 1;
        ll cnt = 0;
        for(auto &l: snack) {
            cnt += l/mid;
        }
        
        if(cnt < M) j = mid-1;
        else i = mid+1;
    }
    
    cout << j;

    return 0;
}