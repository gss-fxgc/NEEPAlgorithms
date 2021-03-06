/**
* 线性表：分为顺序表和链表
**/

//顺序表理解为“数组”

//链表结点结构
struct node {
    typename data; //数据域
    node* next; //指针域
};

//malloc函数
//用于申请动态内存，返回类型为申请的同变量类型的指针
typename* p = (typename*)malloc(sizeof(typename));

//new运算符
//用于申请动态空间，返回类型同样是申请的同变量类型的指针
typename* p = new typename;

//在使用完malloc与new开辟出来的空间后必须将其释放，否则会造成内存泄漏

//free函数
//实现两个效果：释放指针变量p所指向的内存空间；将指针变量p指向空地址NULL
free(p); //malloc与free必须成对出现

//delete运算符
//对应new运算符，使用方法和实现效果与free相同
delete(p); //和new成对出现

//链表的基本操作
//创建链表
node* create(int Array[]) {
    node *p, *pre, *head; //pre保存当前结点的前驱结点，head为头结点
    head = new node; //创建头结点
    head->next = NULL; //头结点不需要数据域，指针域初始为NULL
    pre = head; //记录pre为head
    for (int i = 0; i < 5; i++) {
        p = new node; //新建结点
        //将Array[i]赋给新建的结点作为数据域，也可以scanf输入
        p->data = Array[i];
        p->next = NULL; //新结点的指针域为NULL
        pre->next = p; //前驱结点的指针域设为当前新建结点的地址
        pre = p; //把pre设为p，作为下个结点的前驱结点
    }
    return head; //返回头结点指针
}

//查找元素
int search(node* head, int x) {
    int count = 0; //计数器
    node* p = head->next; //从第一个结点开始
    //只要没有到链表末尾
    while (p != NULL) {
        if (p->data == x)
            count++; //当前结点数据域为x，则count++
        p = p->next; //指针移动到下一个结点
    }
    return count; //返回计数器count
}

//插入元素
void insert(node* head, int pos, int x) {
    node* p = head;
    for (int i = 0; i < pos - 1; i++)
        p = p->next; //pos-1是为了到插入位置的前一个结点
    node* q = new node; //新建结点
    q->data = x; //新结点的数据域为x
    q->next = p->next; //新结点的下一个结点指向原先插入位置的结点
    p->next = q; //前一个位置的结点指向新结点
}

//删除元素
void del(node* head, int x) {
    node* p = head->next; //p从第一个结点开始枚举
    node* pre = head; //pre始终保存p的前驱结点的指针
    while (p != NULL) {
        if (p->data == x) {
            //数据域恰好为x，说明要删除结点
            pre->next = p->next;
            delete(p);
            p = pre->next;
        } else {
            //数据域不是x，把pre和p都后移一位
            pre = p;
            p = p->next;
        }
    }
}

//静态链表
//实现原理是hash
struct Node {
    typename data; //数据域
    int next; //指针域
} node[size];
