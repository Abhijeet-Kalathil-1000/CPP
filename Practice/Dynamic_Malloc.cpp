/* 
   THE FOLLOWING PROGRAM WILL ILLUSTRATES :
	   THE DEMO OF dynamic memory allocation using 'malloc'/ 'calloc'/ 'realloc'...
*/

#include<stdio.h>
#include<malloc.h>

// signatures of the user-defined function...

void OneDimentional();
void TwoDimentional();
void ThreeDimentional();

int main()
{
	int choice;
	int i,sizeX = 4,sizeY = 5;

	printf("Enter your choice:\n");
	printf("1: One Dimentional\n2: Two Dimentional\n3: Three Dimentional\n");
	scanf("%d",&choice);
	// choice is accepted from the user...
	
	switch(choice)
	{
		case 1:
				OneDimentional();
			break;

		case 2:
				TwoDimentional();
			break;

		case 3:
				ThreeDimentional();
			break;

		default:
			printf("Not a valid choice");
	}
	return 0;
}

void OneDimentional()
{
	int *p;		// int pointer is declared...
	int col, i;

	printf("Enter number of elemets\n");
	scanf("%d", &col);

	p = (int *)malloc(sizeof(int) * col);
	// whatever number user will enter that many bytes * sizeof(int) memory allocated...
	// 'p' points to 'col' number of integers memory...
	// 'p' contains address of that allocated memory...

	// accepting the elements from user...
	printf("Enter the elements\n");

	for(i = 0 ; i < col ; i++)
	{
		// loop will iterate 'col' number of times...
		scanf("%d", &p[i]);
	}

	// printing of accepted elements...
	printf("Elemets in 1D array are\n");
	for(i = 0 ; i < col ; i++)
	{
		printf(" %d ", p[i]);
	}

	printf("\nFreeing the allocated memory for the 1D array\n");
	free(p);
	// responsibility of programmer to free that allocated memory while returning back to caller...
}

void TwoDimentional()
{
	int **p = NULL;
	int col,row,i,j;

	// accepting values for 'row' and 'col' from the user...
	printf("Enter number of rows\n");
	scanf("%d" , &row);

	printf("Enter number of columns\n");
	scanf("%d" , &col);

	// TwoDimentional array means 'row' number of 1-D arrays containing 'col' number of elements...

	p = (int**)malloc(sizeof(int) * row);
	// memory for 'row' number of 1-D array is allocated on heap...

	for(i = 0 ; i < row ; i++)
	{
		// memory allocated for 'col' elements for 'row' number of times...
		p[i] = (int *)malloc(sizeof(int) * col);
		// 'p' is pointing to memory of 'row*col' number of elements...
	}

	// accpeting elements from the user...
	printf("Enter elemets in the array\n");
	for(i = 0 ; i < row ; i++)
	{
		for(j = 0 ; j < col ; j++)
		{
			scanf("%d" , &p[i][j]);
		}
	}

	// printing of accepted elements...
	printf("Elemets in 2D array are\n");
	for(i = 0;i < row ; i++)
	{
		printf("\n");
		for(j = 0 ; j < col ; j++)
		{
			printf(" %d " , p[i][j]);
		}
	}

	printf("\nFree the allocated memory for the 1D array\n");
	for(i = 0 ; i < row ; i++)
	{
	// 	for deleting allocated 2-D memory need to iterate 'row' number of times...
		free(p[i]);		
	}
	free(p);	// as 'p' is a pointer to pointer so freeing the memory of 'p'...
}

void ThreeDimentional()
{
	//	dynamic memory allocation for 3-D array...
	//	Three Dimensional array is : 
	//		'first' number of 
	int ***p;
	int first, second, third, i, j, k;

	printf("Enter first dimention\n");
	scanf("%d", &first);

	printf("Enter second dimention\n");
	scanf("%d", &second);

	printf("Enter third dimention\n");
	scanf("%d", &third);


	p = (int ***)malloc(sizeof(int**) * first);
	for(i = 0 ; i < first ; i++)
	{
		p[i] = (int **)malloc(sizeof(int*) * second);

		for( j = 0; j < second ; j++)
		{
			p[i][j] = (int *)malloc(sizeof(int) * third);
		}
	}

	printf("Enter the elements\n ");
	for(i = 0 ; i < first ; i++)
	{
		for(j =0 ; j < second ; j++)
		{
			for(k = 0 ; k < third ; k++)
			{
				scanf("%d" , &p[i][j][k]);
			}
		}
	}

	printf("Enter the elements\n ");
	for(i = 0 ; i < first ; i++)
	{
		for(j = 0 ; j < second ; j++)
		{
			printf("\n");
			for(k = 0 ; k < third ; k++)
			{
				printf(" %d " , p[i][j][k]);
			}
		}
	}

	printf("\nFree the memory of array\n");

	for(i = 0 ; i < first ; i++)
	{
		for(j = 0 ; j < second ; j++)
		{
			free(p[i][j]);
		}
		free(p[i]);
	}
	free(p);
}
