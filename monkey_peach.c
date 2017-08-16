#include<stdio.h>
#define dead_day 9


int main()
{
    int peach_num;
    int day;
    peach_num=1;
    for(day=dead_day;day>0;day--)
    {
        peach_num=(peach_num+1)*2;
    }
    printf("1th peach_num:%d\n",peach_num);
}
