#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;
void ac();
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef DDEBUG
        FILE *fp = freopen("./a.in", "r", stdin);       //测试用例所在路径
    #endif

    ac();

    #ifdef DDEBUG
        fclose(fp);
    #endif
}

void ac(){
    long long n, l, v; cin >> n >> l >> v;
    vector<long long> trap(n);
    for (long long i = 0; i < n; ++ i) cin >> trap[i];
    sort(trap.begin(), trap.end());
    long long day = (l - 1) / v + 1;

    vector<long long> d(n);
    d[0] = (trap[0] - 1) / v + 1;
    long long yu = d[0] * v - trap[0];
    for (long long i = 1; i < n; ++ i){
        d[i] = d[i - 1] + (trap[i] - 1 - yu) / v + 1;
        yu = d[i] * v - trap[i];
    }
    // for (long long x: d) cout << x << " ";cout << endl;

    long long m; cin >> m;
    while (m--){
        long long x; cin >> x;
        if (day > x) cout << 0 << endl;
        else{
            long long le = 0, ri = n - 1;
            long long ans = -1;
            while (le <= ri){
                long long m = (le + ri) / 2;
                if (d[m] + day > x){
                    ans = m;
                    ri = m - 1;
                }else{
                    le = m + 1;
                }
            }
            cout << ans << endl;
        }
    }
}