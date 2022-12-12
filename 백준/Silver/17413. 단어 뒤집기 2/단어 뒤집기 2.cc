#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MOD 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; getline(cin, s);
    string ans = "";
    
    string temp = ""; bool isTag = false;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            if(isTag) {
                temp += s[i];
            }
            else {
                reverse(temp.begin(), temp.end());
                ans += temp; ans += " ";
                temp = "";
            }
        }
        else if(s[i] == '<') {
            reverse(temp.begin(), temp.end());
            ans += temp; temp = "<";
            isTag = true;
        }
        else if(s[i] == '>') {
            temp += s[i];
            ans += temp; temp = "";
            isTag = false;
        }
        else {
            temp += s[i];
        }
    }
    
    reverse(temp.begin(), temp.end());
    ans += temp;
    
    cout << ans;

    return 0;
}