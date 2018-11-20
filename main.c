#include <stdio.h>
#include <pthread.h>

void *display1(void *ptr)
{
	int i;
	for(i=0;i<1000;i++){
		printf("%d\n", i);
	}
	return NULL;
}

void *display2(void *ptr)
{
	int i;
	for(i=0;i<10;i++){
		printf("%d\n", i+10000);
	}
	return NULL;
}

int main(int argc, char**argv)
{
	pthread_t thread1, thread2;
	int iret1, iret2;

	iret1 = pthread_create(&thread1, NULL, display1, (void*)NULL);
	iret2 = pthread_create(&thread2, NULL, display2, (void*)NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Thread 1 returns: %d\n", iret1);
	printf("Thread 2 returns: %d\n", iret2);
	return 0;
}

