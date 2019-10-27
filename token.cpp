#include<iostream>

using namespace std;

int main()
{
        int tr=5,tt=5,n,i;
        cout<<"Enter the number of packets:";
        cin>>n;
        int buff[n];
        cout<<"Enter the size of each packets: \n";
        for(i=0;i<n;i++)
                cin>>buff[i];
        int clk=1;
        i=0;
        while(n!=i)
        {
                while(buff[i]<=tt)
                {
                        cout<<"Send "<<buff[i]<<" at clock "<<clk<<endl;
                        tt-=buff[i];
                        i++;
                }
                clk++;
                tt+=tr;
        }
        return 0;
}
