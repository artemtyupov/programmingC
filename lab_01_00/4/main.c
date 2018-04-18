#include <stdio.h>
#include <math.h>
#define bottle_count(sum) ((sum-20)/25)
 int main(void)
{
    int k;
    int sum;
    printf("How many you have: ");
    scanf("%d", &sum);
    k = bottle_count(sum);
    printf("Number bottle's of water = : %d", k);
}

