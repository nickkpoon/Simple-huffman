#include <iostream>
using namespace std;

void makeHeap(int *array,int i,int size)
{    
    int n, temp;
    temp = array[i];
    n = i * 2;

    while (n <= size)
    {
        if (n < size && array[n+1] < array[n])
            n++;
        
        if (temp < array[n])
            break;
        
        else if (temp >= array[n])
        {
            array[n/2] = array[n];
            n = n*2;
        }
    }

    array[n/2] = temp;
    return;
}

void build(int *array, int size)
{
    int i;
    for(i = size/2; i >= 1; i--)
    {
        makeHeap(array,i,size);
    }
}

int main()
{
    int size=25, i, x;
    int array[26]; //max 26 lower case letters possible
    
    //fills up array with values
    //for now it accepts user input as frequency value
    //will get it changed once count frequency is implemented
    for (i = 1; i <= size; i++)
    {
        cout<<"enter the frequency for element:"<<(i)<<endl;
        cin>>array[i];
    }
    
    //make heap from filled array
    build(array, size);

    /*****print entire heap to debug*****
    */
    cout<<"\nprint:\n";
    for (i = 1; i <= size; i++)
    {
        cout<<array[i]<<endl;
    }
    
    return 0;
}