#include <iostream>
#include<windows.h>
using namespace std;
int main()
{
    int step = 2;
    for(int n=16;n<=5000;n*=step)
    {
    double sum,*a;
    a = new double[n];
    for(int i=0;i<n;i++)
    {
        a[i] = rand()%1;
    }
    double totaltime = 0;
    int counter = 0;
    LARGE_INTEGER startTime;
    LARGE_INTEGER endTime;
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    double quadpart = (double)frequency.QuadPart;
    while(counter<20)
    {
    QueryPerformanceCounter(&startTime);
    for(int m=n;m>1;m/=2)
        for(int i=0;i<m/2;i++)
            a[i] = a[i*2] + a[i*2+1];
    QueryPerformanceCounter(&endTime);
    totaltime += (endTime.QuadPart - startTime.QuadPart)/quadpart;
    counter ++;
    }
    cout<<"n:"<<n<<" "<<"avgtime:"<<totaltime/counter<<"s"<<endl;
    delete[]a;
    }
    return 0;
}
