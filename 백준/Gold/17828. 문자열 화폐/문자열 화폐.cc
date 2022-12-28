#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

string solve(int N, int X) {
    if(N > X || X > 26*N) return "!";
    
    string ret = "";
    
    while(X-1 <= 26*(N-1)) {
        ret += 'A';
        X--; N--;
    }
    if(X%26) {
        ret += (char)(X%26-1+'A');
        N--; X -= (X%26);
    }
    while(N--) { ret += 'Z'; }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, X; cin >> N >> X;
    cout << solve(N, X);

    return 0;
}