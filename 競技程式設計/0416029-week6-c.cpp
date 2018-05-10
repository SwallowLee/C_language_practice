#include<iostream>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--){
    	int m, k;
		int book[501]={0};
		int ans[501][501]={0};
        long long int Min=0,Max=0,mid;
        
		cin >> m >> k;
		for (int i=0;i<m;i++) {
        	cin >> book[i];
            if (book[i] > Min) Min=book[i];
            Max += book[i];
        }
        while (Min < Max){
            int amount=1;
            long long int sum=0;
            mid = (Min+Max)/2;
            for (int i=0;i<m;i++){
                if (sum+book[i] > mid){
                    amount++;
                    sum = 0;
                }
                sum += book[i];
            }
            if (amount > k)  Min = mid+1;
            else Max = mid;
        }
        
        int index[501]={0};
		
		long long sum = 0;
        for (int i=m-1, j=k-1; i>=0; i--){
            if (sum+book[i] > Max || j>i){
                j--;
                sum = 0;
            }
            sum += book[i];
            ans[j][index[j]++] = book[i];
        }

        for (int i=0; i<k; i++){
            for (int j=index[i]-1; j>=0; j--){
                if (i!=0 || j!=index[0]-1) cout<<' ';
                cout<<ans[i][j];
            }
            if (i != k-1) cout << " /";
        }
        cout << endl;
    }
    return 0;
}
