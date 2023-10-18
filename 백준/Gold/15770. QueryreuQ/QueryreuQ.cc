#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

bool is_palindrome[10000][10000] = {false, };
int cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int Q; cin >> Q;
    string s; cin >> s;
    
    char arr[10000];
    int cursor = -1;
    
    for(int i = 0; i < Q; i++){
        char c = s[i];
        if(c == '-') {
            for(int l = 0; l <= cursor; l++) {
                if(is_palindrome[l][cursor]) {
                    cnt--;
                    is_palindrome[l][cursor] = false;
                }
            }
            cursor--;
        }
        else {
            cursor++;
            arr[cursor] = c;
            for(int i = 0; i <= cursor; i++) {
                if(arr[i] == arr[cursor]) {
                    if(cursor-i <= 1 || is_palindrome[i+1][cursor-1]) {
                        is_palindrome[i][cursor] = true;
                        cnt++;
                    }
                }
            }
        }
        
        cout << cnt << ' ';
    }
    
    return 0;
}