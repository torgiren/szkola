#include <stdio.h>
int main()
{
	float x;
	float *px=NULL;
	float *py=NULL;

	printf("&x=%p\t&px=%p\t&py=%p\n",&x,&px,&py);
	printf("x=%f\tpx=%p\tpy=%p\n",x,px,py);
	if(px)
	{
		printf("*px=%f\t",*px);
	}
	else
	{
		printf("px jest null\t");
	};
	if(py)
	{
		printf("*py=%f\n",*py);
	}
	else
	{
		printf("py jest null\n");
	};
	printf("\n");


	x=12;

	printf("&x=%p\t&px=%p\t&py=%p\n",&x,&px,&py);
	printf("x=%f\tpx=%p\tpy=%p\n",x,px,py);
	if(px)
	{
		printf("*px=%f\t",*px);
	}
	else
	{
		printf("px jest null\t");
	};
	if(py)
	{
		printf("*py=%f\n",*py);
	}
	else
	{
		printf("py jest null\n");
	};

	printf("\n");


	px=&x;
	
	
	printf("&x=%p\t&px=%p\t&py=%p\n",&x,&px,&py);
	printf("x=%f\tpx=%p\tpy=%p\n",x,px,py);
	if(px)
	{
		printf("*px=%f\t",*px);
	}
	else
	{
		printf("px jest null\t");
	};
	if(py)
	{
		printf("*py=%f\n",*py);
	}
	else
	{
		printf("py jest null\n");
	};

	printf("\n");
	
	py=px;


	printf("&x=%p\t&px=%p\t&py=%p\n",&x,&px,&py);
	printf("x=%f\tpx=%p\tpy=%p\n",x,px,py);
	if(px)
	{
		printf("*px=%f\t",*px);
	}
	else
	{
		printf("px jest null\t");
	};
	if(py)
	{
		printf("*py=%f\n",*py);
	}
	else
	{
		printf("py jest null\n");
	};

	printf("\n");


	*py=123;

	printf("&x=%p\t&px=%p\t&py=%p\n",&x,&px,&py);
	printf("x=%f\tpx=%p\tpy=%p\n",x,px,py);
	if(px)
	{
		printf("*px=%f\t",*px);
	}
	else
	{
		printf("px jest null\t");
	};
	if(py)
	{
		printf("*py=%f\n",*py);
	}
	else
	{
		printf("py jest null\n");
	};

	printf("\n");
	return 0;
};

