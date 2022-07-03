#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;


void OneDimentional();
void TwoDimentional();
void ThreeDimentional();

int main()
{
	int choice;

	cout<<"Enter your choice:\n";
	cout<<"1: One Dimentional\n2: Two Dimentional\n3: Three Dimentional\n";
	cin>>choice;
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
		cout<<"Not a valid choice";
	}
return 0;
}

void OneDimentional()
{
int *p;
int col , i;

cout<<"Enter number of elemets\n";
cin>>col;

p = new int[col];

cout<<"Enter the elements\n";

for(i = 0 ; i < col ; i++)
{
	cin>>p[i];
}

cout<<"Elemets in 1D array are\n";
for(i = 0 ; i < col ; i++)
{
	cout<<" %d " , p[i];
}

cout<<"\nFree the allocated memory for the 1D array\n";
delete p ;

}

void TwoDimentional()
{
int **p = NULL;
int col,row,i,j;

cout<<"Enter number of rows\n";
cin>>row;

cout<<"Enter number of columns\n";
cin>>col;

p = new int*[row];
for(i = 0 ; i < row ; i++)
{
p[i] = new int[col];
}
cout<<"Enter elemets in the array\n";

for(i = 0 ; i < row ; i++)
{
for(j = 0 ; j < col ; j++)
{
cin>>p[i][j];
}
}

cout<<"Elemets in 2D array are\n";
for(i = 0;i < row ; i++)
{
cout<<"\n";
for(j = 0 ; j < col ; j++)
{
cout<<p[i][j];
}
}

cout<<"\nFree the allocated memory for the 1D array\n";
for(i = 0 ; i < row ; i++)
{
delete [] p[i];
}

delete []p;
}

void ThreeDimentional()
{
int ***p;
int first , second , third , i , j , k;

cout<<"Enter first dimention\n";
cin>>first;

cout<<"Enter second dimention\n";
cin>>second;

cout<<"Enter third dimention\n";
cin>>third;


p=new int**[first];
for(i = 0 ; i < first ; i++)
{
	p[i] = new int*[second];

	for( j = 0; j < second ; j++)
	{
		p[i][j] = new int[third];
	}
}

cout<<"Enter the elements\n ";
for(i = 0 ; i < first ; i++)
{
	for(j =0 ; j < second ; j++)
	{
		for(k = 0 ; k < third ; k++)
		{
			cin>>p[i][j][k];
		}
	}
}

cout<<"Elements are\n ";
for(i = 0 ; i < first ; i++)
{
	for(j = 0 ; j < second ; j++)
	{
		cout<<"\n";
		for(k = 0 ; k < third ; k++)
		{
			cout<<p[i][j][k];
		}
	}
}

cout<<"\nFree the memory of array\n";

for(i = 0 ; i < first ; i++)
{
	for(j = 0 ; j < second ; j++)
	{
		delete [] p[i][j];
	}
	delete [] p[i];
}

delete []p;

}