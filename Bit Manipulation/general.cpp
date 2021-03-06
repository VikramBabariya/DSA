// Function to set the kth bit of n
int setBit(int n, int k)
{
    return (n | (1 << k));
}
  
// Function to clear the kth bit of n
int clearBit(int n, int k)
{
    return (n & (~(1 << k)));
}
  
// Function to toggle the kth bit of n
int toggleBit(int n, int k)
{
    return (n ^ (1 << k));
}

// Function to check kth bit is set or not 
//LSB is 0
bool isSet(int n, int k)
{
    if (n & (1 << k))
        return true;
    return false;
}

int main(){

    // test    
    
    return 0;
}
