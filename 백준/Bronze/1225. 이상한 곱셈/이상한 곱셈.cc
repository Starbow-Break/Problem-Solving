#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

ll solve(string A, string B) {
    int a = 0, b = 0;
    for(auto &c: A) a += c-'0';
    for(auto &c: B) b += c-'0';
    
    return 1LL*a*b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string A, B; cin >> A >> B;
    cout << solve(A, B);
    
    return 0;
}