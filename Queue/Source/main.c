#include"queue.h"
int main()
{
 Queue q;
 initQueue(&q,5);

 enQueue(&q,10);
 enQueue(&q,20);
 enQueue(&q,30);
 enQueue(&q,40);
 enQueue(&q,50);
 enQueue(&q,60);
 Display(q);
 printf("%d is out \n",deQueue(&q));
 printf("%d is out\n",deQueue(&q));
 printf("%d is out\n",deQueue(&q));
 printf("%d is out\n",deQueue(&q));
 printf("%d is out\n",deQueue(&q));
 printf("%d is out\n",deQueue(&q));
 Display(q);
 enQueue(&q,60);
 enQueue(&q,70);
 enQueue(&q,80);
 enQueue(&q,90);
 enQueue(&q,100);
 Display(q);
 
 return 0;
}