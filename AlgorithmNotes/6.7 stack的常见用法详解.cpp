/**
* stack：翻译为栈，是STL中实现的一个后进先出的容器
**/
#include <cstdio>
#include <stack>
using namespace std;


//stack的定义
stack<typename> name;


//stack容器内元素的访问
{
    stack<int> st;
    for (int i = 1; i <= 5; i++)
        st.push(i); //psuh(i)用以把i压入栈，故此处依次入栈1 2 3 4 5
    printf("%d\n", st.top()); // 5
}


//stack常用函数实例解析
//push()  O(1)
//top()  O(1)
//pop()  O(1)
{
    stack<int> st;
    for (int i = 1; i <= 5; i++)
        st.push(i); // 1 2 3 4 5
    for (int i = 1; i <= 3; i++)
        st.pop(); // 5 4 3
    printf("%d\n", st.top()); // 2
}
//empty()
{
    stack<int> st;
    if (st.empty() == true)
        printf("Empty\n");
    else
        printf("Not Empty\n");
    st.push(1);
    if (st.empty() == true)
        printf("Empty\n");
    else
        printf("Not Empty\n");
}
//size()
{
    stack<int> st;
    for (int i = 1; i <= 5; i++)
        st.push(i);
    printf("%d\n", st.size()); // 5
}


//stack的常见用途
//用来模拟实现一些递归，防止程序对栈内存的限制而导致程序运行出错
