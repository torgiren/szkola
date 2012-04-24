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

extern float E1,E2,B,T;

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
		out << endl << "Posilek:" << endl;
		out << "\tmleko       =" << Individual_Value(best_index,0) << " g" << endl;
		out << "\tser         =" << Individual_Value(best_index,1) << " g" << endl;
		out << "\tszynka      =" << Individual_Value(best_index,2) << " g" << endl;
		out << "\tmaslo       =" << Individual_Value(best_index,3) << " g" << endl;
		out << "\tchleb       =" << Individual_Value(best_index,4) << " g" << endl;
		out << "\tbrzoskwinie =" << Individual_Value(best_index,5) << " g" << endl;
		float m=0, E=0, b=0, t=0, w=0;
		for (int i=0; i<6; i++)
		{
			m+=Individual_Value(best_index,i);
			E+=Individual_Value(best_index,i)*products[i].E;
			b+=Individual_Value(best_index,i)*products[i].B;
			t+=Individual_Value(best_index,i)*products[i].T;
			w+=Individual_Value(best_index,i)*products[i].W;
		}
		out << "---------------"<<endl;
		out << "\tMasa        =" << m << " g "<<endl;
		out << "\tWeglowodany =" << w << " g "<<endl;
		out << "\tBialko      =" << b << " g ";
		if(b>B)
			cout<<"\tV"<<endl;
		else
			cout<<"\tX"<<endl;
		out << "\tTlusz       =" << t << " g ";
		if(t<T)
			cout<<"\tV"<<endl;
		else
			cout<<"\tX"<<endl;
		out << "\tEnergia     =" << E << " kcal";
		if(E1<E && E2>E)
			cout<<"\tV"<<endl;
		else
			cout<<"\tX"<<endl;
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

product products[6] = 
{ 
	0.64 , 0.033 , 0.048 , 0.036, // mleko
	3.16 , 0.279 , 0.001 , 0.229, // ser Gouda
	2.53 , 0.171 , 0.009 , 0.203, // szynka
	7.35 , 0.007 , 0.007 , 0.825, // mas³o
	2.41 , 0.004 , 0.571 , 0.013, // chleb
	0.46 , 0.001 , 0.119 , 0.002  // brzoskwinie
};
