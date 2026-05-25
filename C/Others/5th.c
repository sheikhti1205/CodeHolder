#include <stdio.h>
int main()
{
	int arr[2][2] = {{1, 2}, {3, 4}};
    int flag = 0;

	int i, j;

    printf("Two Dimensional Elements: \n");
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("%d ", arr[i][j]);
		} printf("\n");
	}

	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			if(i==j && arr[i][j] != 0)
            {
                flag = 1;
            }
		}
	}

    if(flag == 1)
            {
                printf("yes\n");
            }
            else{
                printf("no\n");
            }

	return 0;
}
