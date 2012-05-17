#ifndef __MYMPE_H
#define __MYMPE_H
#include <mpi.h>
#include <mpe.h>
#define START_BCAST 0
#define END_BCAST 1
#define START_SEND 2
#define END_SEND 3
#define START_RECV 4
#define END_RECV 5
int MPI_Init(int *argc, char*** argv);
int MPI_Bcast(void* buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm);
int MPI_Send(void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);
int MPI_Recv(void* buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status);
int MPI_Finalize(void);
#endif
