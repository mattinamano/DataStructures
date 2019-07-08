#include <iostream>

using namespace std;

int factorialFor(int n)
{
    int i,fact=1;
    for(i=n;i>0;i--)
    {
        fact=fact*i;
    }
    return fact;
}
int factorialWhile(int n)
{
    int fact=1;
    while(n>0)
    {
        fact=fact*n;
        n--;
    }
    return fact;
}
int factorialRec(int n)
{
    int fact=1;
    if(n>1)
    return n*factorialRec(n-1);
    else
    return 1;
}
int main()
{
    int n = 4,fact,fact1,fact2; // Number to find factorial;
    fact=factorialFor(n);
    fact1=factorialWhile(n);
    fact2=factorialRec(n);
    cout<<"the factorial of "<<n<<" is "<<fact<<endl;
    cout<<"the factorial of "<<n<<" is "<<fact1<<endl;
    cout<<"the factorial of "<<n<<" is "<<fact2<<endl;
    return 0;
}

