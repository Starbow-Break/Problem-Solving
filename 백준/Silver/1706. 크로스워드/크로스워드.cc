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
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    char arr[20][21];
    for(int i = 0; i < N; i++) cin >> arr[i];
    vector<string> words;
    
    string t = "";
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(arr[r][c] == '#') {
                if(t.length() > 1) words.push_back(t);
                t = "";
            }
            else t += arr[r][c];
        }
        if(t.length() > 1) words.push_back(t);
        t = "";
    }
    
    for(int c = 0; c < M; c++) {
        for(int r = 0; r < N; r++) {
            if(arr[r][c] == '#') {
                if(t.length() > 1) words.push_back(t);
                t = "";
            }
            else t += arr[r][c];
        }
        if(t.length() > 1) words.push_back(t);
        t = "";
    }
    
    sort(words.begin(), words.end());
    
    cout << words[0];

    return 0;
}