/**
* 高精度整数的存储使用数组即可
* 方法：整数的高位存储在数组的高位，整数的低位存储在数组的低位
* 注意：把整数按字符串%s读入的时候，实际上是逆位存储的，因此在读入之后需要在另存为至d[]数组的时候反转一下
**/


//定义结构体变量
struct bign {
    int d[1000];
    int len; //定义int型变量len，方便随时获取大整数的长度

    //需要马上初始化结构体
    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

//将整数转换为bign
bign change(char str[]) {
    bign a;
    a.len = strlen(str); //bign的长度就是字符串的长度
    for (int i = 0; i < a.len; i++) {
        a.d[i] = str[a.len - i - 1] - '0'; //逆着赋值
    }
    return a;
}

//比较两个bign变量的大小
int compare(bign a, bign b) {
    if (a.len > b.len)
        return 1; //a大
    else if (a.len < b.len)
        return -1; //a小
    else {
        //从高位往低位比较
        for (int i = a.len - 1; i >= 0; i--) {
            if (a.d[i] > b.d[i])
                return 1; //只要有一位a大，则a大
            else if (a.d[i] < b.d[i])
                return -1; //只要有一位a小，则a小
        }
        return 0; //两数相等
    }
}
