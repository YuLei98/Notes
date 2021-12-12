#include <iostream>
#include <bitset>
using namespace std;
int main(){
    #ifdef LOCALL
        FILE *fp = freopen("./a.in", "r", stdin);       //测试用例所在路径
    #endif
    //题目等价为输出二进制位不少于两个1的个数
    int N;
    cin >>N;
    int ans = 0;
    while (N--){
        int x; cin >> x;
        bitset<4> b(x);
        int sum = b[0] + b[1] + b[2] + b[3];
        if (sum >= 2){
            ans ++;
        }
    }
    cout << ans << endl;
    #ifdef LOCALL
        fclose(fp);
    #endif
    return 0;
}