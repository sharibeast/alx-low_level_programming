#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 8

void generate_password(void)
{
	char password[PASSWORD_LENGTH];

	for (int i = 0; i < PASSWORD_LENGTH; i++)
	{
		int random_number = rand() % 94 + 33;

		password[i] = (char)random_number;
	}

	printf("%s\n", password);
}

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		generate_password();
	}

	return 0;
}
