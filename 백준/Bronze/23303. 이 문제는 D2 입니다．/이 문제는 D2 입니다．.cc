#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; getline(cin, s);
    
    bool check = false;
    for(int i = 0; i < s.length()-1; i++) {
        if((s[i] == 'D' || s[i] == 'd') && s[i+1] == '2') {
            check = true; break;
        }
    }
    
    cout << (check ? "D2" : "unrated");
    
    return 0;
}