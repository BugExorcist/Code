#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    printf("Hello world from rank %d out of %d processors\n", world_rank, world_size);
    MPI_Finalize();
    return 0;
}






//#include"mpi.h"
//#include<iostream>
//using namespace std;
//
//int main(void) {
//	int rankID;
//	int sizeNum;
//	MPI_Init(0, 0);
//	MPI_Comm_size(MPI_COMM_WORLD, &sizeNum);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rankID);
//	cout << "Hello world! " << rankID << " of total =" << sizeNum << endl;
//	MPI_Finalize();
//	return 0;
//}


//#include "mpi.h"
//#include <stdio.h>
//#include <windows.h>
//#include <tchar.h>
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	int myrank, nprocs, name_len, flag;
//	double start_time, end_time;
//	char host_name[20];
//
//	MPI_Initialized(&flag);
//	fprintf(stderr, "flag:%d/n", flag);
//
//	MPI_Init(0, 0);
//
//	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
//	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
//
//	MPI_Get_processor_name(host_name, &name_len);
//
//	if (myrank == 0)
//	{
//		fprintf(stderr, "Precision of MPI_WTIME(): %f.\n", MPI_Wtick());
//		fprintf(stderr, "Host Name:%s\n", host_name);
//	}
//
//	start_time = MPI_Wtime();
//	Sleep(myrank * 3);
//	end_time = MPI_Wtime();
//
//	fprintf(stderr, "myrank: %d. I have slept %f seconds.\n", myrank, end_time - start_time);
//
//
//	MPI_Finalize();
//
//	return 0;
//}