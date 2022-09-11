#include "main.h"

int main(int argc, char **argv)
{
	/* Variable declaration */
	FILE *fptr;
	char *line = NULL;
	size_t lineSize;

	fptr = openFile(argc, argv);
	while (getline(&line, &lineSize, fptr) != -1)
	{
		processLine(line);
	}
	

	pclose(fptr);
	return (EXIT_SUCCESS);
}

void processLine(char *line)
{
	/* Variable declaration */
	int64_t num = atol(line);
	int primeNo = 2;

	if (num == 0)
	{
		fprintf(stdout, "0=0*0\n");
		return;
	}

	while ((num % primeNo) != 0 && primeNo <= num / 2)
	{
		primeNo = getNextPrime(primeNo);
	}
	fprintf(stdout, "%ld=%ld*%d\n", num, (num / primeNo), primeNo);
}

int getNextPrime(int prevPrime)
{
	int currentNum = prevPrime + 1;
	while (1)
	{
		if (isPrime(currentNum))
			return currentNum;
		currentNum++;
	}
	
}

bool isPrime(int num)
{
	int n = 2;
	
	if((num - 1) % 6 != 0){
		if(num != 2 && num != 3)
			return false;
	}

	for (n = 2; n <= num/2; n++)
	{
		if ((num % n) == 0)
			return (false);
	}
	return (true);
	
}
