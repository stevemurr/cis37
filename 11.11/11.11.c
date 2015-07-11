
#include <stdio.h>

int main(void)
{
	unsigned int account;
	char name[ 30 ];
	double balance;

	FILE *cfPtr;

	if (( cfPtr = fopen("clients.dat", "w")) == NULL) {
		puts("Could not open\n");
	} else {
		printf("%s", "? ");
		scanf("%d %29s %lf", &account, name, &balance);
		while ( !feof( stdin ) ) {
			fprintf(cfPtr, "%d %s %.2f\n", account, name, balance);
			printf("%s", "? ");
			scanf("%d %29s %lf", &account, name, &balance);
		}
		printf("%s\n", "Omg you guys");
	}
	fclose( cfPtr );
}