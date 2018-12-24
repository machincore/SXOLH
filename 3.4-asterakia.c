#include<stdio.h>
#include<math.h>

int main()
{
	int gram,s;
	int l, k;

	printf("eisagogh arithmou grammwn: ");
	scanf("%d", &gram);
	printf("\n");

	for (l = 1; l <= gram; l++)
	{
		for (k = 1; k <= l; k++)
			printf("*");
		printf("\n");
	}
	printf("\n");
	
	for (l = 1; l <= gram; l++)
	{
		for(k = 1; k >= l-gram; k--)
			printf(" ");
				for(k =1; k<=l; k++)
					printf("*");
		printf("\n");
	}
	printf("\n");
	
	for (l=1;l<=gram; l++)
	{
		for (k=1; k>=l-gram; k--)
			printf(" ");
				for (k=1; k<= l*2-1; k++)
					printf("*");
		printf("\n");
	}
	printf("\n");
	
 for(l=1;l<=gram;l++)
    {
        
        for(k=1;k<=gram;k++)
        {
            if(l==1 || l==gram || k==1 || k==gram)
            {
               printf("*");
            }
            else
            {
                if(l % 2 == 0)
                {
						if(k % 2 == 0)
						{
							printf(".");
						}
						else
						{
							printf(" ");
						}
            	}
            	else
            	{
            		if (k % 2 == 0)
            		{
            			printf(" ");
					}
					else
					{
						printf(".");
					}
				}
            }
        }

       
        printf("\n");
    }
	
	return 0;
}
