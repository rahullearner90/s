#include <stdio.h>
int mutex=1, full=0,empty=3, x=0;
int main()
{
int n;
void producer1();
void consumer1();
int wait(int);
int signal(int);
printf("\n1.Producer\n2.Consumer\n3.Exit");
while(1)
{
printf("\nEnter your Choice:");
scanf("%d",&n);
switch(n)
{
case 1: if((mutex==1)&&(empty!=0))
producer1();
else
printf("Butter is full!!");
break;
case 2: if((mutex==1)&&(full!=0))
consumer1();
else
printf("Butter is empty!!");
break;
case 3:
break;
}
}
return 0;
}
int wait(int s)
{
return (--s);
}
int signal(int s)
{
return(++s);
}
void producer1()
{
mutex=wait(mutex);
full=signal(full);
empty=wait(empty);
x++;
printf("\nProduer produces the item %d",x);
mutex=signal(mutex);
}
void consumer1()
{
mutex=wait(mutex);
full=wait(full);
empty=signal(empty);
printf("\nConsumer consumes item %d",x);
x--;
mutex=signal(mutex);
}

/*
Explanation:
1. The code begins with the inclusion of the standard input-output library <stdio.h> and
declares some global variables: mutex, full, empty, and x.
2. The main function initializes variables and enters an infinite loop that presents a menu to
the user for selecting between producer, consumer, or exit options.
3. Inside the loop, the user's choice is taken as input, and the code performs the selected
operation based on the choice using a switch statement.
4. The wait and signal functions are simple semaphore operations. wait decrements the
semaphore value, and signal increments it. These functions are used for synchronization
and mutual exclusion.
5. In the producer1 function, the producer is attempting to produce an item. It first acquires
the mutex semaphore to ensure exclusive access to the shared variables. Then it
updates the semaphores full and empty accordingly, indicating that a new item has been
produced. Finally, it increments the item count x and releases the mutex.
6. In the consumer1 function, the consumer is attempting to consume an item. It follows a
similar pattern to the producer1 function but in the reverse order. It also updates the item
count x and releases the mutex.
7. Depending on the user's choice, the program either produces an item, consumes an
item, or exits.
8. This code demonstrates a simple producer-consumer scenario with a fixed-size buffer.
The mutex, full, and empty semaphores are used to ensure that the producer and
consumer processes operate in a coordinated and mutually exclusive manner. The
program continues to run until the user chooses to exit.
*/