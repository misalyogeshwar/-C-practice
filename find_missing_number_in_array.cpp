#include <iostream>

using namespace std;

void find_missing_1(int a[],int len)
{
    int sum = (len * (len + 1))/2;
    int sum2 = 0;

    for( int i = 0 ; i < len -1 ; i++)
            sum2 += a[i];

    cout << " \n\t Your missing number is " << (sum - sum2);
}

void find_missing_2(int a[], int len)
{
    int x1 = 0 , x2 = 0;
    int i = 0;

    for(  i = 0 ; i < len-1 ; i++)
    {
        x1 = x1 ^ (i+1) ;
        x2 = x2 ^ a[i];
    }

    x1 = x1 ^ (i+1);

    cout << " \n\t Your missing number is " << (x1^x2);
}

int main()
{
    cout << "Hello world!" << endl;
    int a[] = {1,2,3,4,5,6,7,9};
   // find_missing_1(a,9);
    find_missing_2(a,9);
    return 0;
}
