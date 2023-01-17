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

vector<int> clockNumber;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a = 0; int b;
    for(int i = 0; i < 4; i++) { 
        int v; cin >> v;
        a *= 10; a += v;
    }
    
    b = a;
    for(int i = 0; i < 4; i++) { 
        int t = a%10;
        a /= 10; a += t*1000;
        b = min(b, a);
    }
    
    for(int i = 1000; i <= 9999; i++) {
        int cur = i; bool flag = true;
        for(int j = 0; j < 4 && flag; j++) {
            int t = cur%10;
            if(t == 0) flag = false;
            else {
                cur /= 10; cur += t*1000;
                if(cur < i) flag = false;
            }
        }
        
        if(flag) { clockNumber.push_back(i); }
    }

    for(int i = 0; i < clockNumber.size(); i++) {
        if(clockNumber[i] == b) { cout << i+1; break; }
    }

    return 0;
}