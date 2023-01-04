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
    
    cout << "? 1000000000" << '\n';
    std::cout << std::flush;
    
    string s; cin >> s;
    reverse(s.begin(), s.end());
    
    cout << "! ";
    int idx = 0; int cnt = 0;
    while(cnt <= N) {
        int v = 0;
        for(int j = cnt*9+8; j >= cnt*9; j--) {
            if(j >= s.length()) continue;
            v *= 10; v += s[j]-'0';
        }
        
        cout << v << " ";
        cnt++;
    }
    cout << '\n';
    std::cout << std::flush;

    return 0;
}