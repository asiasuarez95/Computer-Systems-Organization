


#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>


#define size 100000000
int array[size];
int numThreads = 4;
long sum = 0;
pthread_mutex_t mutex;



void computeSum(void* t)
{
    int start = (int) t;

    int i;
	int division = size / numThreads;

	int localsum = 0;
	

    
	
	for(i = start * division ; i < (start * division) + division ; i++)
		localsum += array[i];
	

	//pthread_mutex_lock(&mutex);
	sum += localsum;
	//pthread_mutex_unlock(&mutex);
    return;
}

int main()
{
    
  // 	pthread_mutex_init(&mutex, NULL);
   	

   	int i;

	/* Initialize array with integer values */
	for(i = 0 ; i < 100000000 ; i++)
		array[i] = i % 7;


	/* Compute the sum */
	pthread_t thread[numThreads];
	

	for(i = 0; i < numThreads; i++)
	{
		
		pthread_create(&thread[i], NULL, computeSum, (void*) i);
		// pthread_join(thread[i], NULL);
   		
	}
	for(i=0; i<numThreads; i++){
		pthread_join(thread[i], NULL);
	}

  	
   	
	printf("Sum of the array is: %ld\n",sum);

	return 0;
}

