#define ll long long int

vector<ll> nsel(vector<ll> arr, ll n)
{
  stack<pair<ll, ll>> st;
  vector<ll> ans(n, -1);
  for (ll i = arr.size() - 1; i >= 0; i--)
  {
    while (!st.empty() && st.top().first > arr[i])
    {
      ans[st.top().second] = i;
      st.pop();
    }
    st.push(make_pair(arr[i], i));
  }
  return ans;
}

vector<ll> nser(vector<ll> arr, ll n)
{
  stack<pair<ll, ll>> st;
  vector<ll> ans(n, n);
  for (ll i = 0; i < arr.size(); i++)
  {
    while (!st.empty() && st.top().first > arr[i])
    {
      ans[st.top().second] = i;
      st.pop();
    }
    st.push(make_pair(arr[i], i));
  }
  return ans;
}

ll maximum_area_histogram(vector<ll> arr, ll n)
{
  vector<ll> nsel_v = nsel(arr, n);
  vector<ll> nser_v = nser(arr, n);

  // for(auto i : nsel_v) cout<<i<<" ";
  // cout<<"\n";

  // for(auto i : nser_v) cout<<i<<" ";
  // cout<<"\n";

  ll ans = 0;
  for (ll i = 0; i < n; i++)
  {
    ans = max(ans, arr[i] * (nser_v[i] - nsel_v[i] - 1));
    // cout<<ans<<"\n";
  }

  return ans;
}

class Solution
{
public:
  int maxArea(int M[MAX][MAX], int n, int m)
  {
    int mat[n + 1][m + 1];
    for (ll i = 0; i < m; i++)
    {
      ll val = 0;
      for (ll j = 0; j < n; j++)
      {
        if (M[j][i] == 0)
        {
          val = 0;
        }
        else
        {
          val += 1;
        }
        mat[j][i] = val;
      }
    }

    ll ans = 0;

    for (ll i = 0; i < n; i++)
    {
      vector<ll> arr;
      for (ll j = 0; j < m; j++)
      {
        arr.push_back(mat[i][j]);
        // cout<<mat[i][j]<<" ";
      }
      // cout<<"\n";
      ans = max(ans, maximum_area_histogram(arr, m));
    }
    return ans;
  }
};