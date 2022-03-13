#include <iostream>
#include<time.h>
using namespace std;

int main()
{
    int step = 2;
    for(int n=16;n<=5000;n*=step)
    {
    double sum,*a;
    sum = 0;
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
    for(int i=0;i<n;i+=8)
    {
        sum += a[i];
        sum += a[i+1];
        sum += a[i+2];
        sum += a[i+3];
        sum += a[i+4];
        sum += a[i+5];
        sum += a[i+6];
        sum += a[i+7];
    }
    clock_gettime(CLOCK_MONOTONIC,&endTime);
    totaltime += ((endTime.tv_sec - startTime.tv_sec) * 10^9 + endTime.tv_nsec - startTime.tv_nsec)/1000000000.0;
    counter ++;
    }
    cout<<"n:"<<n<<" "<<"avgtime:"<<totaltime/counter<<"s"<<endl;
    delete[]a;
    }
    return 0;
}
