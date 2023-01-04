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
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

class Trie {
    int count = 0;
    Trie *child[2] = {NULL, NULL};
    
    public:
        void insert(int value, int e = 29) {
            if(e < 0) {
                count++;
                return;
            }
            
            if(value >= (1<<e)) {
                if(child[1] == NULL) child[1] = new Trie();
                child[1]->insert(value-(1<<e), e-1);
            }
            else {
                if(child[0] == NULL) child[0] = new Trie();
                child[0]->insert(value, e-1);
            }
        }
        
        void del(int value, int e = 29) {
            if(e < 0) {
                count--;
                return;
            }
            
            if(value >= (1<<e)) {
                child[1]->del(value-(1<<e), e-1);
                if(child[1]->count == 0 &&
                    child[1]->child[0] == NULL && child[1]->child[1] == NULL) {
                    delete(child[1]);
                    child[1] = NULL;
                }
            }
            else {
                child[0]->del(value, e-1);
                if(child[0]->count == 0 &&
                    child[0]->child[0] == NULL && child[0]->child[1] == NULL) {
                    delete(child[0]);
                    child[0] = NULL;
                }
            }
        }
        
        int query(int value, int e = 29) {
            if(e < 0) return 0;
            
            int t = value/(1<<e); int ret = 0;
            
            if(child[1-t] != NULL) return (1<<e)+child[1-t]->query(value-(1<<e)*t, e-1);
            else return child[t]->query(value-(1<<e)*t, e-1);
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    Trie tr = Trie();
    tr.insert(0);
    
    int M; cin >> M;
    while(M--) {
        int q, x; cin >> q >> x;
        if(q == 1) {
            tr.insert(x);
        }
        else if(q == 2) {
            tr.del(x);
        }
        else {
            cout << tr.query(x) << '\n';    
        }
    }

    return 0;
}