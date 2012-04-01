/*****************************************************************************/
/* TEGO PLIKU, ABSOLUTNIE POD ZADNYM POZOREM NIE MODYFIKUJEMY !!!            */
/*****************************************************************************/

#include "SGA_Facade.h"

void SGA_Facade::Print_Parameters(ostream& out)
{
	out << "SGA Parameters:" << endl;
	out << "\tP_mutation=" << P_Mutation() << endl;
	out << "\tP_crossover=" << P_Crossover() << endl;
	out << "\tPopulation Size=" << Pop_Size() << endl;
	out << "\tReal Numbers in Phenotype=" << Phenotype_Number() << endl;
	out << endl;
}

void SGA_Facade::Print_Statistics(ostream& out, int mode)
{
	if (mode & 1)
	{
		out.setf(ios::fixed,ios::floatfield);
		out.precision(6);
		out << "FV_A=" << average_fit;
		out << "\tFV_B=" << best_fit;
		out << "\tFV_W=" << worst_fit << endl;
	}
	if (mode & 2)
	{
		out << "\tBI=" << Individual_Value(best_index,0);
		out << "\tWI=" << Individual_Value(worst_index,0) << endl;
	}
}

void SGA_Facade::Calc_Statistics()
{
	float sum=Individual_Fitness(0);
	best_fit=sum;
	worst_fit=sum;
	best_index=0;
	worst_index=0;
	average_fit=0;
	for (int i=1; i<Pop_Size(); i++)
	{
		float f=Individual_Fitness(i);
		sum+=f;
		if (f>best_fit) {best_fit=f; best_index=i;};
		if (f<worst_fit) {worst_fit=f; worst_index=i;};
	}
	average_fit = sum/Pop_Size();
}
