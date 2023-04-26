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
    
    int N; cin >> N;
    string s; cin >> s;
    
    bool check = false;
    for(int j = N-1; j > 0 && !check; j--) {
        int cnt = 0;
        for(int i = 0; i+j < N; i++) {
            cnt += (s[i] != s[i+j]);
        }
        
        if(cnt == 1) check = true;
    }
    
    cout << (check ? "YES" : "NO");

    return 0;
}