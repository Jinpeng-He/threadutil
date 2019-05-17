#include "ThreadPool.h"

#define MAX_THREADS 		8
#define MIN_THREADS 		5
#define JOBS_PER_THREAD 	3
#define THREAD_IDLE_TIME 	5000
#define MAX_JOBS_TOTAL 		10

static void thread_task(void*args)
{
	char*test_char=(char*)args;
	if(test_char)
		printf("hjptestfor:%s\n",test_char);
	else
		printf("hjptestfor:args is null\n");
}

int main(void)
{
    ThreadPoolJob job;
	ThreadPool print_thread_pool;
	ThreadPoolAttr attr;
	TPAttrInit( &attr );
    TPAttrSetMaxThreads( &attr, MAX_THREADS );
    TPAttrSetMinThreads( &attr, MIN_THREADS );
    TPAttrSetJobsPerThread( &attr, JOBS_PER_THREAD );
    TPAttrSetIdleTime( &attr, THREAD_IDLE_TIME );
    TPAttrSetMaxJobsTotal( &attr, MAX_JOBS_TOTAL );
	
    if( ThreadPoolInit( &print_thread_pool, &attr ) != 0 )
    {
        ThreadPoolShutdown(&print_thread_pool);
		printf("ThreadPoolInit failed !!!\n");
        return -1;
    }


	
    TPJobInit( &job, ( start_routine ) thread_task,
               "arg test" );
    TPJobSetFreeFunction( &job, NULL );
    TPJobSetPriority( &job, MED_PRIORITY );
	ThreadPoolAdd( &print_thread_pool, &job, NULL );
	printf("hjptestfor:11111\n");
	while(1);
	return 0;
}