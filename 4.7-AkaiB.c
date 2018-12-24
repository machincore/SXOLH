#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* to vasiko interface twn diathesimwn epilogwn pou exei o xrhsths */
void menu(int a,int b)
	{
		printf("leitourgies:\n1*Ypologismos ths dunamhs %d ^ %d?\n2*upologismos tou !%d kai tou !%d\n3*upologimos tou plhthous twn sunduasmwn %d ana %d\n4*an thes na vgeis grapse otidhpote allo:)\n",a,b,a,b,a,b);
		return ;
	}


void praksh_1(int a,int b);
void praksh_2(int a,int b);
void praksh_3(int a,int b);


/*STDIN twn vasikwn timwn a,b */
int choice(void)
	{
		int a,b;
		int num;
		scanf("%d",&num);
		printf("o ari8mos pou eishgages einai : %d\n",num);
		return num;
	}


void choice_picker(int a,int b,int *ans)
	{
		*ans = choice(); /* exei prostethei pointer ston ans wste na apo8ukeuftei h timh tou kai sto kurios programma ws deikths na bei ston pinaka me tis epiloges tou xrhsth */
		if (*ans == 1)
			praksh_1(a,b);
		else if (*ans == 2)
			praksh_2(a,b);
		else if (*ans == 3)
			praksh_3(a,b);
		printf("\n");
		return ;
	}


/* h praksh upologismou ths upsws se dunamh */
void praksh_1(int a,int b)
	{
		printf("%d^%d = %d",a,b,(int)pow(a,b));
		return ;
	}


void factorial(int n); /*arxikopoihsh tou algorithmou upologismou tou paragontikou pou analuete parakatw kai xrhsimopoieitai sthn sunarthsh praksh_2
/* h praksh upologismou tou paragontikou */
void praksh_2(int a,int b)
	{
		printf("!%d = ",a);
		factorial(a);
		printf("\n!%d = ",b);
		factorial(b);
		return;
	}


/* h praksh upologismou tou plhthous twn sunduasmwn a ana b */
void praksh_3(int a,int b)
	{
		unsigned long long int alg,fac_a = 1,fac_b = 1,fac_ab = 1;
		int i;
		if (a>=b)
			{
				for(i=1;i<=a;i++)
					fac_a *= i;
				for(i=1;i<=b;i++)
					fac_b *= i;
				for(i=1;i<=(a-b);i++)
					fac_ab *= i;
				alg = fac_a/(fac_b*(fac_ab));
				printf("to plhthos sunduasmwn %d ana %d einai : %ld",a,b,alg);
			}
		else
			printf("adunato kathws den uparxei arnhtiko paragontiko enos arithmou");
		return ;
	}

/* function emfanishs tou sunolou twn epilogwn pou exei kanei o xrhsths akrivos prin kanei exit to programma */
void synol_epilogwn(int arr[],int size)
	{
		int i;
		int choice_1 = 0,choice_2 = 0,choice_3 =0;
		for(i=0;i<size;i++)
			{
				if (arr[i] == 1)
					choice_1 += 1;
				else if(arr[i] == 2)
					choice_2 += 1;
				else if(arr[i] == 3)
					choice_3 += 1;
			}
		system("cls");
		printf("O xrhsths ekane tis ekseis epiloges toses fores\n1: %d\n2: %d\n3: %d",choice_1,choice_2,choice_3);
		return ;
	}

/* o algorithmos gia ton upologismo paragontikhs enos upervolika megalou arithmo(can reach up to 200 digits) */
/*------------------------------------------*/
void factorial(int n)
{
    int a[200],counter,temp,i;
    a[0]=1;
    counter=0;
    for(; n>=2; n--)
    {
        temp=0;
        for(i=0; i<=counter; i++)
        {
            temp=(a[i]*n)+temp;
            a[i]=temp%10;
            temp=temp/10;
        }
        while(temp>0)
        {
            a[++counter]=temp%10;
            temp=temp/10;
        }
    }
    for(i=counter; i>=0; i--)
        printf("%d",a[i]);
    return ;
}
/*------------------------------------------*/

int main() {
	int a,b,ans;
	char ex;
	int choices[50],counter = 0;
	while(1)
		{
		printf("Grapse ton A: ");
		scanf("%d",&a);
		printf("Grapse ton B: ");
		scanf("%d",&b);
		menu(a,b);
		choice_picker(a,b,&ans);
		choices[counter] = ans;
		counter += 1;
		printf("thes na vgeis?an nai pata y alliws pata N(h otidhpote allo)");
		scanf(" %c",&ex);
		if (ex == 'y')
			break;
		}
	synol_epilogwn(choices,counter);
    return 0;
	}
