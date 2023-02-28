#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>
#define SIZE 1'860'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        string s; cin >> s; int ans = 0;
        
        int cnt = 0;
        for(int i = 0; i < s.length(); i++) {
            if(i%8 == 0) {
                ans += cnt%2; cnt = 0;
            }
            
            cnt += (s[i] == '1');
        }
        ans += cnt%2;
        
        cout << ans << '\n';
    }
    
    return 0;
}