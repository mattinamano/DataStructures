#include <iostream>

using namespace std;

void fibonacciFor(int n)
{
    int i,t1=0,t2=1,term=0;
    for(i=1;i<=n;i++)
    {
         if(i == 1)
        {
            cout << " " << t1;
            continue;
        }
        if(i == 2)
        {
            cout <<" "<< t2<<" ";
            continue;
        }
        term = t1 + t2;
        t1 = t2;
        t2 = term;
        cout << term << " ";
    }
}
void fibonacciWhile(int n)
{
    int t1=-1,t2=1,term=0;
    while(n>0)
    {
        term = t1 + t2;
        t1 = t2;
        t2 = term;
        n--;
        cout <<term << " ";
    }
}
int fibonacciRec(int n)
{
    if(n<2)
    {
    return n;
    }
    else
    {
    return (fibonacciRec(n-1)+fibonacciRec(n-2));
    }
}
int main()
{
    int n = 4; // Number to find fibonacci;
    cout<<"calling fibonacci for";
    fibonacciFor(n);
    cout<<endl<<"calling fibonacci while ";
    fibonacciWhile(n);
    cout<<endl<<"calling fibonacci recursion ";
    for(int i=0;i<n;i++)
    {
    cout<<fibonacciRec(i)<<" ";
    }
    return 0;
}

