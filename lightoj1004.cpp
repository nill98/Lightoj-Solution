/*
   Author A.G.Maruf
   10 th sem :P
   code written 2020-02-19-12.38()
*/
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cctype>
#define gc              getchar
#define pc              putchar
#define pb              push_back
#define Sort_arr(n,x)   sort(n,n+x);
#define Sortr_arr(arr,x)  sort(arr, arr+n,greater<int>());
#define SortS(s)        sort(s.begin(), s.end());
#define SortRS(s)       sort(s.rbegin(), s.rend());
#define all(s)          s.begin(), s.end()a
#define GCin(a)         getline(cin,a);
#define Sz(a)           a.size()
#define arr_rev(n)      sort(n.begin(), n.end(), greater<int>());
#define Gin(a)          getline(cin,a);
#define input(a)        scanf("%d",&a);
#define Sz(a)           a.size()
#define input2(a,b)     scanf("%d %d",&a,&b);
#define input3(a,b,c)   scanf("%d %d %d",&a,&b,&c);
#define input4(a,b,c,d) cin>>a>>b>>c>>d;
#define rep(n)          for(int i=1;i<n;i++)
#define Fast_read       ios_base::sync_with_stdio(false);
#define Unique(n)       sort(Search(n)),n.erase(unique(Search(n)),n.end());
#define PI              3.1415926535897932384626433832795l
#define Ignore          cin.ignor3e();
#define out(n)          cout<<n<<endl;
#define mem(n,i)        memset(n,i,sizeof n);
#define square(n)       (n*n)
#define cube(n)         (n*n*n)
#define F               first
#define S               second
#define mxin            -INFINITY
#define mnin            INFINITY
#define el              <<endl
#define MAXC 1000
//#define N 1000000
using namespace std;

/*------------------------------Graph Moves----------------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/__gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

//typedef pair <ll, ll> pll;
typedef long long int ll;
const int Max = 1e4 + 10;
const int MOD = 1e9 + 7;

int main ()
{

    Fast_read
    int cs=1,t;
    cin>>t;

    while (t--)
    {
        int n;
        cin>>n;
        int arr[2*n+5][n+5],ans[2*n+5][n+5];

        mem(arr,0);
        mem(ans,0);

        for (int i=0; i<n; i++)
        {
            for (int j=0; j<=i; j++)
                cin>>arr[i][j];

        }

        for (int i=n,k=n-1; i<2*n-1; i++,k--)
        {
            for (int j=0; j<k; j++)
            {
                cin>>arr[i][j];
            }
        }


        ans[0][0]=arr[0][0];
        for (int i=0; i<n-1; i++)
        {
            for (int j=0; j<=i; j++)
            {
                ans[i+1][j]=max(arr[i+1][j]+ans[i][j],ans[i+1][j]);
                ans[i+1][j+1]=max(arr[i+1][j+1]+ans[i][j],ans[i+1][j+1]);
            }
        }

        for (int i=n-1,k=n-1; i<2*n-2; i++,k--)
        {
            for (int j=0; j<=k; j++)
            {

                if (j!=0 and j!=k){

                    ans[i+1][j-1]=max(arr[i+1][j-1]+ans[i][j],ans[i+1][j-1]);
                    ans[i+1][j]=max(arr[i+1][j]+ans[i][j],ans[i+1][j]);
                }
                else if (j==0){
                    ans[i+1][j]=max(arr[i+1][j]+ans[i][j],ans[i+1][j]);
                }
                else if (j==k){
                     ans[i+1][j-1]=max(arr[i+1][j-1]+ans[i][j],ans[i+1][j-1]);
                }
            }
        }
        cout<<"Case "<<cs++<<": ";
        cout<<ans[2*n-2][0]<<endl;

    }
}
