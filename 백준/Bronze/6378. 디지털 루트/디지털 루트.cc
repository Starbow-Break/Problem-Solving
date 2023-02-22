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
    
    string s;
    while(1) {
        cin >> s;
        if(s == "0") break;
        
        int value = 0;
        for(auto &c: s) value += (c-'0');
        
        while(value >= 10) {
            int temp = 0;
            while(value > 0) {
                temp += value%10; value /= 10;
            }
            
            value = temp;
        }
        
        cout << value << '\n';
    }

    return 0;
}