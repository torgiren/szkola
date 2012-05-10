/*
#include "mympe.h"
int MPI_Init(int *argc, char*** argv)
{
        int wynik=PMPI_Init(argc,argv);
        MPE_Init_log();
        int proc;
        MPI_Comm_rank(MPI_COMM_WORLD,&proc);
        if(proc==0)
        {
                MPE_Describe_state(START_BCAST,END_BCAST,"broadcast","red");
                MPE_Describe_state(START_SEND,END_SEND,"send","blue");
                MPE_Describe_state(START_RECV,END_RECV,"recv","green");
        };
        MPE_Start_log();

        return wynik;
};
int MPI_Bcast(void* buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm)
{
        MPE_Log_event(START_BCAST,0,"bcast");
        int wynik=PMPI_Bcast(buffer,count,datatype,root,comm);
        MPE_Log_event(END_BCAST,0,"bcast");
        return wynik;

};
int MPI_Send(void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
        MPE_Log_event(START_SEND,0,"send");
        int wynik=PMPI_Send(buf,count,datatype,dest,tag,comm);
        MPE_Log_event(END_SEND,0,"send");
        return wynik;
};
int MPI_Recv(void* buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status)
{
        MPE_Log_event(START_RECV,0,"recv");
        int wynik=PMPI_Recv(buf,count,datatype,source,tag,comm,status);
        MPE_Log_event(END_RECV,0,"recv");
        return wynik;
};
int MPI_Finalize(void)
{
        MPE_Finish_log("log.dat");
        return PMPI_Finalize();
};
*/
