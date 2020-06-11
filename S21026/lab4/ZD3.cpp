#include <iostream>
#include <cstdlib>

using namespace std;



int main(int argc, char **argv)
{
    const int n = atoi(argv[1]);

    for (int i = 1; i<=n; i++)
    {
        for(int j=1; j<=2*n-1;j++)
        {
            if(j>= n-(i-1) && j <=n+(i-1))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}