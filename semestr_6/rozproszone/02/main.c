#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
double f(double x);
double calk(double (*f)(double),int start, int stop, double dt);
int main(int argc, char *argv[])
{
	double g_start=0;
	double g_stop=5;
	double g_dt=0.00001;
	MPI_Init(&argc,&argv);
	int nproc;
	MPI_Comm_size(MPI_COMM_WORLD,&nproc);
	int start,stop;
	double dt;
	int rank;
	double przedz;
	int przedzialow;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	if(rank==0)
	{
		start=g_start;
		stop=g_stop;
		dt=g_dt;
		
		przedzialow=(stop-start)/dt/nproc;


		przedz=(stop-start)/nproc;
	};
	MPI_Bcast(&dt,1,MPI_DOUBLE,0,MPI_COMM_WORLD);
	int i;
	double r_dt;
	int r_start;
	int r_stop;
	for(i=0;i<nproc;i++)
	{
		double a;
		if(rank==0)
		{
			r_dt=dt;	
			r_start=i*przedzialow;
			r_stop=r_start+przedzialow;
		}
		else
		{
			a=0;
		};
		MPI_Bcast(&r_dt,1,MPI_DOUBLE,0,MPI_COMM_WORLD);
		MPI_Bcast(&r_start,1,MPI_INT,0,MPI_COMM_WORLD);
		MPI_Bcast(&r_stop,1,MPI_INT,0,MPI_COMM_WORLD);
		if(i==rank)
		{
			start=r_start;
			stop=r_stop;
			dt=r_dt;
		}
	};
	double l_wynik=calk(f,start,stop,dt);
//	printf("Proc: %d: start: %d, stop: %d, dt: %lf, wynik: %lf\n",rank,start,stop,dt,l_wynik);
	double wynik=0;
	for(i=0;i<nproc;i++)
	{
		double r_wynik;
		if(rank==i)
		{
			r_wynik=l_wynik;
		};
		MPI_Bcast(&r_wynik,1,MPI_DOUBLE,i,MPI_COMM_WORLD);
		if(rank==0)
		{
			wynik+=r_wynik;
		};
	};
	if(rank==0)
	{
		printf("MPI  : %f\n",wynik);
		printf("Iter : %f\n",calk(f,0,(g_stop-g_start)/dt,g_dt));
	};
	MPI_Finalize();
	return 0;
};
double f(double x)
{
	return 2.0f*x;
};
double calk(double (*f)(double),int start, int stop,double dt)
{
	double t=0;
	double wynik=0;
	int i;
	for(i=start,t=start*dt;i<=stop;i++,t+=dt)
//	for(t=start*dt;t<stop*dt;t+=dt)
	{
		wynik+=(f(t)+f(t+dt))/2*dt;
	};
	return wynik;	
};
