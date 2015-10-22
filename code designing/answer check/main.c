#include <stdio.h>
#include <stdlib.h>

void main()
{
   int n,num;
   n=1;
   while(n<6)
   {
      num=0;
      switch(n)
      {
     case 1:
        num=n;
     case 2:
        num=num+2*n;
        break;
     case 3:
        num=num+3*n;
        break;
     case 4:
        num=num+4*n;
     default:
        num=num+5*n;
        break;
        }
   printf("%d ",num);
   n++;
   }

    return 0;
}
