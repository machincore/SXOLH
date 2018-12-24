#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loopx */
/* STDIN */
void inputs(double *a,double *b,double *c)
	{
		system("cls");
		printf("\n\n\nkalwsorises sto kompiouteraki upologismou eksiswshs 2ou vathmou :)");
		printf("\n<=========================================================================>");
		printf("\ngrapse ton prwto oro: ");
		scanf("%lf",a);
	    printf("grapse ton deutero oro: ");
		scanf("%lf",b);
		
		printf("grapse ton trito oro: ");
		scanf("%lf",c);
	}


int vathmos_checker(double *a)
	/* elegxei an einai prwtou h deuterou vathmou */
	{
		if (*a==0)
			return 1;
		else
			return 0;
	}

void prwtovathmia(double *b,double *c,double *x1)
	{
		if (*b==0)
		{
			if(*c==0)
				printf(" h eksiswsh einai aoristh tautothta ");
			else
				printf(" h eksiswsh einai adunath ");
		}
		else
		{
				*x1 = -*c/(*b);
				printf("x1: %lf",*x1);
		}
	}


/* oles oi sunarthseis sxetika me ton upologismo deuterovathmias 
	----------------------------------------------------------*/

void oxi_diakrinousa(double *a,double *b,double *c)
	{
		if (*a == 0 && *c == 0)
				printf("x = 0");
		else if(*c==0)
			{
				double temp = -*b/(*a);
				printf("x = %lf\nH'\nx = 0",temp); 
			}	
	}
	
void diakrinousa(double *a,double *b,double *c,double *d)
	{
		*d = pow(*b,2) -4*(*a)*(*c);
		printf("h diakrinousa einai: %lf",*d);
	}

void calc(double *a,double *b,double *d,double *x1,double *x2)
	{
		if (*d>0)
		{
			*x1 = (-*b+sqrt(*d))/2*(*a);
			*x2 = (-*b-sqrt(*d))/2*(*a);
			printf("\nsunepws h eksiswsh exei 2 rizes\noi rizes tis eksiswshs einai \n x1 = %f \n x2 = %f",*x1,*x2);
	 	}
	 	else if (*d == 0)
	 	{
	 		*x1 = -(*b)/(2*(*a));
	 		printf("\n \nsunepws,h eksiswsh exei monadikh riza thn x1 = %f",*x1);
		}
		else
		{
			printf("\nara h eksiswsh den exei pragmatikes rizes (adunath) :)");
		}
	}
/* ------------------------------ */
int retry(void)
	{
			char answer;
			printf("\n\n\ntha htheles na upologiseis kai allh eksiswsh? an nai pata (y) alliws tha ginei eksodos  ");
			scanf(" %c",&answer);
			if (answer != 'y')
				return 0;
			else
				return 1;
			
	}


int main(int argc, char *argv[]) {
	double x1,x2;
	double a,b,c,d;
	while(1) 
	{
		inputs(&a,&b,&c); /* eisodos timwn */
		if (vathmos_checker(&a) != 1) /* an einai deuterovathmia */
		{
			if (c == 0)
				oxi_diakrinousa(&a,&b,&c); /* se periptwsh pou to c einai 0 lunei thn deuterovathmia eksiswsh alla oxi me thn xrhsh diakrinousas(xrhsh koinou paragwnta) */
			else
			{
				diakrinousa(&a,&b,&c,&d);
				calc(&a,&b,&d,&x1,&x2);
			}
		}
		else
			prwtovathmia(&b,&c,&x1);
		/* checks if the users wants to calculate another equation */
		if (retry() !=1)
			break;
	}
	return 0;
}
