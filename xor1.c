#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double sigmoid(double x)
{
	return 1.0/(1.0 + exp(-x));
}

double d(double x)
{
	return x*(1-x);
}
int main()
{
	time_t tt;
	srand((unsigned) time(&tt));
	double x[][2] = { {0,0} , {0,1} , {1,0} , {1,1}};
	double t[] = { 0,1,1,0};
	double h1input[2];
	double h1weights[] = { 1, 1} ;
	double h1err;
	double h1bias = .01;
	double h2input[2];
        double h2weights[2] = {1,1};
        double h2err;
	double h2bias = .01;
	double outinput[2];
        double outweights[2] = {-1,1};
        double outerr;
	double outbias = .01;
	double outout[] = {0,0,0,0};
	int i , j;
	
	for(j = 0 ; j <400 ; j++)
	{
		for(i =0; i<4 ; i++)
		{
			double f;

			h1input[0] = x[i][0];
			h1input[1] = x[i][1];
			h2input[0] = x[i][0];
			h2input[1] = x[i][1];
			
			outinput[0] = sigmoid(h1weights[0]*h1input[0] + h1weights[1]*h1input[1]+h1bias);
			outinput[1] = sigmoid(h2weights[0]*h2input[0] + h2weights[1]*h2input[1]+h2bias);
			
			f =  sigmoid(outweights[0]*outinput[0] + outweights[1]*outinput[1]+outbias);			
//			printf("%f\t%f\t%f" , x[i][0] , x[i][1] , f);

			outerr = d(f)*(t[i] -f);
		        outweights[0] += outerr * outinput[0];
                	outweights[1] += outerr * outinput[1];
                	outbias += outerr;
	
			h1err = d(outinput[0])*outerr*outweights[0];
			h2err = d(outinput[1])*outerr*outweights[1];

                        h1weights[0] += h1err * h1input[0];
                        h1weights[1] += h1err * h1input[1];
                        h1bias += h1err;

			h2weights[0] += h2err * h2input[0];
                        h2weights[1] += h2err * h2input[1];
                        h2bias += h2err;
			
			outout[i] = f;
		}
	}
	printf("\n\n\n\n\nA\tB\tOutput\n");
	for(i = 0 ; i<4 ; i++)
	{
		printf("%f\t%f\t%f\n" , x[i][0] , x[i][1] , outout[i]);
	}
}



 
   

