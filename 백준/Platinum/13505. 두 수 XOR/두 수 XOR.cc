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
#define MAX_N 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int A[MAX_N+1] = {0, };

class Trie {
    Trie* child[2];
    
    public:
        Trie() {
            child[0] = child[1] = NULL;
        }
        
        void insert(int value, int bit = 30) {
            if(bit == -1) return;
            
            int b = (value & (1<<bit) ? 1 : 0);
            
            if(child[b] == NULL) child[b] = new Trie();
            child[b]->insert(value, bit-1);
        }
        
        int query(int value, int bit = 30) {
            if(bit == -1) return 0;
            
            int b = (value & (1<<bit) ? 1 : 0);
            if(child[1-b] != NULL)
                return (1<<bit)+child[1-b]->query(value, bit-1);
            else 
                return child[b]->query(value, bit-1);
        }
        
        void clear() {
            for(int i = 0; i < 2; i++) {
                if(child[i] != NULL) child[i]->clear();
                delete child[i];
                child[i] = NULL;
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    Trie trie = Trie();
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i <= N; i++) trie.insert(A[i]);
        
    int ans = 0;
    for(int i = 1; i <= N; i++) ans = max(ans, trie.query(A[i]));
    cout << ans << '\n';

    return 0;
}