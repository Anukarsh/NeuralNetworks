#include <stdio.h>

int main()
{
	int x1[] = { 0,0,1,1};
        int x2[] = { 0,1,0,1};
	int o[] = {0,0,0,0} ;
	float w1 = 1.0;
	float eta = 0.1;
	int i , j;
	float dw1 = 0.0;
	float t[] = { 0,1,1,0};
	for(i=0 ; i<=1; i++)
	{
		w1 = 0.0;
		for(j = 0 ; j<4 ; j++)
		{	
			o[j] = x1[j]*w1 + x2[j]*w1;
			dw1 = eta*(t[j]-o[j]);
			while(dw1!=0)
			{
				o[j] = x1[j]*w1 + x2[j]*w1;
	                        dw1 = eta*(t[j]-o[j]);
				w1 = w1 + dw1;
			}
		
		}
	}
	printf("A\tB\toutput\n");
	for(i=0 ; i<4 ; i++)
        {
		    
                                 printf("%d\t%d\t%d\n" , x1[i] , x2[i] , o[i] ); 
	}
	printf("Weight = %.2f\n" , w1);
}

