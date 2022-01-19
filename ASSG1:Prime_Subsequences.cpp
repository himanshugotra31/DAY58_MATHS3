const int mod=1000000007;
int Solution::solve(vector<int> &A) 
{
    int n=A.size();
    int max=A[0];               
    for(int i=0;i<n;i++)                                //finding maximum element of array 'A'         
    {
        if(max<A[i])
        {
            max=A[i];
        }
    }
    vector<int> hg1(max+1,1);                           // vector 'hg1' to check prime number from 0 to A
    for(int i=0;i<hg1.size();i++)
    {
        hg1[i]=i;
    }
    hg1[0]=0;
    hg1[1]=0;
    for(int i=2;i*i<=max;i++)
    {
        if(hg1[i]==i)
        {
            hg1[i]=i;
            for(int j=i*i;j<=max;j+=i)
            {
                hg1[j]=0;
            }
        }
    }

    sort(A.begin(),A.end());
    int ans=1;                              //'ans' will carry total number of subsequences from 1 to A
    for(int i=0;i<n;i++)                    //since we know if M is the number of prime integers in an array, then the number of Prime Subsequences will be((2 ^ M) - 1).
    {                                       
        if(A[i]==hg1[A[i]])
        {
            ans=((ans%mod)*2)%mod;
        }
    }
    return ans-1;

}
//refer to page 8-9, notebook 3

