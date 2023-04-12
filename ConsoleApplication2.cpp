#include <iostream>

using namespace std;

bool IsKPeriodic(int k, string s)
{
    int k_t = 0;

    int i = 0;
    string temp = s.substr(0,1);
    while (i < s.size()-1)
    {
        string slice =  s.substr(i+1, temp.size());
        if (slice == temp)
        {
            i += slice.size();
            k_t++;
        }
        else
        {
            i++;
            temp += s[i];
            k_t = 0;
        }
   
    }

    return k_t == k;
}

int main()
{
    cout << IsKPeriodic(3, "abcabcabcabc") << endl;
    cout << IsKPeriodic(3, "aaaa") << endl;
    cout << IsKPeriodic(1, "ab") << endl;

    return 0;
}