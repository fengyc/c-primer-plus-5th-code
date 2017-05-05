#include <stdio.h>
#include <string.h>

int gcd(int x, int y)
{
    int k = x % y;
    if (k==0){
        return y;
    }
    return gcd(y, k);
}

char r[100][100];

int main(void) {

    int w, x, y, z;
    int p, q;
    int k;
    int count=0;

    memset(r, 0, 100*100);

    scanf("%d %d %d %d", &w, &x, &y, &z);

    for (p=w; p<=x; p++)
    {
        for(q=y; q<=z; q++)
        {
            if (p>q)
                k = gcd(p, q);
            else
                k=gcd(q,p);
            if (r[p/k][q/k]==0) {
                count++;
                r[p/k][q/k] = 1;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}

