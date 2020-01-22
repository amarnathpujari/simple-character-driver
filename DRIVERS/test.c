#include<stdio.h>
int fact(int);
int main()
{
	int n,i;
	printf("enter a no. for getting it's factorial");

	scanf("\n\n%d", &n);

	printf("\n\n factorial of given no. is : %d ", fact(n));

}

int fact(int a)
{

	if(a==1)
	return 1;

	return (a * fact(a-1));
}
