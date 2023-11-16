#include "sshell.h"

/**
* tokenize - parse user input into arguments
* by splitting a string into tokens using a specified delimiter.
* @inputString: the string to be tokenized.
* @delimiter: the delimiter used to split the string.
*
* Return: an array of pointers to the tokens,
*         or NULL if an error occurs.
*/
char **tokenize(char *inputString, const char *delimiter)
{
	char *currentToken = NULL;
	char **resultArray = NULL;
	int tokenIndex = 0;

	currentToken = strtok(inputString, delimiter);
	while (currentToken)
	{
		resultArray = realloc(resultArray, sizeof(char *) * (tokenIndex + 1));
		if (resultArray == NULL)
			return (NULL);

		resultArray[tokenIndex] = malloc(_strlen(currentToken) + 1);
		if (!(resultArray[tokenIndex]))
			return (NULL);

		_strcpy(resultArray[tokenIndex], currentToken);
		currentToken = strtok(NULL, delimiter);
		tokenIndex++;
	}

	resultArray = realloc(resultArray, (tokenIndex + 1) * sizeof(char *));
	if (!resultArray)
		return (NULL);

	resultArray[tokenIndex] = NULL;
	return (resultArray);
}

/**
* tokenize_input - custom implementation to tokenize user input.
* @user_input: the user input string to be tokenized.
*
* Return: an array of pointers to the tokens, or NULL if an error occurs.
*/
char **tokenize_input(char *user_input)
{
	char **tokens = NULL;

	char *input_copy = NULL;

	input_copy = _strdup(user_input);
	if (input_copy == NULL)
	{
		ss_print("error in memory allocation");
		exit(EXIT_FAILURE);
	}
	tokens = tokenize(input_copy, " \t\r\n\a");
	free(input_copy);

	return (tokens);

}
