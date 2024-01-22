## 作业20230908-补

姜俊彦 2022K8009970011

### 分析执行结果

源码：

```C
#include <stdio.h>
int main()
{
    int caculate(int x, int y);
    int a, b, c;
    a = 10;
    b = 8;
    c = caculate(a, b);
    printf("c=%d\n", c);
    a = 7;
    b = 12;
    c = caculate(a, b);
    printf("c=%d\n", c);
    return 0;
}
int caculate(int x, int y)
{
    int z;
    if (x > y)
        z = x - y;
    else
        z = x * y;
    return z;
}
```

 执行结果分析

```
第4行：声明所用函数caculate;
第5行：声明所用变量a,b,c及类型；
第6行：对变量a赋值10；
第7行：对变量b赋值8；
第8行：此处调用函数caculate，实参a=10,b=8；

此处执行至函数caculate入口，形参x=a=10,y=b=8;
第18行：声明局部变量及类型z；
第19行：条件判断x>y，条件成立，跳转到第20行;
第20行：对变量z赋值x-y，跳转到23行;
第23行：返回值z；

第8行：对变量c赋值caculate的返回值2；
第9行：打印字符串“c=2”；
第10行：对变量a赋值7；
第11行：对变量b赋值12；
第12行：此处调用函数caculate，实参a=7,b=12；

此处执行至函数caculate入口，形参x=a=7,y=b=12;
第18行：声明局部变量及类型z；
第19行：条件判断x>y，条件不成立，跳转到第22行;
第22行：对变量z赋值x*y，跳转到23行;
第23行：返回值z；

第12行：对变量c赋值caculate的返回值84；
第13行：打印字符串“c=84”；
第14行：main函数返回0,程序运行完毕




```

运行结果截图：

![搭建环境及分析结果](E:\VSCODE\UbuntuShare\C\Homework\Homework1\搭建环境及分析结果.png)