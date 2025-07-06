#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int T;
	cin>>T;
        while (T-- > 0)
        {   
    		int N;
            cin>>N;
            
            int i;
            
            int max_freq = 0;
            int freq = 0;
            
            int ans = 0;
                    
            for (i = 2; i*i <= N; i++)
            {
                if(N%i != 0)
                continue;
                
                freq = 0;
                while (N%i == 0)
                {
                	N /= i;
                	freq++;
				}
				
				if (freq > max_freq)
				{
					max_freq = freq;
					ans = i;
				}
            }
            
            if(N != 1)
            {
            	freq = 1;
            	
            	if (freq > max_freq)
            	{
            		max_freq = freq;
            		ans = N;
				}
			}
            cout<<ans<<"\n";
        }

	return 0;
}