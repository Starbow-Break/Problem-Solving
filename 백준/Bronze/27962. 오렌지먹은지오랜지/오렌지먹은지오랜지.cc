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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N; string s; cin >> s;
    
    bool check = false;
    for(int i = 0; i < N && !check; i++) {
        int a = 0, b = N-1-i, cnt = 0;
        while(b < N) {
            cnt += (s[a] != s[b]);
            a++; b++;
        }
        
        check = (cnt == 1);
    }
    
    cout << (check ? "YES" : "NO");

    return 0;
}