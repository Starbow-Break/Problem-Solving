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
    
    string s;
    while(getline(cin, s)) {
        int cnt[4] = {0, };
        for(int i = 0; i < s.length(); i++) {
            if('a' <= s[i] && s[i] <= 'z') cnt[0]++;
            if('A' <= s[i] && s[i] <= 'Z') cnt[1]++;
            if('0' <= s[i] && s[i] <= '9') cnt[2]++;
            if(s[i] == ' ') cnt[3]++;
        }
        
        for(int i = 0; i < 4; i++) cout << cnt[i] << ' ';
        cout << '\n';
        
        //getchar();
    }

    return 0;
}