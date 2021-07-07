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
  vector<ll> ans(n, -1);
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

ll maximum_area_histogram(vector<ll> arr, n)
{
  vector<ll> nsel_v = nsel(arr, n);
  vector<ll> nser_v = nser(arr, n);

  ll ans = 0;
  for (ll i = 0; i < n; i++)
  {
    ans = max(ans, arr[i] * (nser_v[i] - nsel_v[i] - 1));
  }

  return ans;
}
