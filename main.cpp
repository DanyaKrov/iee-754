#include "easy.h"
#include <vector>

using namespace std;

long long itc_pow(int n, int i)
{
    int m = 1;
    while (i > 0){
        i --;
        m *= n;
    }
    return m;
}
unsigned long long itc_not(unsigned long long num, int type)
{
    unsigned long long NumInTw = 0;
    long long i = 0;
    while (num > type - 1){
            if (num % type != 0)
                NumInTw += (num % type) * itc_pow(i, 10);
            num /= type;
            i++;
        }
    NumInTw += num * itc_pow(i, 10);
    return NumInTw;
}
int[] toMas(long double number)
{
    int num [32] = { };
    if (number < 0){
        number *= -1;
        num[0] = 1;
    }
    int x = itc_not((int) number, 2);
}
int main()
{
    long double x;
    cin >>x;
    if (x != 0.0)
    {
        for(int i = 0; i < 32; i++)
            cout <<i;
    }
    else if (x == std::numeric_limits<T>::infinity())
        cout <<"01111111111111111111111111111111" <<endl;
    else if (x == std::numeric_limits<T>::infinity() * -1)
        cout <<"11111111111111111111111111111111" <<endl;
    else if (x == -0.0)
        cout <<"10000000000000000000000000000000" <<endl;
    else
        cout <<"00000000000000000000000000000000" <<endl;
    return 0;
}
