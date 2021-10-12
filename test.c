#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{

	FILE *fp = fopen(argv[1], "r");
	char buf[10240];
	int malloc_lens[3000] = { 0 };
	int to_free[3000];
	char *points[3000];

	bzero(malloc_lens, sizeof(int)*3000);

	char *p = NULL;
	p = fgets(buf,10240,fp);
	if ( p == NULL ) 
	{
		perror("fgets");
		return -1;
	}

	int n = 0;
	for (;n < 3000;n++) {
		char *p1;
		if ( n == 0 )
			p1  = strtok(buf," ");
		else
			p1 = strtok(NULL," ");
		if ( p1 == NULL)
			break;
		malloc_lens[n] = atoi(p1);
	}
	printf("read item %d\n", n);

	p = fgets(buf,10240,fp);
	if ( p == NULL ) 
	{
		perror("fgets");
		return -1;
	}
	for (n=0;n < 3000;n++) {
		char *p1;
		if ( n == 0 )
			p1  = strtok(buf," ");
		else
			p1 = strtok(NULL," ");
		if ( p1 == NULL)
			break;
		to_free[n] = atoi(p1);
	}
	printf("read item %d\n", n);
	fclose(fp);


	// start
	int k = 0;
	for ( ; k < n; k++)
	{
		points[k] = malloc(malloc_lens[k]);
		if ( points[k] == NULL )
			printf("malloc error\n");

		if (malloc_lens[k] > 3)
			strcpy(points[k], "AA");
		if ( to_free[k] == 0 ){
			free(points[k]);
			points[k] = NULL;
		}
	}

	printf("%x %x , sub=%d\n", points[1],points[998], points[1]-points[998]);
	for (k =0; k < n;k++) 
	{
		if ( points[k] != NULL  ) {
			//if ( k == 661 || k == 617 )
				printf("sub[%d]=%d,  ptr=%p, size=%d\n", k, points[k] - points[998], points[k], malloc_lens[k] );
		}
	}

	char *p1 = points[617];
	char *p2 = points[661];

	char puz[100];
	memset(puz, 'B',99);
	puz[99] = 0 ;
	strcpy(p1, puz);

	printf("%d, %s\n", strlen(p1), p1);
	printf("%d, %s\n", strlen(p2), p2);
	return 0;
}


