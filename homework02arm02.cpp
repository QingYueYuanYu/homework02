#include <iostream>
#include<time.h>
using namespace std;

int main()
{
    int step = 2;
    for(int n=16;n<=5000;n*=step)
    {
    double sum,*a,sum1,sum2,sum3,sum4,sum5,sum6,sum7,sum8;
    sum = 0;
    sum1 = 0;
    sum2 = 0;
    sum3 = 0;
    sum4 = 0;
    sum5 = 0;
    sum6 = 0;
    sum7 = 0;
    sum8 = 0;
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
        sum1 += a[i];
        sum2 += a[i+1];
        sum3 += a[i+2];
        sum4 += a[i+3];
        sum5 += a[i+4];
        sum6 += a[i+5];
        sum7 += a[i+6];
        sum8 += a[i+7];
    }
    sum = sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7 + sum8;
    clock_gettime(CLOCK_MONOTONIC,&endTime);
    totaltime += ((endTime.tv_sec - startTime.tv_sec) * 10^9 + endTime.tv_nsec - startTime.tv_nsec)/1000000000.0;
    counter ++;
    }
    cout<<"n:"<<n<<" "<<"avgtime:"<<totaltime/counter<<"s"<<endl;
    delete[]a;
    }
    return 0;
}
