#include "main.h"

void process64bitLine(char *line){
    int i = 0;
	int len = strlen(line);
    int arrSize = len / 9;
    int lastSize;
    char tempStr[20];
    uint64_t numbers[arrSize];
    int primeNo = 2;

    for (i = 0; i < arrSize; i++)
    {
        if(i == arrSize - 1){
            numbers[i] = atol(strcpy(tempStr, &line[i * 9]));
            lastSize = strlen(tempStr) - 1;
        }else{
            numbers[i] = atol(strncpy(tempStr, &line[i * 9], 9));
        }
    }

    while (arrMod(numbers, primeNo, arrSize, lastSize) != 0)
	{
		/*TODO: limit primeno <= sqrt(num)*/
		primeNo = getNextPrime(primeNo);
	}
    fprintf(stdout, "%s=%s*%d\n", removeNewLine(line), arrDiv(numbers, primeNo, arrSize, len, lastSize), primeNo);
}

uint64_t arrMod(uint64_t *numbers, int mod, int arrSize, int lastSize)
{
    int i = 0;
    uint64_t carry = 0;
    for (i = 0; i < arrSize; i++)
    {
        //printf("Carry: %ld new no: %ld before: %ld\n", carry, addCarry(numbers[i], carry), numbers[i]);
        carry = addCarry(numbers[i], carry, (i == arrSize - 1)?lastSize:9) % mod;
    }
    return carry;
}
char *arrStr(uint64_t *numbers, int arrSize, int len)
{
    char *ans = malloc(sizeof(char) * len);
    char temp[20];
    int i = 0;
    strcpy(ans, "");
    for (i = 0; i < arrSize; i++)
    {
        sprintf(temp, "%ld", numbers[i]);
        strcat(ans, temp);
    }
    return ans;
}
char *arrDiv(uint64_t *numbers, uint64_t div, int arrSize, int len, int lastSize)
{
    char *ans = malloc(sizeof(char) * len);
    char temp[20];
    int i = 0;
    uint64_t carry = 0;
    strcpy(ans, "");
    for (i = 0; i < arrSize; i++)
    {
        // printf("Carry: %ld new no: %ld before: %ld\n", carry, addCarry(numbers[i], carry, (i == arrSize - 1)?lastSize:9), numbers[i]);
        sprintf(temp, "%ld", addCarry(numbers[i], carry, (i == arrSize - 1)?lastSize:9) / div);
        strcat(ans, temp);
        carry = addCarry(numbers[i], carry, (i == arrSize - 1)?lastSize:9) % div;
    }
    return ans;
}
uint64_t addCarry(uint64_t num, uint64_t carry,int digits)
{
    return ((carry * pow(10, digits)) + num);
}

char *removeNewLine(char *line)
{
    char *temp = line;
    while (*temp)
    {
        if (*temp == '\n')
        {
            *temp = '\0';
        }
        temp++;
    }
    return line;
}
