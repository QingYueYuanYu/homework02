#include <iostream>
#include<windows.h>
using namespace std;
void recursion(int n,double *a)
{
    if(n==1)
        return ;
    else
    {
        for(int i=0;i<n/2;i++)
            a[i] += a[n-i-1];
        n = n/2;
        recursion(n,a);
    }

}

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
    recursion(n,a);
    QueryPerformanceCounter(&endTime);
    totaltime += (endTime.QuadPart - startTime.QuadPart)/quadpart;
    counter ++;
    }
    cout<<"n:"<<n<<" "<<"avgtime:"<<totaltime/counter<<"s"<<endl;
    delete[]a;
    }
    return 0;
}
