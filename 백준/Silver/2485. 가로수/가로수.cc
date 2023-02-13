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

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    if(b == 1) return 1;
    if(b == 0) return a;
    
    return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<int> pos;
    
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        pos.push_back(v);
    }
    
    sort(pos.begin(), pos.end());
    
    int g = 0;
    for(int i = 1; i < pos.size(); i++) {
        g = gcd(g, pos[i]-pos[i-1]);
    }
    
    cout << (pos.back()-pos.front())/g-pos.size()+1;

    return 0;
}