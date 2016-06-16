#include <stdio.h>

int main()
{

	int x1[] = { 0,0,1,1}; 
	int x2[] = { 0,1,0,1};
	int t[] = {0,1,1,1};
 	float w = -1.1 , dw = -1 , eta = 0.1;
	int  th = 1;
	float o[4] , v;
	int  i;
	for(i=0; i<4 ; i++)
		o[i] = 0;
	printf("A\tB\toutput\n");
	for(i=0 ; i<4 ; i++)
	{
		v = x1[i]*w + x2[i]*w;
		dw = eta*(t[i] - o[i]);
		while(dw != 0)
		{ 
			if(v >= th )
				o[i] = 1;
			else 
				o[i] = 0;
		        v = x1[i]*w + x2[i]*w;
                	dw = eta*(t[i] - o[i]);
			w = w + dw;
		}
	}
	for(i=0 ; i<4 ; i++)
        {
		        if(o[i] >= th)
                                 printf("%d\t%d\t1\n" , x1[i] , x2[i] );
                        else
                                 printf("%d\t%d\t0\n" , x1[i] , x2[i] );
	}
	printf("Weight = %.2f\n" , w);
		
}		
		 
