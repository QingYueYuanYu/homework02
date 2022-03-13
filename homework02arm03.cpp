#include <iostream>
#include<time.h>
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
    timespec startTime;
    timespec endTime;
    while(counter<20)
    {
    clock_gettime(CLOCK_MONOTONIC,&startTime);
    recursion(n,a);
    clock_gettime(CLOCK_MONOTONIC,&endTime);
    totaltime += ((endTime.tv_sec - startTime.tv_sec) * 10^9 + endTime.tv_nsec - startTime.tv_nsec)/1000000000.0;
    counter ++;
    }
    cout<<"n:"<<n<<" "<<"avgtime:"<<totaltime/counter<<"s"<<endl;
    delete[]a;
    }
    return 0;
}
