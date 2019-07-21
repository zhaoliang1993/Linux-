#include<stdio.h>
#include<stdlib.h>   //环境表变量是标C的函数，它在stdlib.h头文件中
#include<string.h>

int main(int argc,char** argv,char** env)
{
    extern char** environ;
    printf("%p, %p\n",env,environ);
    char* value = getenv("pwd");
    printf("value = %s\n",value);

    putenv("VAR=ABC");   //会替换已存在的值
    value = getenv("VAR");
    printf("VAR = %s\n",value);

    setenv("VAR","123",0);
    printf("VAR = %s\n",getenv("VAR"));  //第三个参数0不会替换以存在的值，1为替换

    setenv("VAR","456",1);
    printf("VAR = %s\n",getenv("VAR"));
    return 0;
}
