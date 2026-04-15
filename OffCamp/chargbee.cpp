bool isDiv(string& ans)
{
    int n = ans.size();
    int remainder = 0;

    for (int i = 0; i < n; ++i) {
        remainder = (remainder * 10 + (ans[i] - '0')) % 7;
    }

    return remainder == 0;
}
void increment(string& s)
{
    int n=s.size();//6
    int mid=n/2;//3
    if(n%2==0)
    {
        int z=s[mid]-'0';//
        s[mid]=z+1+'0';
        s[mid-1]=s[mid];
    }
    else
    {
        //we have to change just mid index
        s[mid]=(s[mid]-'0')+1+'0';
    }
}
string f(int n)
{
    string ans="1";
    if(n==1)
        return "7";
    else
    {
        for(int i=0;i<n-2;i++)
        {
            ans+=to_string(0);
        }
        ans+='1';
    }
    while(isDiv(ans)!=true)
    {
        increment(ans);
    }
    return ans;
}