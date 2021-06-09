/*
AUTHOR: Aman Raj
College:IIT JODHPUR
Branch:CSE
LANG: C++
*/

using namespace std;

typedef     long long ll;
#include <bits/stdc++.h>


//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
#define fast  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
#define all(a) a.begin(),a.end()
//#define mod 998244353





#define inf 1e18
//#define mod 3
#define flush fflush(stdout)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef cc_hash_table<ll, ll, hash< ll > > ht;

// find_by_order()  // order_of_key
typedef tree<
    pair<ll,ll>,
    null_type,
    less<pair<ll,ll> >,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;




ll mod=1e9+7;

ll power1(ll a, ll b)//a raised to power b
   {  if(b<=0) return 1; if(b==1) return a;
       ll c=power1(a,b/2);
        c*=c;c%=mod;if(b%2==1) c*=a;c%=mod;
        return c;
   }
   ll mi(ll a)
   { ll c= power1(a,mod-2);

     return c;
   }



 struct less_then_greater {
    template<typename T, typename U>
    bool operator()(T const& lhs, U const& rhs) const {
        if (lhs.first < rhs.first) return true;
        if (rhs.first < lhs.first) return false;
        return lhs.second > rhs.second;
    }
};

 /*std::priority_queue<std::pair<int, int>,
                    std::vector<std::pair<int, int>>,
                    less_then_greater
                    > pq;*/
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
//cout<<"Case #"<<tt<<": "<<ans<<endl;

void prnt(vector<vector<char> > &v)
{
    ll r=v.size(),c=v[0].size();
    for(int i=0;i<r;i++)
     {
         for(int j=0;j<c;j++)cout<<v[i][j];
         cout<<endl;
     }
}
ll n,m;
vector<vector<pair<ll,ll> > > v;
vector<map<ll,ll>  > vd;
int main()
{  fast;
   //ifstream cin("ts1_input.txt");

    cin>>n>>m;
    v.resize(n);
    vd.resize(n);
    for(int i=0;i<m;i++)
    {
        ll a,b,c;cin>>a>>b>>c;
        a--;b--;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i=0;i<n;i++)
    {
        ll k;cin>>k;
         vector<ll> vt;
        while(k--)
        {
            ll a;cin>>a;
             vt.push_back(a);
        }
       reverse(all(vt));
       for(auto x:vt)
       {
           vd[i][x]=vd[i][x+1]+1;
       }

    }

    vector<ll> vans(n,inf);
    vans[0]=0;
    priority_queue<pair<ll,ll> > pq;//distance and node
    pq.push({0,0});
    while(pq.size()>0)
    {
        ll a=pq.top().second;cout<<a<<endl;
        ll d=vans[a];
        pq.pop();
        for(auto x:v[a])
        {
            ll e=max(vd[a][d]-1ll,0ll);//extra time that will take here

            ll nd=e+x.second+d;
            if(nd<vans[x.first])
            {
                pq.push({-nd,x.first});
                vans[x.first]=nd;
            }
        }
        //for(auto x:vans)cout<<x<<" ";cout<<endl;
    }
   //for(auto x:vans)cout<<x<<" ";cout<<endl;
    cout<<((vans[n-1]==inf)?-1:vans[n-1]);



    return 0;
}


