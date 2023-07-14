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
    
    int P; cin >> P;
    while(P--) {
        int num; cin >> num;
        int ans = 0, height[20];
        
        for(int i = 0; i < 20; i++) {
            int h; cin >> h;
            height[i] = h;
            
            int j = i;
            while(j > 0 && height[j-1] > height[i]) j--;
            
            for(int k = i-1; k >= j; k--) {
                height[k+1] = height[k]; ans++;
            }
            height[j] = h;
        }
        
        cout << num << ' ' << ans << '\n';
    }

    return 0;
}