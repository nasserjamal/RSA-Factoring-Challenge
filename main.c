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
	uint64_t num;
	int primeNo = 2;

	if(strlen(line) > 19){
		process64bitLine(line);
		return;
	}

	num = atol(line);

	if (num == 0)
	{
		fprintf(stdout, "0=0*0\n");
		return;
	}

	while ((num % primeNo) != 0)
	{
		/*TODO: limit primeno <= sqrt(num)*/
		//primeNo = getNextPrime(primeNo);
		primeNo++;
	}
	fprintf(stdout, "%ld=%ld*%d\n", num, (num / primeNo), primeNo);
}



int getNextPrime(int prevPrime)
{
	int currentNum = prevPrime + 1;
	/*TODO: Limit range of current num*/
	while (1)
	{
		if (isPrime(currentNum))
			return currentNum;
		currentNum++;
	}
	
}

bool isPrime(int num)
{
	if((num - 1) % 6 != 0){
		if(num != 2 && num != 3 && num != 5)
			return false;
	}
	return (true);
	
}

char *removeWhiteSpaces(char *str)
{
	int i, len = 0,j;  
      
    len = strlen(str);  
      
    for(i = 0; i < len; i++){  
        if(str[i] == ' '){  
            for(j=i;j<len;j++)  
        {  
            str[j]=str[j+1];  
        }  
        len--;  
        }  
    }  
	return (str);
}
