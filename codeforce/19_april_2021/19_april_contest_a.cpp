#include<iostream>
using namespace std;

bool is_square(int x)
{
    if (x == 1)
        return true;
    int i = 1;
    while (i <= x/2)
    {
        if (x == i * i)
            return true;
        i++;
    }
    return false;
}
int main()
{

    int t = 0;  /* no of test cases */
    int i = 0;
    int j = 0;
    cin>>t;
    for (i = 0; i < t; i++)
    {
        bool flag = true;
        int n = 0;
        cin>>n;
        int input[n];
        for (j = 0; j < n; j++)
        {
            cin>>input[j];
        }
        for (j = 0; j < n; j++)
        {
            flag = is_square(input[j]);
            if (flag == false)
            {
                cout<<"YES"<<endl;
                break;
            }
        }
        if (flag == true)
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
