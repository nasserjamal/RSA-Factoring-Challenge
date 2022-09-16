#include "main.h"

void process64bitLine(char *line){
    int i = 0;
	int len = strlen(line);
    int arrSize = len / 9;
    int lastSize = 0;
    char tempStr[20];
    uint64_t numbers[arrSize];
    int primeNo = 2;

    for (i = 0; i < arrSize; i++)
    {
        if(i == arrSize - 1){
            numbers[i] = atol(strcpy(tempStr, &line[i * 9]));
            lastSize = strlen(tempStr);
            //printf("Last size id %d", lastSize);
        }else{
            numbers[i] = atol(strncpy(tempStr, &line[i * 9], 9));
        }
    }

    while (arrMod(numbers, primeNo, arrSize) != 0)
	{
		/*TODO: limit primeno <= sqrt(num)*/
		//primeNo = getNextPrime(primeNo);
        primeNo++;
	}
    fprintf(stdout, "%s=%s*%d\n", arrStr(numbers, arrSize, len), arrDiv(numbers, primeNo, arrSize, len), primeNo);
}

uint64_t arrMod(uint64_t *numbers, int mod, int arrSize)
{
    int i = 0;
    uint64_t carry = 0;
    for (i = 0; i < arrSize; i++)
    {
        //printf("Carry: %ld new no: %ld before: %ld\n", carry, addCarry(numbers[i], carry), numbers[i]);
        carry = addCarry(numbers[i], carry) % mod;
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
char *arrDiv(uint64_t *numbers, uint64_t div, int arrSize, int len)
{
    char *ans = malloc(sizeof(char) * len);
    char temp[20];
    int i = 0;
    uint64_t carry = 0;
    strcpy(ans, "");
    for (i = 0; i < arrSize; i++)
    {
        sprintf(temp, "%ld", numbers[i] / div);
        strcat(ans, temp);
        carry = addCarry(numbers[i], carry) % div;
    }
    return ans;
}
uint64_t addCarry(uint64_t num, uint64_t carry)
{
    uint64_t n = num;
    int count = 0;
    if(carry == 0)
        return num;
    
    do {
    n /= 10;
    ++count;
    } while (n != 0);

    return ((carry * pow((double)10, (double)count)) + num);
}
