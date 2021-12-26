#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <queue>
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

/* 河宽l，中间有n个柱子，位置为v[i] (0 <= i < n)，小A过河的时候会破坏m个墩子，让自己跳的更远，返回的时候会修复这m个墩子，同时会新立起来
    m个墩子
 */
/* 求他过河的时候跨越的最小距离的最大值，和返回的时候跨越的最大距离的最小值 */

//输入
/* 
25 5 2
2
11
13
17
21 
*/


//输出
/* 
4
4
 */
void ac(){
    int l, n, m;  cin >> l >> n >> m;
    int mm = m;
    vector<int> v(n);
    for (int i = 0; i < n; ++ i) cin>> v[i];
    sort(v.begin(), v.end());
    class cmp1{
    public:
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            return abs(a.first - a.second) > abs(b.first - b.second);
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1> pq1;
    pq1.push({0, v[0]});
    unordered_map<int, int> mp1;
    mp1[0] = v[0];
    for (int i = 1; i <n; ++ i) {
        pq1.push({v[i - 1], v[i]});
        mp1[v[i - 1]] = v[i];
    }
    pq1.push({v[n - 1], l});
    mp1[v[n - 1]] = l;
    while (m > 0 and !pq1.empty()){
        auto p = pq1.top(); pq1.pop();
        if (!mp1.count(p.first)) continue;
        m --;
        // cout << p.first << " " << p.second << " " << abs(p.first - p.second) << endl;
        pq1.push({p.first, mp1[p.second]});
        mp1[p.first] = mp1[p.second];
        mp1.erase(p.second);
    }
    cout << (pq1.empty() ? l : abs(pq1.top().first - pq1.top().second)) << endl;

    // auto pq1t = pq1;
    // while (!pq1t.empty()){
    //     auto p = pq1t.top(); pq1t.pop();
    //     cout << p.first << " " << p.second << " " << abs(p.first - p.second) << endl;
    // };
    // cout << endl << endl;

    m = mm;
    class cmp2{
    public:
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            return abs(a.first - a.second) < abs(b.first - b.second);
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> pq2;
    pq2.push({0, v[0]});
    unordered_map<int, int> mp2;
    mp2[0] = v[0];
    for (int i = 1; i <n; ++ i) {
        pq2.push({v[i - 1], v[i]});
        mp2[v[i - 1]] = v[i];
    }
    pq2.push({v[n - 1], l});
    mp2[v[n - 1]] = l;

    while (m > 0 and !pq2.empty()){
        auto p = pq2.top(); pq2.pop();
        int mid = p.first + (p.second - p.first) / 2;
        m --;
        // cout << p.first << " " << p.second << " " << abs(p.first - p.second) << endl;
        pq2.push({p.first, mid});
        pq2.push({mid, p.second});
        mp2[mid] = p.second;
        mp2[p.first] = mid;
    }
    cout << abs(pq2.top().first - pq2.top().second) << endl;

    // auto pq2t = pq2;
    // while (!pq2t.empty()){
    //     auto p = pq2t.top(); pq2t.pop();
    //     cout << p.first << " " << p.second << " " << abs(p.first - p.second) << endl;
    // };
    // cout << endl << endl;
}