// ...

#include<bits/stdc++.h>
using namespace std;

//-----------------------------------------------------------------------------------
typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define int long long
#define float long double
#define mm multimap
#define pb push_back
#define ff first
#define ss second
#define ln length
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define repe(i,a,b)  for(int i=a;i<=b;i++)
#define m_p make_pair
#define go_flash ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
const int mod = 1000000007;
const int inf = LLONG_MAX;
const int ninf = LLONG_MIN;
//-----------------------------------------------------------------------------------
void primeFactors(int p) {
    while (!(p % 2)) {p /= 2;} for (int i = 3; i * i <= p; i += 2) {
        while (!(p % i)) {p /= i;}
    } if (p > 2) {;}
}
//-----------------------------------------------------------------------------------
template<typename...T>void input(T &...args) {((cin >> args), ...);}
template<typename...T>void print(T &&...args) {((cout << args << " "), ...);}
template<typename...T>void deb(T &&...args) {((cerr << args << " "), ...); cerr << endl;}
#define debug(x) cerr<<#x<<" => "<<x<<" ";
//-----------------------------------------------------------------------------------
void forv(vector<int> &v, int n) {int x; for (int i = 0; i < n; i++) {cin >> x; v.pb(x);}}
void printv(vector<int> v) {for (auto i : v) {cout << i << " ";}}
void fora(int *a, int n) {for (int i = 0; i < n; i++)cin >> a[i];}
void printa(int *a, int n) {for (int i = 0; i < n; i++)cout << a[i] << " ";}
void dmap(map<int, int> mp) {for (auto i : mp)cout << i.ff << " " << i.ss << endl;}
void dmmap(mm<int, int> mp) {for (auto i : mp)cout << i.ff << " " << i.ss << endl;}
void sortra(int *a, int n) {sort(a, a + n, greater<int>());}
void sortrv(vector<int> &v) {sort(all(v), greater<int>());}
//-----------------------------------------------------------------------------------
inline void guts() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif
}
//-----------------------------------------------------------------------------------
map<string, string> ids, cg_marks;
ifstream infile;


void input_names() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string st_no, name;
    int t = 123;
    while (t--) {
        infile >> st_no;
        name = "";
        string temp; infile >> temp;
        name += temp;
        while (temp.substr(0, 1) != "7") {
            infile >> temp;
            name += " ";
            name += temp;
        }

        // deb(st_no, name);
        ids[st_no] = name;
    }
    for (auto i : ids) {
        cout << i.ff << " " << i.ss << endl;
    }
    // deb(ids.size());
}

// void input_names(ifstream infile) {

//     while(!infile.eof()){
//         infile >> st;
//     }

// }


void input_cg_marks() {
    // freopen("CG_MKS.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string st_no, mks;
    int t = 61;
    while (t--) {
        infile >> st_no >> mks;
        cg_marks[st_no] = mks;
    }
    for (auto i : cg_marks) {
        cout << i.ff << " " << i.ss << endl;
    }
    // deb(cg_marks.size());
}


void solve()
{

    infile.open("input.txt");
    input_names();
    infile.close();
    infile.open("CG_MKS.txt");
    input_cg_marks();
    infile.close();
    // input_cg_marks();
    // input_cg_marks();
    // input_cg_marks();
    // input_cg_marks();


}


signed main()
{
    go_flash;
    guts();
    // cout << fixed << setprecision(6);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        //Your Code Blows HERE
        solve();
        // cout << endl;
    }
    return 0;
}