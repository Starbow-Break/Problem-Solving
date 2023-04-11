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

string mandalart[9][9];
vector<pair<string, string>> vec;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) cin >> mandalart[i][j];
    }
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 1 && j == 1) continue;
            
            string s = mandalart[i*3+1][j*3+1];
            for(int r = 0; r < 3; r++) {
                for(int c = 0; c < 3; c++) {
                    if(r == 1 && c == 1) continue;
                    vec.push_back({s, mandalart[i*3+r][j*3+c]});
                }
            }
        }
    }
    
    sort(vec.begin(), vec.end());
    
    for(int i = 1; i <= 8; i++) {
        cout << "#" << i << ". " << vec[8*(i-1)].first << '\n';
        for(int j = 1; j <= 8; j++) {
            cout << "#" << i << "-" << j << ". ";
            cout << vec[8*(i-1)+(j-1)].second << '\n';
        }
    }

    return 0;
}