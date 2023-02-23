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
    
    int score = 0;
    for(int i = 0; i < 10; i++) {
        bool getScore = true;
        
        for(int j = 0; j < N/10; j++) {
            if(s[i*(N/10)+j] == 'N') {
                getScore = false; break;
            }
        }
        
        score += getScore;
    }
    
    cout << score;
    
    return 0;
}