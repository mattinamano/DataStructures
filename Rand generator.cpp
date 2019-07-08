#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int arr[10];
    for (int i=0; i < 10; i++)
    arr[i]=rand()%100;
    cout<<"the randomly generated array"<<endl;
    for (int i=0; i < 10; i++)
    cout<<arr[i]<<endl;
    return 0;
}
