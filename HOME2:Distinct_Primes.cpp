int Solution::solve(vector<int> &A) 
{
    int n=A.size();
    int max=A[0];
    for(int i=0;i<n;i++)                    //for calculating maximum element of array 'A'
    {
        if(max<A[i])
        {
            max=A[i];
        }
    }


    vector<int> spf(max+1);                 //creating an 'spf' array which will contain smallest prime factor for every number
    spf[0]=0;
    spf[1]=0;
    for(int i=2;i<=max;i++)
    {
        spf[i]=i;
    }
    for(int i=2;i*i<=max;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<=max;j+=i)
            { 
                spf[j]=i;
            }
        }
    }


    vector<int> hg1(max+1,0);                //creating an vector to count number of every i from 0 to max(A) will present in our G 
    for(int i=0;i<n;i++)
    {
        int temp=A[i];
        while(temp>1)
        {
            hg1[spf[temp]]++;
            temp=temp/spf[temp];
        }
    }
    int ans=0;
    for(int i=0;i<hg1.size();i++)               //counting total number of distinct prime divisors of G.
    {
        if(hg1[i]>0)
        {
            ans++;
        }
    }
    return ans;


}
//T.C. = O(N logN)
//refer to page 10, notebook 3
