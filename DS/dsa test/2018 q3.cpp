#include<stdio.h>
#include<stdlib.h>
#define max 10 //just any number

void add(int sparseM[max][3])
{
	if (sparseM[0][0] != sparseM[0][1])
	{
		printf("Not a square sparse matrix, hence transpose is not possible");
		return;
	
	}
	
		int transSparseMatrix[max][3]; //declaring a new sparse matrix transpose

//populating 0th row of the transpose sparse matrix
		transSparseMatrix[0][0] = sparseM[0][1];
		transSparseMatrix[0][1] = sparseM[0][0];
		transSparseMatrix[0][2] = sparseM[0][2];
		
		int b1[100][100];
		int k =1;
		int n = transSparseMatrix[0][2]; //counting the total number of non-zero elements
		//sparse matrix formation
	for (int i=0;i< sparseM [0][1];++i) //traversing through the number of columns
	{
		for (int j=1;j<=n;j++)
		{
			if(i== b1[j][1])
			{
				transSparseMatrix[k][0]=i;
				transSparseMatrix[k][1]= sparseM[j][0];
				transSparseMatrix[k][2]= sparseM[j][2];
				k++;
			}
		}
	}
		//sparse matrix addition
		int r,c,i,j,k1,k2,k3,tot1,tot2;
		tot1 = sparseM[0][2];
		tot2 = transSparseMatrix[0][2];
		k1 = k2 = k3 = 1;
		int addSparseMatrix[max][3];
		while ( k1 <= tot1 && k2 <= tot2)
		{
			if ( sparseM[k1][0] < transSparseMatrix[k2][0] )
			{
				addSparseMatrix[k3][0] = sparseM[k1][0];
				addSparseMatrix[k3][1] = sparseM[k1][1];
				addSparseMatrix[k3][2] = sparseM[k1][2];
				k3++;
				k1++;
			}
			else if ( sparseM[k1][0] > transSparseMatrix[k2][0] )
			{
				addSparseMatrix[k3][0] = transSparseMatrix[k2][0];
				addSparseMatrix[k3][1] = transSparseMatrix[k2][1];
				addSparseMatrix[k3][2] = transSparseMatrix[k2][2];
				k3++;
				k2++;
			}
			else if ( sparseM[k1][0] == transSparseMatrix[k2][0])
			{
				if ( sparseM[k1][1] < transSparseMatrix[k2][1] )
				{
					addSparseMatrix[k3][0] = sparseM[k1][0];
					addSparseMatrix[k3][1] = sparseM[k1][1];
					addSparseMatrix[k3][2] = sparseM[k1][2];
					k3++;
					k1++;
				}
			else if ( sparseM[k1][1] > transSparseMatrix[k2][1] )
			{
				addSparseMatrix[k3][0] = transSparseMatrix[k2][0];
				addSparseMatrix[k3][1] = transSparseMatrix[k2][1];
				addSparseMatrix[k3][2] = transSparseMatrix[k2][2];
				k3++;
				k2++;
			}
			else
			{
				addSparseMatrix[k3][0] = transSparseMatrix[k2][0];
				addSparseMatrix[k3][1] = transSparseMatrix[k2][1];
				addSparseMatrix[k3][2] = sparseM[k1][2] + transSparseMatrix[k2][2];
				k3++;	
				k2++;
				k1++;
			}
		} // else
	} // while
			while ( k1 <=tot1 )
			{
				addSparseMatrix[k3][0] = sparseM[k1][0];
				addSparseMatrix[k3][1] = sparseM[k1][1];
				addSparseMatrix[k3][2] = sparseM[k1][2];
				k3++;
				k1++;
			} //while
			while ( k2 <= tot2 )
			{
				addSparseMatrix[k3][0] = transSparseMatrix[k2][0];
				addSparseMatrix[k3][1] = transSparseMatrix[k2][1];
				addSparseMatrix[k3][2] = transSparseMatrix[k2][2];
				k3++;
				k2++;
			} // while
				addSparseMatrix[0][0] = sparseM[0][0];
				addSparseMatrix[0][1] = sparseM[0][1];
				addSparseMatrix[0][2] = k3-1;
}
