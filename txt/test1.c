#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

double sigmoid(double x)
{
	return 1.0/(1.0 + exp(-x));
}

double dd(double x)
{
	return x*(1-x);
}
int main()
{
	time_t tt;
	srand((unsigned) time(&tt));
	int x[624][30][32];
//	double t[] = { 0.9,0.1,0.1,0.1};
	double hinput[3][961];
	double hweights[3][961];
	double herr[3];
//	double h1bias = .01;
	int rate = 0.3;
	double outinput[4][3];
        double outweights[4][3];
        double outerr;
	float outout[961];
	int i , j , k , m , m1 , m2 , ind;
	char name[100];
	char *token;
	int n = 100;			
        FILE *file , *f;
	float a = 0.0 , b = 0.0 , c = 0.0 , d = 0.0;
	int t[4][4] = { {0.9,0.1,0.1,0.1} , {0.1,0.9,0.1,0.1} ,  {0.1,0.1,0.9,0.1} , {0.1,0.1,0.1,0.9}};
	
	for( i = 0 ; i <961 ; i++)
	{
		hweights[0][i] = ((float) rand()/(float)(RAND_MAX)*1);
		hweights[1][i] = ((float) rand()/(float)(RAND_MAX)*1);
		hweights[2][i] = ((float) rand()/(float)(RAND_MAX)*1);


	}
	for( i = 0 ; i <3 ; i++)
        {
                outweights[0][i] = ((float) rand()/(float)(RAND_MAX)*1);
		outweights[1][i] = ((float) rand()/(float)(RAND_MAX)*1);
		outweights[2][i] = ((float) rand()/(float)(RAND_MAX)*1);
		outweights[3][i] = ((float) rand()/(float)(RAND_MAX)*1);
        }

	
	file = fopen("all.list", "r");
	for(k = 0 ; k<624 ; k++)
	{
		 if(fgets(name, n, file))
		 {
			 // printf("%s" , name);
			token =	  strtok(name,"\n");
			//  printf("%s" , token);
		          if( f = fopen(name,"r"))
		       	{
			  for(i = 0; i < 30; i++)
 		 	 {
     				 for(j = 0; j < 32; j++) 
     				 {
      					 if (!fscanf(f, "%d", &x[k][i][j])) 
        				   break;
    					 
//     					  printf("%d\t",x[k][i][j]);
      				 }
//				printf("\n");
  			 }
	  		fclose(f); 
		
			}
		}
	}
	fclose(file);
//	printf("\n%d\n",count);

	for(j = 0 ; j <15 ; j++)
	{
		for(k = 0 , m = 0 , m1 = 0 , m2 = 0; k<624 ; k++)
		{ 
			for(i = 0; i<30 ;i++)
			{ 
				for(j = 0 ; j < 32; j++)
				{
				hinput[1][m++] = x[k][i][j++];
				hinput[2][m1++] = x[k][i][j++];
				hinput[3][m2++] = x[k][i][j++];
				}
			}
			a = 0.0;
			b = 0.0;
			c = 0.0;
			d = 0.0;
			for( i = 0 ; i<961 ; i++)
			{

				a = a + (hweights[1][i]*hinput[1][i]);
				b = b + (hweights[2][i]*hinput[2][i]);
                                c = c + (hweights[3][i]*hinput[3][i]);
			}
			a = sigmoid(a);
		        b = sigmoid(b);
		        c = sigmoid(c);
			d = (a+b+c)/3.0;
			if(d <= 0.2)
			{	
				ind = 0;
				outinput[0][0] = a;
				outinput[0][1] = b;
				outinput[0][2] = c;
			}
			else if(d<=0.4)
			{
				ind = 1;
				outinput[1][0] = a;
                                outinput[1][1] = b;
                                outinput[1][2] = c;
			}
			 else if(d<=0.6)
                        {
				ind = 2;
                                outinput[2][0] = a;
                                outinput[2][1] = b;
                                outinput[2][2] = c;
                        }
			else if(d>0.6)
                        {
				ind = 3;
                                outinput[3][0] = a;
                                outinput[3][1] = b;
                                outinput[3][2] = c;
                        }
			float f;
			f =  sigmoid((outweights[ind][0]*outinput[ind][0] + outweights[ind][1]*outinput[ind][1]+outweights[ind][2]*outinput[ind][2]));
//				printf("%f\t%f\t%f" , x[i][0] , x[i][1] , f);

			outerr = (dd(f)*(0.9 -f));
		       	outweights[ind][0] += outerr * outinput[ind][0];
                	outweights[ind][1] += outerr * outinput[ind][1];
		        outweights[ind][2] += outerr * outinput[ind][2];

	
			herr[0] = dd(outinput[ind][0])*outerr*outweights[ind][0];
			herr[1] = dd(outinput[ind][1])*outerr*outweights[ind][1];
			herr[2] = dd(outinput[ind][2])*outerr*outweights[ind][2];

			for(i = 0 ; i <961 ; i++)
			{
                        	hweights[0][i] += herr[0] * hinput[0][i];
				hweights[1][i] += herr[1] * hinput[1][i];
			        hweights[2][i] += herr[2] * hinput[2][i];
			}
			outout[i] = f;
		}
	}
	for(i = 0 ; i<961 ; i++)
	{
		printf("%f\n" , outout[i]);
	}
}
