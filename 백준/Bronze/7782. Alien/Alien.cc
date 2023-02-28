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
    int x, y; cin >> x >> y;
    
    while(1) {
        if(N <= 0) {cout << "No"; break;}
        
        int lx, ly, rx, ry; cin >> lx >> ly >> rx >> ry;
        
        if(lx <= x && x <= rx && ly <= y && y <= ry) {
            cout << "Yes"; break;
        }
        
        N--;
    } 
    
    return 0;
}