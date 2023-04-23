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
    
    string A, T; cin >> A >> T;
    
    int lenA = A.length(), lenT = T.length();
    stack<pair<char, int>> front, back;
    int f = 0, b = lenT-1;
    while(1) {
        while(f < lenT) {
            if(f <= b) {
                front.push({T[f], f});
                f++;
            }
            else {
                if(back.empty()) f = lenT;
                else {
                    f = back.top().second;
                    front.push(back.top()); back.pop();
                }
            }
            
            if(front.size() >= lenA) {
                int idx = lenA-1;
                stack<pair<char, int>> temp;
                while(idx >= 0) {
                    if(A[idx] != front.top().first) {
                        while(!temp.empty()) {
                            front.push(temp.top()); temp.pop();
                        }
                        break;
                    }
                    
                    temp.push(front.top()); front.pop();
                    idx--;
                }
                
                if(idx == -1) break;
            }
        }
        
        if(f == lenT) break;
        
        while(b >= 0) {
            if(f <= b) {
                back.push({T[b], b});
                b--;
            }
            else {
                if(front.empty()) b = -1;
                else {
                    b = front.top().second;
                    back.push(front.top()); front.pop();
                }
            }
            
            if(back.size() >= lenA) {
                int idx = 0;
                stack<pair<char, int>> temp;
                while(idx < lenA) {
                    if(A[idx] != back.top().first) {
                        while(!temp.empty()) {
                            back.push(temp.top()); temp.pop();
                        }
                        break;
                    }
                    
                    temp.push(back.top()); back.pop();
                    idx++;
                }
                
                if(idx == lenA) break;
            }
        }
    }
    
    string ans = "";
    while(!front.empty()) {
        ans = front.top().first + ans;
        front.pop();
    }
    while(!back.empty()) {
        ans = ans + back.top().first;
        back.pop();
    }
    
    cout << ans;

    return 0;
}