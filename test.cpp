#include <iostream>
#include <fstream>

using namespace std;

struct node
{
    char character;
    int frequency;
};

struct freqTable
{
    int size;
    node *table;
};

node * initializeArray(int size)
{
    node array[27];

    for (int i = 0; i < size; i++)
    {
        char ascii = i + 97;
        if (i = 27)
            ascii = 32;

        array[i].character = ascii;
        array[i].frequency = 0;
        
    }
    return array;
}

/*freqTable *initializeTable(int size)
{
    freqTable *ftable;
    if (size < MIN_TABLE_SIZE)
    {
        cout<<"Table Size Too Small"<<endl;
        return NULL;
    }
    ftable = new freqTable;
    if (ftable == NULL)
    {
        cout<<"Out of Space"<<endl;
        return NULL;
    }
    ftable->size = size;
    ftable->table = new HashNode [ftable->size];
    if (ftable->table == NULL)
    {
        cout<<"Table Size Too Small"<<endl;
        return NULL;
    }
    for (int i = 0; i < ftable->size; i++)
    {
        char ascii = i + 97;
        if (i = 27)
            ascii = 32;

        ftable->table[i].character = ascii;
        ftable->table[i].frequency = 0;
        
    }
    return ftable;
}*/

void makeHeap(node *array, int i, int size)
{
    int temp = array[i].frequency;
    int n;
    n = i * 2;

    while (n <= size)
    {
        if (n < size && array[n+1].frequency < array[n].frequency)
            n++;
        
        if (temp < array[n].frequency)
            break;
        
        else if (temp >= array[n].frequency)
        {
            array[n/2].frequency = array[n].frequency;
            array[n/2].character = array[n].character;
            n = n*2;
        }
    }

    array[n/2].frequency = temp;
    return;

}

void build(node *array, int size)
{
    int i;
    for (i = size / 2; i >= 1; i--)
    {
        makeHeap(array, i, size);
    }
}

int main(int, char **)
{
    ifstream fin;
    int arrray[28];
    int ascii;
    char next;

    node *farray;
    farray = initializeArray(28);

    for (int i = 0; i < 27; i++)
    {
    	arrray[i] = 0;
    }

    do
    {
        fin.open("dank");
        if(!fin)
        {
            cout<<"can't open file"<<endl;
            return 0;
        }
    }
    while(!fin);

    while((next=fin.get())!=EOF)
    {
    	cout<<next<<endl;
        ascii = next;
        if(ascii == 32) //32 is ascii for space, does not align well with 'a' which is #97
        {
            ascii = 123; //97+26
        }
        ascii = ascii-97;
        arrray[ascii]++;
    }


    for (int i = 0; i < 27; i++)
    {
    	cout<<arrray[i]<<endl;
    }

    return 0;
}