ll setBit(ll n, ll k)
{
    return (n | (1 << (k - 1)));
}
  
// Function to clear the kth bit of n
ll clearBit(ll n, ll k)
{
    return (n & (~(1 << (k - 1))));
}
  
// Function to toggle the kth bit of n
ll toggleBit(ll n, ll k)
{
    return (n ^ (1 << (k - 1)));
}
