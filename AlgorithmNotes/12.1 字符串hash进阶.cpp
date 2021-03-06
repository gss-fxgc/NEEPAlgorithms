/**
* 字符串hash进阶
**/

//问题1：给出N个只有小写字母的字符串，求其中不同的字符串的个数
//问题2：输入两个长度均不超过1000的字符串，求它们的最长公共子串的长度

//问题3：用hash+二分的思路解决最长回文子串
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007; //MOD为计算hash值时的模数
const LL P = 10000019; //P为计算hash值时的进制数
const LL MAXN = 200010; //MAXN为字符串最长长度

LL powP[MAXN], H1[MAXN], H2[MAXN]; //powP[i]存放P^i%MOD，H1和H2分别存放str和rstr的hash值

//初始化powP
void init() {
    powP[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        powP[i] = (powP[i - 1] * P) % MOD;
    }
}

//计算字符串str的hash值
void calH(LL H[], string &str) {
    H[0] = str[0]; //H[0]单独处理
    for (int i = 1; i < str.length(); i++) {
        H[i] = (H[i - 1] * P + str[i]) % MOD;
    }
}

//计算H[i…j]
int calSingleSubH(LL H[], int i, int j) {
    if (i == 0)
        return H[j]; //H[0…j]单独处理
    return ((H[j] - H[i - 1] * powP[j - i + 1]) % MOD + MOD) % MOD;
}

//对称点为i，字符串长len，在[l,r]里二分回文半径
//寻找最后一个满足条件“hashL == hashR”的回文半径
//等价于寻找第一个满足条件“hashL != hashR”的回文半径，然后减1即可
//isEven当求奇回文时为0，当求偶回文时为1
int binarySearch(int l, int r, int len, int i, int isEven) {
    //当出现l==r时结束（因为范围是[l,r]）
    while (l < r) {
        int mid = (l + r) / 2;
        //左半子串hash值H1[H1L…H1R]，右半子串hash值H2[H2L…H2R]
        int H1L = i - mid + isEven, H1R = 1;
        int H2L = len - l - (i + mid), H2R = len - l - (i + isEven);
        int hashL = calSingleSubH(H1, H1L, H1R);
        int hashR = calSingleSubH(H2, H2L, H2R);
        if (hashL != hashR)
            r = mid; //hash值不等，说明回文半径<=mid
        else
            l = mid + 1; //hash值相等，说明回文半径>mid
    }
    return l - 1; //返回最大回文半径
}

int main() {
    init(); //初始化powP
    string str;
    getline(cin, str);
    calH(H1, str); //计算str的hash数组
    reverse(str.begin(), str.end()); //将字符串反转
    calH(H2, str); //计算rstr的hash数组
    int ans = 0;
    //奇回文
    for (int i = 0; i < str.length(); i++) {
        //二分上界为分界点i的左右长度较小值加1
        int maxLen = min(i, (int)str.length() - 1 - i) + 1;
        int k = binarySearch(0, maxLen, str.length(), i, 0);
        ans = max(ans, k * 2 + 1);
    }
    //偶回文
    for (int i = 0; i < str.length(); i++) {
        //二分上界为分界点i的左右长度的较小值加1（注意左长为i+1）
        int maxLen = min(i + 1, (int)str.length() - 1 - i) + 1;
        int k = binarySearch(0, maxLen, str.length(), i, 1);
        ans = max(ans, k * 2);
    }
    printf("%d\n", ans);
    return 0;
}
