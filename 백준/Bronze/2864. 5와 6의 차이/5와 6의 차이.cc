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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string A, B; cin >> A >> B;
    
    int minA = 0, maxA = 0, minB = 0, maxB = 0;
    for(auto &a: A) {
        minA *= 10; maxA *= 10;
        if(a == '5' || a == '6') {
            minA += 5; maxA += 6;
        }
        else {minA += a-'0'; maxA += a-'0';}
    }
    for(auto &b: B) {
        minB *= 10; maxB *= 10;
        if(b == '5' || b == '6') {
            minB += 5; maxB += 6;
        }
        else {minB += b-'0'; maxB += b-'0';}
    }
    
    cout << minA+minB << ' ' << maxA+maxB;
    
    return 0;
}