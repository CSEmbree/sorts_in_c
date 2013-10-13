//Cameron S. Embree
//CREATED:  10/01/13
//MODIFIED: 10/01/13
//
//COMPILE: sh setup.sh
// setup executes: gcc -std=c99 -g -DDEBUG=0 sortcmp.c quick.c merge.c insert.c -o sortcmp
//RUN: "/.sortcmp"

#include "sortcmp.h"


int main(int argc, char **argv)
{
    int arraySize = MAX_SIZE; //arbitrary large array for extenuating

    if(argc == 2)
        arraySize = atoi(argv[1]); //let user easily change the size of test arrays
 

    printf("Testing sorting algorithms with arrays of SIZE: '%s'\n", argv[1]);

	TestMergeSort( arraySize ); 
    printf("\n"); //formatting

    TestInsertionSort( arraySize ); 
    printf("\n"); //formatting

	//TestQuickSort( arraySize ); 
    //printf("\n"); //formatting


   return SUCCESS;
}


void TestMergeSort(int arraySize)
{
    printf("Testing MergeSort...\n");

	int low  = 0;
	int high = arraySize;
	int A[arraySize];
    int B[arraySize];
	double duration;
	clock_t t;
 

	// ACEDNING DATA
    for(int i = 0; i<arraySize; i++ ) A[i] = i; //filled array 0,1,2,...,8,9
    
    #ifndef DEBUG
    printf("\nData BEFORE Sort: ");
    DisplayList(A, arraySize);
    #endif
    t = clock();

    MergeSort(A, high);  //sort call

    #ifndef DEBUG
    printf("\nData AFTER Sort: ");
    DisplayList(A, arraySize);
    #endif
    t = clock() - t;
    duration = ExecutionTime( t, CLOCKS_PER_SEC );

    printf("\n\t INC ORDER TIME: \t%f sec\n", duration);


    // RAN DATA
    for(int i = 0; i<arraySize; i++ ) A[i] = rand()%MAX_SIZE; //RAN values 0-9
    t = clock();
    #ifndef DEBUG
    printf("\nData BEFORE Sort: ");
    DisplayList(A, arraySize);
    #endif

    MergeSort(A, high);  //sort call

    #ifndef DEBUG
    printf("\nData AFTER Sort: ");
    DisplayList(A, arraySize);
	#endif
    t = clock() - t;
    duration = ExecutionTime( t, CLOCKS_PER_SEC );

    printf("\n\t RAN DATA TIME: \t%f sec\n", duration);


    // DEC DATA
    for(int i = arraySize; i>0; i-- ) A[arraySize-i] = i; //filled array 10,9,8,...,2,1
    t = clock();
    #ifndef DEBUG
    printf("\nData BEFORE Sort: ");
    DisplayList(A, arraySize);
    #endif

    MergeSort(A, high); //sort call

    #ifndef DEBUG
    printf("\nData AFTER Sort: ");
    DisplayList(A, arraySize);
	#endif
    t = clock() - t;
    duration = ExecutionTime( t, CLOCKS_PER_SEC );

    printf("\n\t DEC DATA TIME: \t%f sec\n", duration);
}

void TestQuickSort(int arraySize)
{
	printf("Testing QuickSort...\n");

	int low  = 0;
	int high = arraySize;
	int A[arraySize];
	double duration;
	clock_t t;
  


	// ACEDNING DATA
    for(int i = 0; i<arraySize; i++ ) A[i] = i; //filled array 0,1,2,...,8,9
    t = clock();
    #ifndef DEBUG
    printf("Data BEFORE Sort: ");
    DisplayList(A, arraySize);
    #endif

    QuickSort(A, low, high);

    #ifndef DEBUG
    printf("\nData AFTER Sort: ");
    DisplayList(A, arraySize);
	#endif
    t = clock() - t;
    duration = ExecutionTime( t, CLOCKS_PER_SEC );

    printf("\n\tINC DATA TIME: \t%f sec\n", duration);



    // RAN DATA
    for(int i = 0; i<arraySize; i++ ) A[i] = rand()%MAX_SIZE; //RAN values 0-9
    t = clock();
    #ifndef DEBUG
    printf("Data BEFORE Sort: ");
    DisplayList(A, arraySize);
    #endif

    QuickSort(A, low, high);

    printf("\nData AFTER Sort: ");
    #ifndef DEBUG
    DisplayList(A, arraySize);
	#endif
    t = clock() - t;
    duration = ExecutionTime( t, CLOCKS_PER_SEC );

    printf("\n\tRAN DATA TIME: \t%f sec\n", duration);



    // DEC DATA
    for(int i = arraySize; i>0; i-- ) A[arraySize-i] = i; //filled array 10,9,8,...,2,1
    t = clock();
    #ifndef DEBUG
    printf("Data BEFORE Sort: ");
    DisplayList(A, arraySize);
    #endif

    QuickSort(A, low, high);
	
    #ifndef DEBUG
    printf("\nData AFTER Sort: ");
    DisplayList(A, arraySize);
    #endif
    t = clock() - t;
    duration = ExecutionTime( t, CLOCKS_PER_SEC );

    printf("\n\tDEC DATA TIME: \t%f sec\n", duration);
}

void TestInsertionSort(int arraySize)
{
	printf("Testing InsertionSort...\n");

	int low  = 0;
	int high = arraySize;
	int A[arraySize];
	double duration;
	clock_t t;


	// ACENDING
    for(int i=0; i<arraySize; i++ ) A[i] = i; //filled array 0,1,2,...,8,9
    t = clock();
    #ifndef DEBUG
    printf("Data BEFORE Sort: ");
    DisplayList(A, arraySize);
    #endif

    InsertionSort(A, arraySize); //sort call
	
    #ifndef DEBUG
    printf("\nData AFTER Sort: ");
    DisplayList(A, arraySize);
    #endif
    t = clock() - t;
    duration = ExecutionTime( t, CLOCKS_PER_SEC );

    printf("\n\t INC ORDER TIME: \t%f sec\n", duration);



    // RAN
    for(int i=0; i<arraySize; i++ ) A[i] = rand()%MAX_SIZE; //RAN values 0-9
    t = clock();
    #ifndef DEBUG
    printf("Data BEFORE Sort: ");
    DisplayList(A, arraySize);
    #endif

    InsertionSort(A, arraySize); //sort call
	
    #ifndef DEBUG
    printf("\nData AFTER Sort: ");
    DisplayList(A, arraySize);
    #endif
    t = clock() - t;
    duration = ExecutionTime( t, CLOCKS_PER_SEC );

    printf("\n\t RAN DATA TIME: \t%f sec\n", duration);



    // DEC
    for(int i=arraySize; i>0; i-- ) 
    A[arraySize-i] = i; //filled array 10,9,8,...,2,1
    t = clock();
    #ifndef DEBUG
    printf("Data BEFORE Sort: ");
    DisplayList(A, arraySize);
    #endif

    InsertionSort(A, arraySize); //sort call
	
    #ifndef DEBUG
    printf("\nData AFTER Sort: ");
    DisplayList(A, arraySize);
    #endif
    t = clock() - t;
    duration = ExecutionTime( t, CLOCKS_PER_SEC );

    printf("\n\t DEC ORDER TIME: \t%f sec\n", duration);
}

void DisplayList(int *Array, int arraySize)
{
    for (int i = 0; i < arraySize; ++i)
        printf(" %d", Array[i]);
}

double ExecutionTime(double duration, double factor)
{
    return ((double)duration)/CLOCKS_PER_SEC;
}
