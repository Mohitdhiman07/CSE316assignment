#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define maxvalue 10000
#define minvalue 2

void *getuserinput()
{
int *user_input=(int*)malloc(sizeof(int));
puts("can enter a number between[0-10000]");
while(1)
{
	printf("enter your number:-");
	scanf("%d",user_input);
	if(*user_input<minvalue || *user_input>maxvalue)
	{
		printf("you entered the no.out of the range\n");
		rewind(stdin);
    } else break;
	}
	puts("input thread has recieved the input from user");
	pthread_exit(user_input);
}
int checkprime(int number)
{
	if(number==1) return 0;
	int i;
	for(i=2;i<=(int)(number/2);i++)
	   if(!(number%i)) return 0;
	return 1;
}
void *printprimeuntil(void *argument)
{
	int number= *((int *)argument),i,count=0;
	printf("thread 2 has recieved:%d\n",number);
	for(i=2;i<=number;i++)
	{
		if(checkprime(i))
		{
			printf("%7d",i);
			if(!(++count%7))
			printf("\n");
		}
	}
	pthread_exit(NULL);
}
int main()
{
 pthread_t input_thread, output_thread;
    void *ret_number;

    
    if(pthread_create(&input_thread,NULL,getuserinput,NULL))
        return -1*printf("an error occured during creation of thread\n");

    pthread_join(input_thread,&ret_number);

    int *number = (int *)ret_number;

    
    if(pthread_create(&output_thread,NULL,&printprimeuntil,(void *)number))
       return -1*printf("an error occured during creation of thread\n");

    return pthread_join(output_thread,NULL);
}

