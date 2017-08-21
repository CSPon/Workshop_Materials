/*
*	Electronics Workshop
 *	Works_003.c
*	Intro to C Programming (4)
 *	Functions
*/

/*
*	This shows how to declare and define functions in C.
 *	Functions in C consists of [return type] [function name] (parameters){}
*	Return type can be any data type, including pointer type.
 *	Parameters also, can have pointer type data.
*	C89 standard can have declaration first then definition. Having declaration first allows
 *	function definitions to be after main function.
*/

#include <stdio.h>

/* If function declaration is stated before, Function definition can be after main fuction. */
void a();
int addTwo(int a, int b);
int* addTwoPointer(int a, int b);
int addTwoFromPtr(int *a, int *b);
void multiplySame(int *a, int *b);

/* Otherwise you have to declare and define function before main function */
void b(int num)
{
	printf("Called from function b: %d\n", num);
}

int main(void)
{
	int numa = 10;
	int numb = 20;
	int sum;
	int *ptra, *ptrb;

	/* To call a function, simply call it by defining function name and parameters. */
	a();
	b(numa);

	sum = addTwo(numa, numb);
	printf("Returned value from function addTwo: %d\n", sum);

	numa = 30;
	numb = 20;
	ptra = addTwoPointer(numa, numb);
	printf("Returned value from function addTwoPointer: %d\n", *ptra);

	numa = 60;
	numb = 50;
	sum = addTwoFromPtr(&numa, &numb);
	printf("Returned value from function addTwoFromPtr: %d\n", sum);

	/*
	*	Benefits for passing pointers to function, you can manipulate value pointed by pointer!
	 *	Think about function requiting returning two values at same time; such as coordinates
	*/
	multiplySame(&numa, &numb);

	printf("Two values after multiplySame: %d %d\n", numa, numb);

	getchar();
	return 0;
}

void a()
{
	printf("Called from function a\n");
}

int addTwo(int a, int b)
{
	return a + b;
}

int* addTwoPointer(int a, int b)
{
	int sum = a + b;
	return &sum;
}

int addTwoFromPtr(int *a, int *b)
{
	int sum = (*a) + (*b);
	return sum;
}

void multiplySame(int *a, int *b)
{
	*a *= 2;
	*b *= 2;
}
