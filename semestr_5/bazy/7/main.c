/* Processed by ecpg (4.5.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "main.pgc"
#include <stdio.h>

#line 1 "/usr/include/postgresql/sqlca.h"
#ifndef POSTGRES_SQLCA_H
#define POSTGRES_SQLCA_H

#ifndef PGDLLIMPORT
#if  defined(WIN32) || defined(__CYGWIN__)
#define PGDLLIMPORT __declspec (dllimport)
#else
#define PGDLLIMPORT
#endif   /* __CYGWIN__ */
#endif   /* PGDLLIMPORT */

#define SQLERRMC_LEN	150

#ifdef __cplusplus
extern		"C"
{
#endif

struct sqlca_t
{
	char		sqlcaid[8];
	long		sqlabc;
	long		sqlcode;
	struct
	{
		int			sqlerrml;
		char		sqlerrmc[SQLERRMC_LEN];
	}			sqlerrm;
	char		sqlerrp[8];
	long		sqlerrd[6];
	/* Element 0: empty						*/
	/* 1: OID of processed tuple if applicable			*/
	/* 2: number of rows processed				*/
	/* after an INSERT, UPDATE or				*/
	/* DELETE statement					*/
	/* 3: empty						*/
	/* 4: empty						*/
	/* 5: empty						*/
	char		sqlwarn[8];
	/* Element 0: set to 'W' if at least one other is 'W'	*/
	/* 1: if 'W' at least one character string		*/
	/* value was truncated when it was			*/
	/* stored into a host variable.				*/

	/*
	 * 2: if 'W' a (hopefully) non-fatal notice occurred
	 */	/* 3: empty */
	/* 4: empty						*/
	/* 5: empty						*/
	/* 6: empty						*/
	/* 7: empty						*/

	char		sqlstate[5];
};

struct sqlca_t *ECPGget_sqlca(void);

#ifndef POSTGRES_ECPG_INTERNAL
#define sqlca (*ECPGget_sqlca())
#endif

#ifdef __cplusplus
}
#endif

#endif

#line 2 "main.pgc"

/* exec sql whenever sql_warning  sqlprint ; */
#line 3 "main.pgc"

int main(int argc, char* argv[])
{
	{ ECPGconnect(__LINE__, 0, "i9fabryk@fourier:5432" , "i9fabryk" , "Marcin" , "coon", 0); 
#line 6 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();}
#line 6 "main.pgc"

	{ ECPGtrans(__LINE__, NULL, "begin");
#line 7 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();}
#line 7 "main.pgc"

	/* exec sql begin declare section */
    	 
		 
		  
		 
	
#line 9 "main.pgc"
 int count ;
 
#line 10 "main.pgc"
 int id ;
 
#line 11 "main.pgc"
 char tmp [ 255 ] [ 30 ] [ 8 ] ;
 
#line 12 "main.pgc"
 char stmp1 [ 255 ] ;
/* exec sql end declare section */
#line 13 "main.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select empno from emp", ECPGt_EOIT, ECPGt_EORT);
#line 14 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();}
#line 14 "main.pgc"

	int x=sqlca.sqlerrd[2];
	printf("Wierszy: %d\n\n\n",x);
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select * from emp limit 1", ECPGt_EOIT, 
	ECPGt_char,(tmp[0]),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(tmp[1]),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(tmp[2]),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(tmp[3]),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(tmp[4]),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(tmp[5]),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(tmp[6]),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(tmp[7]),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 17 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();}
#line 17 "main.pgc"

//	printf("%d\n",slqca.sqlerrd[2]);

	int j=0;
	int i=0;
	for(j=0;j<8;j++)
	{
		printf("%s ",tmp[j]);
	};
	printf("\n\n\n");
//	EXEC SQL FETCH INTO :id;




	{
		int tmp=argc-1;
		int i;
		int first=-1;
		int last=-1;
		/* exec sql begin declare section */
		 
			  

		
#line 38 "main.pgc"
 char * desc = 0 ;
 
#line 39 "main.pgc"
 char tmp2 [ 255 ] [ 30 ] [ 8 ] ;
/* exec sql end declare section */
#line 41 "main.pgc"

		for(i=1;i<argc;i+=2)
		{
//			printf("przetwarzam: %s\n",argv[i]);
			if(!strcmp(argv[i],"n"))
				first=atoi(argv[i+1]);
			if(!strcmp(argv[i],"m"))
				last=atoi(argv[i+1]);
			if(!strcmp(argv[i],"d"))
				desc=argv[i+1];
		};
		printf("%d %d %s\n",first,last,desc);

		strcpy(stmp1,"select * from emp");
		if(desc)
			strcat(stmp1," where job=?");
		{ ECPGprepare(__LINE__, NULL, 0, "mystmp1", stmp1);
#line 57 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();}
#line 57 "main.pgc"

		
		/* declare mycursor cursor for $1 */
#line 59 "main.pgc"


		if(desc)
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "mystmp1", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(desc),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 62 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();}
#line 62 "main.pgc"

		else
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "mystmp1", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 64 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();}
#line 64 "main.pgc"


		while(sqlca.sqlcode==0)
		{
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor", ECPGt_EOIT, 
	ECPGt_char,(tmp2[0]),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(tmp2[1]),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(tmp2[2]),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(tmp2[3]),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(tmp2[4]),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(tmp2[5]),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(tmp2[6]),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(tmp2[7]),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 68 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();}
#line 68 "main.pgc"

			if(sqlca.sqlcode==0)
			{
				int i;
				for(i=0;i<8;i++)
				{
					printf("%s ",tmp2[i]);
				};
				printf("\n");
			};
		};
			
		
	};

	{ ECPGtrans(__LINE__, NULL, "commit");
#line 83 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();}
#line 83 "main.pgc"

	{ ECPGdisconnect(__LINE__, "ALL");
#line 84 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();}
#line 84 "main.pgc"

	printf("%d\n",count);
};
