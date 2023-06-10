#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

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
    
    int T; cin >> T;
    vector<int> a, b;
    while(T--) {
        a.clear(); b.clear();
        
        int n1, m1, n2, m2; cin >> n1 >> m1 >> n2 >> m2;
        double temp = 1, ans = 0;
        for(int i = 1; i <= n1-m1; i++) a.push_back(n1+n2+2-m1-i);
        for(int i = 1; i <= n1+1; i++) a.push_back(i);
        for(int i = 1; i <= n1+1; i++) b.push_back(n1+n2+3-i);
        for(int i = 1; i <= n1-m1; i++) b.push_back(i);
        
        int idxA = 0, idxB = 0;
        
        while(idxA < a.size() && idxB < b.size()) {
            temp *= (double)a[idxA]/b[idxB];
            idxA++; idxB++;
        }
        while(idxA < a.size()) {
            temp *= (double)a[idxA]; idxA++; 
        }
        while(idxB < b.size()) {
            temp *= (double)1/b[idxB]; idxB++;
        }
        ans += temp;
        
        for(int i = m1+1; i <= m1+m2; i++) {
            temp *= (double)i/(i-m1);
            temp *= (double)(n2+2-i+m1)/(n1+n2+2-i);
            ans += temp;
        }
        
        cout << fixed << setprecision(12) << ans << '\n';
    }

    return 0;
}