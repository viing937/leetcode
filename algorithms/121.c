#include <stdio.h>

int maxProfit(int* prices, int pricesSize)
{
    if ( pricesSize < 2 )
        return 0;
    int i;
    int buy = pricesSize-2, sell = pricesSize-1;
    int max = sell;
    for ( i = pricesSize-2; i >= 0; i-- )
    {
        if ( prices[max]-prices[i] > prices[sell]-prices[buy] )
            buy = i, sell = max;
        if ( prices[i] > prices[max] )
            max = i;
    }
    return prices[sell]>prices[buy] ? prices[sell]-prices[buy] : 0;
}

int main()
{
    int arr[] = {5,1,4,7,24};
    printf("%d\n", maxProfit(arr, sizeof(arr)/sizeof(arr[0])));
    return 0;
}
