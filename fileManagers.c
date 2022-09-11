#include "main.h"

FILE *openFile(int argc, char **argv)
{
	FILE *fptr;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <File name>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fptr = fopen(argv[1], "r");

	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Could not open file.\n");
		exit(EXIT_FAILURE);
	}

	return (fptr);
}
