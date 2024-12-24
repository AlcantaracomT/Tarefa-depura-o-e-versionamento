#include <stdio.h>
int main()
{
    for (int i; i<10;i++)
    {
        if(i*i>100)
        {
            break;
        }
        else{
            printf("%d \n",(i*i));
        }
    }
}