#define LOCAL
#ifndef LOCAL
#include<bits/stdc++.h>
#else
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#include<numeric>
#include<climits>
#include<bitset>
#include<functional>
#include<cmath>
#endif // LOCAL

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
namespace luoyu {
    using namespace std;
//#pragma GCC optimize("Ofast")   
#define PB push_back
#define EB emplace_back
#define fi first
#define se second
#define MP make_pair
#define LB lower_bound
#define UB upper_bound
#define CE cout << endl
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;++i)
#define FFOR(i,a,b) for(int i=(a),_ii=(b);i<=_ii;++i)
#define EOR(j,a,b) for(int j=(a),_I=(b);j>_I;--j)
#define EEOR(j,a,b) for(int j=(a),_II=(b);j>=_II;--j)
#define ALL(x) x.begin(), x.end()
#define SZ(a) ((int)a.size())

    typedef vector<int> VI;
    typedef vector<vector<int>> VVI;
    typedef pair<int, int> pii;
    typedef long long ll;
    typedef unsigned long long ull;
    typedef double db;
    const double pi = acos(-1.0);
    const int MOD = 1e9 + 7;
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    //__gcd(int a, int b);
    //lower_bound(x.begin(), x.end(), value);
    //iota(x.begin(),x.end(),val); val,val+1,val+2....
    //fill(x.begin(),x.end(),val); val,val,val....
    //accumulate(x.begin(), x.end(), start_val);
    //next_permutation(x.begin(), x.end());
    //prev(iterator[,n]);将迭代器往后移n个单位，第二个为默认参数=1，返回一个迭代器所在新位置，同理有next(it [,n])
    //nth_element(first，kth，end);  把第k个元素放在正确的位置上，前面的数比它小，后面的数比它大
    //void itoa(int val, char *buffer, int radix);    把整数转为radix进制字符串
    //int atoi(char *buffer);  把字符串转为整数
    template<class T>
    void PRINT(T x) {
        for (auto p = x.begin(); p != x.end(); p++)
            cout << *p << " ";
        cout << endl;
    }
#define PRINT_2(x)                            \
        for (int i = 0, n = x.size(); i < n; i++) \
        {                                         \
            PRINT(x[i]);                          \
        }
    /*template <typename T> inline void read(T& x)
    {
        x = 0; char ch = getchar(); ll f = 1;
        while (!isdigit(ch)) { if (ch == '-')f = -1; ch = getchar(); }
        while (isdigit(ch)) { x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar(); }x *= f;
    }*/
    void quick_read(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
}//namespace luoyu

void Dijkstra(){

}
void SPFA(){
    
}
using namespace luoyu;
int main() {
    quick_read();
    Dijkstra();
    SPFA();
}
