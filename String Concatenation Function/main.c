#include <stdio.h>
#include <stdlib.h>

int my_strlen(const char* str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

char* concat(const char* str1, const char* str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);

    char* result = malloc(len1 + len2 + 2);  
    if (!result) {
        printf("Nie ma pamieci\n");
        return NULL;
    }

    for (int i = 0; i < len1; i++)
        result[i] = str1[i];

    result[len1] = ' ';

    for (int i = 0; i < len2; i++)
        result[len1 + 1 + i] = str2[i];

    result[len1 + len2 + 1] = '\0';

    return result;
}


int main()
{

	char* str1 = malloc(100 * sizeof(char));
	char* str2 = malloc(100 * sizeof(char));

	if (str1 == NULL || str2 == NULL) {
		printf("Pusty string");
		free(str1);
		free(str2);
		return 7;
	}
	printf("Podaj pierwsze slowo: ");
	scanf(" %[^\n]", str1);

	printf("Podaj drugie slowo: ");
	scanf(" %[^\n]", str2);

	char* result = concat(str1, str2);
	printf("%s\n", result);

	free(str1);
	free(str2);
	free(result);
	return 0;
}

