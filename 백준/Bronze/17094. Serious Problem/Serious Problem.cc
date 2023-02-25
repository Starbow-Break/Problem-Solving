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
    
    int cnt[2] = {0, };
    int N; cin >> N;
    string s; cin >> s;
    
    for(int i = 0; i < N; i++) {
        if(s[i] == '2') cnt[0]++;
        if(s[i] == 'e') cnt[1]++;
    }
    
    if(cnt[0] > cnt[1]) cout << 2;
    else if(cnt[0] < cnt[1]) cout << 'e';
    else cout << "yee";
    
    return 0;
}