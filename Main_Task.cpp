#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string Reverse(string s)
{
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        if (s[i] == '0')
        {
            s[i] = '1';
        }
        else
        {
            s[i] = '0';
        }
    }
    return s;
}

string Sum_Stb(string s1, string s2)
{
    int s11 = s1.size();
    int s22 = s2.size();
    int t = int(s1[0]) + int(s2[0]);
    int promezhytok = 0, res, l;
    string s3;
    if (s11 == s22)
    {
        int h = 0;
        for (int i = 0; i < s11; i++)
        {
            if (i < s11 - s22)
            {
                s3.push_back('0');
            }
            else
            {
                s3.push_back(s2[h]);
                h++;
            }
        }
        int t = int(s1[0]) + int(s2[0]) - '0' - '0';
        if (t >= 10)
        {
            l = s11 + 1;
        }
        else
        {
            l = s11;
        }
        char rez[l];
        for (int i = s11 - 1; i >= 0; i--)
        {
            s11 = s1[i] - '0';
            s22 = s3[i] - '0';
            res = s11 + s22;
            if (promezhytok == 1)
            {
                res++;
            }
            if (res >= 10)
            {
                char t = res % 10;
                rez[i + 1] = t + '0';
                promezhytok = 1;
                if (i == 0)
                {
                    rez[0] = '1';
                    break;
                }
                continue;
            }
            promezhytok = 0;
            char t = res;
            rez[i + 1] = t + '0';
        }
        string ans;
        for (int i = 0; i < l; i++)
        {
            ans.push_back(rez[i]);
        }
        return ans;
    }
    if (s11 > s22)
    {
        int h = 0;
        for (int i = 0; i < s11; i++)
        {
            if (i < s11 - s22)
            {
                s3.push_back('0');
            }
            else
            {
                s3.push_back(s2[h]);
                h++;
            }
        }
        int t = int(s1[0]) + int(s2[0]) - '0' - '0';
        if (t >= 10)
        {
            l = s11 + 1;
        }
        else
        {
            l = s11;
        }
        char rez[l];
        for (int i = s11 - 1; i >= 0; i--)
        {
            s11 = s1[i] - '0';
            s22 = s3[i] - '0';
            res = s11 + s22;
            if (promezhytok == 1)
            {
                res++;
            }
            if (res >= 10)
            {
                char t = res % 10;
                rez[i + 1] = t + '0';
                promezhytok = 1;
                if (i == 0)
                {
                    rez[0] = '1';
                    break;
                }
                continue;
            }
            promezhytok = 0;
            char t = res;
            rez[i] = t + '0';
        }
        string ans;
        for (int i = 0; i < l; i++)
        {
            ans.push_back(rez[i]);
        }
        return ans;
    }
    return "0";
}

string Proizved_Stb(string a, string n)
{
    int *A, *B, *C, length, l, cc;
    A = new int[a.size()];
    B = new int[n.size()];

    for (int i = 0; i < a.size(); i++)
    {
        A[i] = a[a.size() - i - 1] - '0';
    }
    for (int i = 0; i < n.size(); i++)
    {
        B[i] = n[n.size() - i - 1] - '0';
    }

    length = a.size() + n.size() - 1;
    l = length;
    C = new int[length + 1];
    for (int ix = 0; ix < length; ix++)
    {
        C[ix] = 0;
    }

    for (int ix = 0; ix < a.size(); ix++)
    {
        for (int jx = 0; jx < n.size(); jx++)
        {
            C[ix + jx] += A[ix] * B[jx];
        }
    }

    for (int ix = 0; ix < length - 1; ix++)
    {
        C[ix + 1] += C[ix] / 10;
        C[ix] %= 10;
    }

    while (C[length] == 0)
    {
        length--;
    }
    if (C[length] >= 10)
    {
        int perem = C[length] / 10;
        C[length] = C[length] % 10;
        C[length + 1] = perem;
    }
    string res;
    bool p = false;
    for (int i = length + 1; i > -1; i--)
    {
        if (C[i] == 0 && p == false)
        {
            p = true;
            continue;
        }
        else
        {
            cout << char(C[i] + '0');
            res.push_back(char(C[i]) + '0');
        }
        p = true;
    }
    return res;
}
int main()
{
    string s, s1;
    getline(cin, s);
    getline(cin, s1);
    s = Reverse(s);
    
    return 0;
}