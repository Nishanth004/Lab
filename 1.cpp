#include<bits/stdc++.h>
using namespace std;

int min(int m, int n)
{
        if(m<n)
                return m;
        return n;
}
int consec(int m,int n)
{
        int r,t=min(m,n);
        clock_t st,end;
        st=clock();
        while( m%t!=0 || n%t!=0)
            t--;
        end=clock();
        cout<<"\ntime="<<((double)(end-st))/CLOCKS_PER_SEC<<"sec\n";
		cout<<"answer=";	
        return t;
	return 1;
}

int middle(int m,int n)
{
        
        int gcd=1;
        clock_t st,end;
        st=clock();
        for(int i=2;i<=min(m,n);++i)
        {
                while(((m%i)==0)&&((n%i)==0))
                {
                        gcd*=i;
                        m/=i;
                        n/=i;
                }
        }
        end=clock();
        cout<<"\ntime="<<((double)(end-st))/CLOCKS_PER_SEC<<"sec\n";
	    cout<<"answer=";
        return gcd;
}



int euclid_iter(int m,int n)
{
        clock_t st,end;
        st=clock();
        int r;
        while(n!=0)
        {
                r=m%n;
                m=n;
                n=r;
        }
        end=clock();
        cout<<"\ntime="<<((double)(end-st))/CLOCKS_PER_SEC<<"sec\n";
	    cout<<"answer=";
        return m;
}

int euclid_recur(int m, int n)
{
        int y=m%n;
        if(y==0)
                return n;
        return euclid_recur(n,y);
}


int main()
{
        clock_t st,end;
        int m,n,ch;
        cout<<"\n\nEnter the two numbers\n";
        cin>>m>>n;
        while(1)
        {
                cout<<"\n\n1.euclids alg using recursion\n2.euclids alg without recursion\n3.cont int checking alg \n4.middle school method\n5.exit\nEnter your choice\n";
                cin>>ch;
                switch(ch)
                {
                        case 1: st=clock();
                                cout<<"answer="<<euclid_recur(m,n);
                                end=clock();
                                cout<<"\ntime="<<((double)(end-st))/CLOCKS_PER_SEC<<"sec\n";
                                break;
                        case 2: cout<<euclid_iter(m,n);
                                break;
                        case 3: cout<<consec(m,n);
                                break;
                        case 4: cout<<middle(m,n);
                                break;
			case 5:exit(0);
                        default: cout<<"invalid input";
                }
        }
        return 0;
}
