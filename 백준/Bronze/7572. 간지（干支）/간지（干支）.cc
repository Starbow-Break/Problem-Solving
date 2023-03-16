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

int value(char c) {
    if('0' <= c && c <= '9') return c-'0';
    else return c-'a'+10;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s = "ABCDEFGHIJKL", t = "0123456789";
    
    int N; cin >> N;
    N -= 2013; int i = 5, j = 9;
    while(N > 0) {
        i = (i+1)%12; j = (j+1)%10; N--;
    }
    while(N < 0) {
        i = (i+11)%12; j = (j+9)%10; N++;
    }
    
    cout << s[i] << t[j];

    return 0;
}