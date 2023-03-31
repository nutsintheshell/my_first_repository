#include<stdio.h>
#include<time.h>
char buffer[100];
char array[100];
char stack[100];
char read[100];
int length=0, len=0, ls=0, lr=0, k;
char getch()
{
    if(length>0)
    {
        length--;
        return buffer[length];
    }
    else
    {
        return getchar();
    }
}
void putch(char c)
{
    buffer[length]=c;
    length++;
    return;
}
int readnumber()
{
    char c;
    int sum=0;
    while((c=getch())!='-'&&c!='\n'&&c!=' ')
    {
        sum=sum*10+c-'0';
    }
    putch(c);
    return sum;
}
int max(int a, int b)
{
    return a>b?a:b;
}
int min(int a, int b)
{
    return a>b?b:a;
}
int judge(int a, char s[], int l, int e)
{
    if(a==lr-1)
    {
        if(l==1&&read[a]==s[0])
        {
            return 1;
        }
        if(l==0&&read[a]==array[e])
        {
            return 1;
        }
        return 0;
    }else if (e==len)
    {
        for(int i=0;i<l;i++)
        {
            if(read[a+i]!=s[l-i-1])
            {
                return 0;
            }
        }
        return 1;
    }
    if(l==0)
    {
        char stack[10];
        for(int i=0;i<l;i++)
        {
            stack[i]=s[i];
        }
        stack[l]=array[e];
        return judge(a, stack, l+1, e+1);
    }
    for(int i=0;i<k;i++)
    {
        if(a+i<lr&&l-i-1>=0&&read[a+i]!=s[l-i-1])
        {
            char stack[10];
            for(int j=0;j<l;j++)
            {
                stack[j]=s[j];
            }
            stack[l]=array[e];
            return judge(a, stack, l+1, e+1);
            break;
        }
    }
    char stack1[10], stack2[10];
    for(int i=0;i<max(l-k, 0);i++)
    {
        stack1[i]=s[i];
    }
    for(int i=0;i<l;i++)
    {
        stack2[i]=s[i];
    }
    stack2[l]=array[e];
    return judge(min(a+k, a+l), stack1, max(l-k, 0) , e)||judge(a, stack2, l+1, e+1);
}
int main()
{
    char c;
    while((c=getch())!='\n'&&c!=' ')
    {
        if(c-'A'>=0&&c-'A'<7)
        {
            array[len++]=c;
        }
        if(c-'0'>=0&&c-'0'<=9)
        {
            putch(c);
            int l=readnumber();
            for(int i=0;i<l-1;i++)
            {
                array[len]=array[len-1];
                len++;
            }
        }
    }
    while((c=getch())==' '){}
    putch(c);
    k=readnumber();
    while((c=getch())<'A'||c>'G'){}
    putch(c);
    int a[10], i=0;
    while((c=getch())!=EOF)
    {
        putch(c);
    while((c=getch())!='\n'&&c!=EOF)
    {
        read[lr++]=c;
    }
    if(judge(0, stack, 0, 0))
    {
        a[i]=1;
    }
    else
    {
        a[i]=0;
    }
    lr=0;
    i++;
    if(c==EOF)
    {
        break;
    }
    }
    for(int j=0;j<i;j++)
    {
        if(a[j]==1)
        {
            printf("true\n");
        }
        else{
            printf("false\n");
        }
    }
    return 0;
}
