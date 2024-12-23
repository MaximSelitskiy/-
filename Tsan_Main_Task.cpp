#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class BOCHKA
{
public:
    int raby[5] = {0};
    int isPoisoned = 0;
};
int drink_BOCHKA(BOCHKA Bochki[], int raby[])
{
    int Killed = 0;
    for (int i = 0; i < 240; i++)
    {
        if (Bochki[i].isPoisoned)
        {
            for (int j = 0; j < 5; j++)
            {
                if (Bochki[i].raby[j])
                {
                    raby[j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (raby[i])
        {
            cout << "Раб под номером " << i + 1 << " мёртв" << '\n';
        }
        else
            Killed++;
    }
    return Killed;
}

void BOCHHKI()
{
    cout << "Введите номер отравленной бочки." << '\n';
    BOCHKA Bochki[240];
    int raby[5] = {0};
    int poisoned = 0;
    cin >> poisoned;
    Bochki[poisoned].isPoisoned = 1;
    int k = 0;
    int t = 0;
    for (int i = 0; i < 240; i++)
    {
        if (i < 32)
        {
            continue;
        }
        else if (i < 112)
        {

            t = i % 10;
            if (t == 2)
            {
                k = 1;
            }
            else if (t == 5)
            {
                k += 2;
            }
            else if (t == 3 || t == 7)
            {
                k++;
            }
            else if (t == 8)
            {
                k += 4;
            }
            else if (t == 0)
            {
                k += 11;
            }
            else if (t == 1)
            {
                k += 3;
            }
            for (int j = 0; j < 5; j++)
            {
                Bochki[i].raby[j] = ((t + k) >> j) & 1;
            }
        }
        else if (i < 152)
        {
            t = i % 10;
            if (t == 2)
            {
                k = 5;
            }
            else if (t == 3)
            {
                k += 3;
            }
            else if (t == 4 || t == 7 || t == 1)
            {
                k++;
            }
            else if (t == 6)
            {
                k += 4;
            }
            else if (t == 9)
            {
                k += 2;
            }
            else if (t == 0)
            {
                k += 10;
            }
            for (int j = 0; j < 5; j++)
            {
                Bochki[i].raby[j] = ((t + k) >> j) & 1;
            }
        }
        else if (i < 232)
        {
            t = i % 5;
            if (t == 2)
            {
                k = 0;
            }
            else if (t == 3)
            {
                k++;
            }
            else if (t == 4)
            {
                k += 3;
            }
            else if (t == 0)
            {
                k += 12;
            }
            else if (t == 1)
            {
                k += 16;
            }
            for (int j = 0; j < 5; j++)
            {
                Bochki[i].raby[j] = ((t + k) >> j) & 1;
            }
        }
        else
        {
            t = i % 5;
            if (t == 2)
            {
                k = 13;
            }
            else if (t == 3)
            {
                k += 7;
            }
            else if (t == 4)
            {
                k += 3;
            }
            else if (t == 0)
            {
                k += 6;
            }
            for (int j = 0; j < 5; j++)
            {
                Bochki[i].raby[j] = ((t + k) >> j) & 1;
            }
        }
    }

    // for (int i = 0; i < 240; i++)
    // {
    //     cout << i << ": [ ";
    //     for (int j = 0; j < 5; j++)
    //     {
    //         cout << Bochki[i].raby[j] << ' ';
    //     }
    //     cout << "]\n";
    // }

    int Killed = drink_BOCHKA(Bochki, raby);
    cout << "Рабы под номерами 1 - мёртвые, а  0 - живые: [ ";
    for (int i = 0; i < 5; i++)
    {
        cout << raby[i] << " ";
    }
    cout << "]\n";
    int count = 0;
    k = 0;
    for (int i = 0; i < 240; i++)
    {
        if (Bochki[i].raby[0] == raby[0] && Bochki[i].raby[1] == raby[1] && Bochki[i].raby[2] == raby[2] && Bochki[i].raby[3] == raby[3] && Bochki[i].raby[4] == raby[4])
        {
            k = i;
            count++;
            cout << "Бочка под номером " << i << " вероятно отравлена" << '\n';
        }
    }
    if (count == 1)
    {
        cout << "Бочка под номером " << k << " отравлена" << '\n';
        return;
    }

    cout << "Надо проверить " << count << " бочек с вином" << '\n';
    for (int i = 0; i < 240; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            Bochki[i].raby[j] = -1;
        }
    }
    t = 0;
    if (Killed == 5)
    {
        for (int i = 0; i < 32; i++)
        {
            cout << i << ": ";
            for (int j = 0; j < 5; j++)
            {
                Bochki[i].raby[j] = (i >> j) & 1;
                cout << Bochki[i].raby[j] << " ";
            }
            cout << '\n';
        }
    }
    if (Killed == 4)
    {
        raby[0] = 0;
        raby[1] = 0;
        raby[2] = 0;
        raby[3] = 0;
        raby[4] = 1;
        for (int i = k; i >= 152; i -= 5)
        {
            cout << i << ": ";
            for (int j = 0; j < 4; j++)
            {
                Bochki[i].raby[j] = (t >> j) & 1;
                cout << Bochki[i].raby[j] << " ";
            }
            Bochki[i].raby[4] = 1;
            cout << '\n';
            t++;
        }
        cout << k << '\n';
    }
    if (Killed == 3)
    {
        raby[0] = 0;
        raby[1] = 0;
        raby[2] = 0;
        raby[3] = 1;
        raby[4] = 1;
        for (int i = k; i >= 32; i -= 10)
        {
            cout << i << ": ";
            for (int j = 0; j < 3; j++)
            {
                Bochki[i].raby[j] = (t >> j) & 1;
                cout << Bochki[i].raby[j] << " ";
            }
            Bochki[i].raby[3] = 1;
            Bochki[i].raby[4] = 1;
            cout << '\n';
            t++;
        }
        cout << k << '\n';
    }
    if (Killed == 2)
    {
        raby[0] = 0;
        raby[1] = 0;
        raby[2] = 1;
        raby[3] = 1;
        raby[4] = 1;
        for (int i = k; i >= 112; i -= 10)
        {
            cout << i << ": ";
            for (int j = 0; j < 2; j++)
            {
                Bochki[i].raby[j] = (t >> j) & 1;
                cout << Bochki[i].raby[j] << " ";
            }
            Bochki[i].raby[2] = 1;
            Bochki[i].raby[3] = 1;
            Bochki[i].raby[4] = 1;
            cout << '\n';
            t++;
        }
        cout << k << '\n';
    }
    if (Killed == 1)
    {
        raby[0] = 0;
        raby[1] = 1;
        raby[2] = 1;
        raby[3] = 1;
        raby[4] = 1;
        for (int i = k; i >= 232; i -= 5)
        {
            cout << i << ": ";
            Bochki[i].raby[0] = 0;
            for (int j = 0; j < 1; j++)
            {
                Bochki[i].raby[j] = (t >> j) & 1;
                cout << Bochki[i].raby[j] << " ";
            }
            Bochki[i].raby[1] = 1;
            Bochki[i].raby[2] = 1;
            Bochki[i].raby[3] = 1;
            Bochki[i].raby[4] = 1;
            cout << '\n';
            t++;
        }
        cout << k << '\n';
    }
    drink_BOCHKA(Bochki, raby);
    for (int i = 0; i < 240; i++)
    {
        if (Bochki[i].raby[0] == raby[0] && Bochki[i].raby[1] == raby[1] && Bochki[i].raby[2] == raby[2] && Bochki[i].raby[3] == raby[3] && Bochki[i].raby[4] == raby[4])
        {
            cout << "Бочка с вином под номером " << i << " отравлена" << '\n';
        }
    }
    return;
}

string Reverse(string s)
{
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        if (s[i] == '0')
        {
            s[i] = '1';
            continue;
        }
        if (s[i] == '1')
        {
            s[i] = '0';
        }
    }
    return s;
}

string Sum_Stb(string s1, string s2)
{
    int s11_s = s1.size();
    int s22_s = s2.size();
    int s11 = s11_s;
    int s22 = s22_s;
    if (s11 == 0)
    {
        return s2;
    }
    if (s22 == 0)
    {
        return s1;
    }
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
                if (l == s11_s + 1)
                {
                    rez[i + 1] = t + '0';
                }
                else
                {
                    rez[i] = t + '0';
                }
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
            if (i == 0)
            {
                rez[0] = t + '0';
                break;
            }
            if (l == s11_s + 1)
            {
                rez[i + 1] = t + '0';
            }
            else
            {
                rez[i] = t + '0';
            }
        }
        string ans;
        for (int i = 0; i < l; i++)
        {
            if (rez[i] >= '0' && rez[i] <= '9')
            {
                ans.push_back(rez[i]);
            }
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
                if (l == s11_s + 1)
                {
                    rez[i + 1] = t + '0';
                }
                else
                {
                    rez[i] = t + '0';
                }
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
            if (i == 0)
            {
                rez[0] = t + '0';
                break;
            }
            if (l == s11_s + 1)
            {
                rez[i + 1] = t + '0';
            }
            else
            {
                rez[i] = t + '0';
            }
        }
        string ans;
        for (int i = 0; i < l; i++)
        {
            if (rez[i] >= '0' && rez[i] <= '9')
            {
                ans.push_back(rez[i]);
            }
        }
        return ans;
    }

    if (s22 > s11)
    {
        int h = 0;
        for (int i = 0; i < s22; i++)
        {
            if (i < s22 - s11)
            {
                s3.push_back('0');
            }
            else
            {
                s3.push_back(s1[h]);
                h++;
            }
        }
        int t = int(s1[0]) + int(s2[0]) - '0' - '0';
        if (t >= 10)
        {
            l = s22 + 1;
        }
        else
        {
            l = s22;
        }
        char rez[l];
        for (int i = s22 - 1; i >= 0; i--)
        {
            s22 = s2[i] - '0';
            s11 = s3[i] - '0';
            res = s11 + s22;
            if (promezhytok == 1)
            {
                res++;
            }
            if (res >= 10)
            {
                char t = res % 10;
                if (l == s22_s + 1)
                {
                    rez[i + 1] = t + '0';
                }
                else
                {
                    rez[i] = t + '0';
                }
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
            if (i == 0)
            {
                rez[0] = t + '0';
                break;
            }
            if (l == s22_s + 1)
            {
                rez[i + 1] = t + '0';
            }
            else
            {
                rez[i] = t + '0';
            }
        }
        string ans;
        for (int i = 0; i < l; i++)
        {
            if (rez[i] >= '0' && rez[i] <= '9')
            {
                ans.push_back(rez[i]);
            }
        }
        return ans;
    }
    return "0";
}

string Proizved_Stb(string a, string n)
{
    if (a[0] == '0' || n[0] == '0')
    {
        return "0";
    }
    bool minus = false;
    if (a[0] == '-' && n[0] != '-')
    {
        minus = true;
        string a1;
        for (int i = 1; i < a.size(); i++)
        {
            a1.push_back(a[i]);
        }
        a = a1;
    }
    if (n[0] == '-' && a[0] != '-')
    {
        minus = true;
        string a1;
        for (int i = 1; i < n.size(); i++)
        {
            a1.push_back(n[i]);
        }
        n = a1;
    }
    if (a[0] == '-' && n[0] == '-')
    {
        minus = false;
        string a1;
        for (int i = 1; i < a.size(); i++)
        {
            a1.push_back(a[i]);
        }
        a = a1;
        string a2;
        for (int i = 1; i < n.size(); i++)
        {
            a2.push_back(n[i]);
        }
        n = a2;
    }
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
    if (minus == true)
    {
        res.push_back('-');
    }
    for (int i = length + 1; i > -1; i--)
    {
        if (C[i] == 0 && p == false)
        {
            p = true;
            continue;
        }
        else
        {
            // cout << char(C[i] + '0');
            res.push_back(char(C[i]) + '0');
        }
        p = true;
    }
    return res;
}

string Answer(string s1)
{
    string ans = "0", per = "1";
    int size = s1.size();
    for (int i = 0; i < size; i++)
    {
        if (s1[i] == '1')
        {
            for (int j = size - i - 1; j > 0; j--)
            {
                per = Proizved_Stb(per, "2");
            }
            ans = Sum_Stb(per, ans);
            per = "1";
        }
    }
    return ans;
}

string Bin_Sum(string s1, string s2)
{
    int s11_s = s1.size();
    int s22_s = s2.size();
    int s11 = s11_s;
    int s22 = s22_s;
    if (s11 == 0)
    {
        return s2;
    }
    if (s22 == 0)
    {
        return s1;
    }
    int promezhytok = 0, res, l;
    string s3, per;
    bool minus = false;
    if (s22 > s11)
    {
        minus = true;
        per = s2;
        s2 = s1;
        s1 = per;
        int u = s22;
        s22 = s11;
        s11 = u;
        u = s22_s;
        s22_s = s11_s;
        s11_s = u;
    }
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
    if (t >= 2)
    {
        l = s11 + 1;
    }
    else
    {
        l = s11;
    }
    char rez[l + 1];
    bool another = false;
    for (int i = s11_s - 1; i >= 0; i--)
    {
        s11 = s1[i] - '0';
        s22 = s3[i] - '0';
        res = s11 + s22;
        if (promezhytok == 1)
        {
            res++;
        }
        if (res == 2)
        {
            res = 10;
        }
        promezhytok = 0;
        if (res == 3)
        {
            another = true;
            res -= 2;
            promezhytok = 1;
        }
        if (res >= 10)
        {
            char t = res % 10;
            rez[i + 1] = t + '0';
            promezhytok = 1;
            if (i == 0)
            {
                if (s1[i] == '1' && s3[i] == '1' && another == true)
                {
                    rez[1] = '1';
                    rez[0] = '1';
                    break;
                }
                if (s1[i] == '1' && s3[i] == '1' && another == false)
                {
                    rez[1] = '0';
                    rez[0] = '1';
                    break;
                }
                if ((s1[i] == '1' && s3[i] == '0') || (s1[i] == '0' && s3[i] == '1'))
                {
                    rez[1] = '0';
                    rez[0] = '1';
                    break;
                }
                rez[0] = t + '0';
                break;
            }
            continue;
        }
        char t = res;
        if (i == 0)
        {
            if (s1[i] == '1' && s3[i] == '1' && another == true)
            {
                rez[1] = '1';
                rez[0] = '1';
                break;
            }
            if (s1[i] == '1' && s3[i] == '1' && another == false)
            {
                rez[1] = '0';
                rez[0] = '1';
                break;
            }
            rez[0] = t + '0';
            break;
        }
        rez[i + 1] = t + '0';
        another = false;
    }
    string ans;
    for (int i = 0; i < l + 1; i++)
    {
        if (rez[i] >= '0' && rez[i] <= '9')
        {
            ans.push_back(rez[i]);
        }
    }
    return ans;
}

string Raznost_Stb(string s1, string s2)
{
    int s11_s = s1.size();
    int s22_s = s2.size();
    if (s1[0] == '-' && s2[0] != '-')
    {
        string s1_cpy, s2_cpy, ans;
        for (int i = 0; i < s11_s; i++)
        {
            if (s1[i] != '-')
            {
                s1_cpy.push_back(s1[i]);
            }
        }
        ans.push_back('-');
        ans += Sum_Stb(s1_cpy, s2);
        return ans;
    }
    if (s2[0] == '-' && s1[0] != '-')
    {
        string s2_cpy;
        for (int i = 0; i < s22_s; i++)
        {
            if (s2[i] != '-')
            {
                s2_cpy.push_back(s2[i]);
            }
        }
        string ans;
        ans = Sum_Stb(s2_cpy, s1);
        return ans;
    }
    if (s2[0] == '-' && s1[0] == '-')
    {
        string s2_cpy, s1_cpy;
        for (int i = 0; i < s22_s; i++)
        {
            if (s1[i] != '-')
            {
                s2_cpy.push_back(s2[i]);
            }
        }
        for (int i = 0; i < s11_s; i++)
        {
            if (s1[i] != '-')
            {
                s1_cpy.push_back(s1[i]);
            }
        }
        s2 = s1_cpy;
        s1 = s2_cpy;
    }
    s11_s = s1.size();
    s22_s = s2.size();
    int s11 = s11_s;
    int s22 = s22_s;
    if (s11 == 0)
    {
        return s2;
    }
    if (s22 == 0)
    {
        return s1;
    }
    int promezhytok = 0, res, l;
    string s3, per;
    bool minus = false;
    if (s22 > s11)
    {
        minus = true;
        per = s2;
        s2 = s1;
        s1 = per;
        int u = s22;
        s22 = s11;
        s11 = u;
        u = s22_s;
        s22_s = s11_s;
        s11_s = u;
    }
    if (s11 == s22)
    {
        int h = 0;
        int t;
        for (int i = 0; i < s11; i++)
        {
            if (s1[i] != s2[i])
            {
                int y = int(s1[i]) - '0';
                int g = int(s2[i]) - '0';
                t = y - g;
                break;
            }
        }
        if (t < 0)
        {
            minus = true;
            per = s2;
            s2 = s1;
            s1 = per;
            int u = s22;
            s22 = s11;
            s11 = u;
            u = s22_s;
            s22_s = s11_s;
            s11_s = u;
        }
        l = s11 + 1;
        char rez[l];
        for (int i = s11 - 1; i >= 0; i--)
        {
            s11 = s1[i] - '0';
            s22 = s2[i] - '0';
            res = s11 - s22;
            if (promezhytok == 1)
            {
                res--;
            }
            if (res < 0)
            {
                res += 10;
                char t = res;
                if (l == s11_s - 1)
                {
                    rez[i - 1] = t + '0';
                }
                else
                {
                    rez[i] = t + '0';
                }
                promezhytok = 1;
                continue;
            }
            promezhytok = 0;
            char t = res;
            if (l == s11_s - 1)
            {
                rez[i - 1] = t + '0';
            }
            else
            {
                rez[i] = t + '0';
            }
        }
        string ans;
        bool p = 0;
        bool ans_b = 0;
        if (minus == true)
        {
            ans.push_back('-');
        }
        for (int i = 0; i < l; i++)
        {
            if (rez[i] != '0' && p == 0)
            {
                p = 1;
            }
            if (rez[i] >= '0' && rez[i] <= '9' && p == 1)
            {
                ans.push_back(rez[i]);
                ans_b = 1;
            }
        }
        if (ans_b == 0)
        {
            ans.clear();
            ans.push_back('0');
        }
        return ans;
    }
    else
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
        int y = int(s1[0]) - '0';
        int g = int(s2[0]) - '0';
        int t = y - g;
        l = s11 + 1;
        char rez[s11 + 1];
        for (int i = s11 - 1; i >= 0; i--)
        {
            s11 = s1[i] - '0';
            s22 = s3[i] - '0';
            res = s11 - s22;
            if (promezhytok == 1)
            {
                res--;
            }
            if (res < 0)
            {
                res += 10;
                char t = res;
                if (l == s11_s - 1)
                {
                    rez[i - 1] = t + '0';
                }
                else
                {
                    rez[i] = t + '0';
                }
                promezhytok = 1;
                continue;
            }
            promezhytok = 0;
            char t = res;
            if (l == s11_s - 1)
            {
                rez[i - 1] = t + '0';
            }
            else
            {
                rez[i] = t + '0';
            }
        }
        string ans;
        bool p = 0;
        if (minus == true)
        {
            ans.push_back('-');
        }
        for (int i = 0; i < l; i++)
        {
            if (rez[i] != '0' && p == 0)
            {
                p = 1;
            }
            if (rez[i] >= '0' && rez[i] <= '9' && p == 1)
            {
                ans.push_back(rez[i]);
            }
        }
        return ans;
    }
    return "0";
}

string To_The_Bin(string s1)
{
    bool minus = false;
    if (s1[0] == '-')
    {
        s1.erase(0, 1);
        minus = true;
    }
    int size = s1.size();
    string ans, sum, final_sum = "0";
    if (minus == true)
    {
        ans.push_back('-');
    }
    int k = 0;
    while (s1[0] != '0')
    {
        k++;
        if (k == 8)
        {
            int y = 0 + 8;
        }
        size = s1.size();
        int t = s1[size - 1] - '0';
        if (t % 2 == 0)
        {
            ans.push_back('0');
        }
        else
        {
            ans.push_back('1');
        }
        for (int i = 0; i < size; i++)
        {
            int h = s1[i] - '0';
            double n = (double)h / 2;
            if (i != size - 1)
            {
                n *= 10;
                int n1 = n;
                if (n1 >= 10)
                {
                    char t = n1 % 10;
                    t += '0';
                    char t1 = n / 10;
                    t1 += '0';
                    sum.push_back(t1);
                    sum.push_back(t);
                }
                else
                {
                    char t = n1;
                    t += '0';
                    sum.push_back(t);
                }
                for (int j = i; j < size - 2; j++)
                {
                    sum.push_back('0');
                }
                final_sum = Sum_Stb(sum, final_sum);
            }
            if (i == size - 1)
            {
                int n1 = (s1[i] - '0') / 2;
                char t = n;
                t += '0';
                sum.push_back(t);

                final_sum = Sum_Stb(sum, final_sum);
            }
            sum.clear();
        }
        s1 = final_sum;
        final_sum.clear();
    }
    if (ans[0] == '-')
    {
        reverse(ans.begin() + 1, ans.end());
    }
    else
    {
        reverse(ans.begin(), ans.end());
    }

    return ans;
}

string Raznost_Stb_Bin(string s1, string s2)
{
    int s11_s = s1.size();
    int s22_s = s2.size();
    if (s1[0] == '-' && s2[0] != '-')
    {
        string s1_cpy, s2_cpy, ans;
        for (int i = 0; i < s11_s; i++)
        {
            if (s1[i] != '-')
            {
                s1_cpy.push_back(s1[i]);
            }
        }
        ans.push_back('-');
        ans += Bin_Sum(s1_cpy, s2);
        return ans;
    }
    if (s2[0] == '-' && s1[0] != '-')
    {
        string s2_cpy;
        for (int i = 0; i < s22_s; i++)
        {
            if (s1[i] != '-')
            {
                s2_cpy.push_back(s2[i]);
            }
        }
        string ans;
        ans = Bin_Sum(s2_cpy, s1);
        return ans;
    }
    if (s2[0] == '-' && s1[0] == '-')
    {
        string s2_cpy, s1_cpy;
        for (int i = 0; i < s22_s; i++)
        {
            if (s1[i] != '-')
            {
                s2_cpy.push_back(s2[i]);
            }
        }
        for (int i = 0; i < s11_s; i++)
        {
            if (s1[i] != '-')
            {
                s1_cpy.push_back(s1[i]);
            }
        }
        s2 = s1_cpy;
        s1 = s2_cpy;
    }
    s11_s = s1.size();
    s22_s = s2.size();
    int s11 = s11_s;
    int s22 = s22_s;
    if (s11 == 0)
    {
        return s2;
    }
    if (s22 == 0)
    {
        return s1;
    }
    int promezhytok = 0, res, l;
    string s3, per;
    bool minus = false;
    if (s22 > s11)
    {
        minus = true;
        per = s2;
        s2 = s1;
        s1 = per;
        int u = s22;
        s22 = s11;
        s11 = u;
        u = s22_s;
        s22_s = s11_s;
        s11_s = u;
    }
    if (s11 == s22)
    {
        int h = 0;
        int t;
        for (int i = 0; i < s11; i++)
        {
            if (s1[i] != s2[i])
            {
                int y = int(s1[i]) - '0';
                int g = int(s2[i]) - '0';
                t = y - g;
                break;
            }
        }
        if (t < 0)
        {
            minus = true;
            per = s2;
            s2 = s1;
            s1 = per;
            int u = s22;
            s22 = s11;
            s11 = u;
            u = s22_s;
            s22_s = s11_s;
            s11_s = u;
        }
        l = s11;
        char rez[l];
        for (int i = s11 - 1; i >= 0; i--)
        {
            s11 = s1[i] - '0';
            s22 = s2[i] - '0';
            res = s11 - s22;
            if (promezhytok == 1)
            {
                res--;
            }
            if (res < 0)
            {
                res = 1;
                char t = res;
                if (l == s11_s - 1)
                {
                    rez[i - 1] = t + '0';
                }
                else
                {
                    rez[i] = t + '0';
                }
                promezhytok = 1;
                continue;
            }
            promezhytok = 0;
            char t = res;
            if (l == s11_s - 1)
            {
                rez[i - 1] = t + '0';
            }
            else
            {
                rez[i] = t + '0';
            }
        }
        string ans;
        bool p = 0;
        bool ans_b = 0;
        if (minus == true)
        {
            ans.push_back('-');
        }
        for (int i = 0; i < l; i++)
        {
            if (rez[i] == '1' && p == 0)
            {
                p = 1;
            }
            if (rez[i] >= '0' && rez[i] <= '1' && p == 1)
            {
                ans.push_back(rez[i]);
                ans_b = 1;
            }
        }
        if (ans[1] == '0' && minus == true)
        {
            ans.clear();
            ans.push_back('0');
        }
        if (ans[0] == '0' && minus == false)
        {
            ans.clear();
            ans.push_back('0');
        }
        return ans;
    }
    else
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
        int y = int(s1[0]) - '0';
        int g = int(s2[0]) - '0';
        int t = y - g;
        l = s11 + 1;
        char rez[s11 + 1];
        for (int i = s11 - 1; i >= 0; i--)
        {
            s11 = s1[i] - '0';
            s22 = s3[i] - '0';
            res = s11 - s22;
            if (promezhytok == 1)
            {
                res--;
            }
            if (res < 0)
            {
                res = 1;
                char t = res;
                if (l == s11_s - 1)
                {
                    rez[i - 1] = t + '0';
                }
                else
                {
                    rez[i] = t + '0';
                }
                promezhytok = 1;
                continue;
            }
            promezhytok = 0;
            char t = res;
            if (l == s11_s - 1)
            {
                rez[i - 1] = t + '0';
            }
            else
            {
                rez[i] = t + '0';
            }
        }
        string ans;
        bool p = 0;
        if (minus == true)
        {
            ans.push_back('-');
        }
        for (int i = 0; i < l; i++)
        {
            if (rez[i] == '1' && p == 0)
            {
                p = 1;
            }
            if (rez[i] >= '0' && rez[i] <= '1' && p == 1)
            {
                ans.push_back(rez[i]);
            }
        }
        if (ans[1] == '0' && minus == true)
        {
            ans.clear();
            ans.push_back('0');
        }
        if (ans[0] == '0' && minus == false)
        {
            ans.clear();
            ans.push_back('0');
        }
        return ans;
    }
    return "0";
}

void Task_1()
{
    cout << "Перевести числа согласно своему варианту. Предусмотреть ввод" << '\n';
    cout << "положительных и отрицательных чисел. Длинна числа не ограничена." << '\n';
    cout << "Из дополнительного кода в естественную форму" << '\n';
    cout << "*****************************************************************" << '\n';
    cout << "Введите число для перевода" << '\n';
    string s, s_cpy, per = "1";
    getline(cin, s);
    string ans;
    if (s[0] == '-')
    {
        cout << '-';
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            if (s[i] != '-')
            {
                s_cpy.push_back(s[i]);
            }
        }
        s = s_cpy;
        s = Reverse(s);
        ans = Answer(s);
        ans = Sum_Stb(ans, "1");
    }
    else
    {
        ans = Answer(s);
    }
    cout << "Ответ" << '\n';
    cout << ans;
}

string Is_Int()
{
    string s;
    bool proverka;
    while (1)
    {
        getline(cin, s);
        for (int i = 0; i < s.size(); i++)
        {
            proverka = isdigit(s[i]);
            if (proverka == false)
            {
                cin.clear();
                cout << "Неверный ввод" << '\n';
                break;
            }
        }
        if (proverka == true)
        {
            break;
        }
    }
    return s;
}

void Task_2()
{
    cout << "Найдите сумму двоичных чисел, заданных в естественной форме.a" << '\n';
    cout << "Сложение выполните в дополнительном коде. Ответ выразите в" << '\n';
    cout << "естественной форме." << '\n';
    cout << "*************************************************************" << '\n';
    bool minus1 = false, minus2 = false, both_less_zero = false;
    string s1, s2;
    cout << "Введите первое число" << '\n';
    s1 = Is_Int();
    cout << "Введите второе число" << '\n';
    s2 = Is_Int();
    if (s1[0] == '-')
    {
        minus1 = true;
        s1.erase(0, 1);
    }
    if (s2[0] == '-')
    {
        minus2 = true;
        s2.erase(0, 1);
    }
    bool changed = false;
    if (minus1 == true && minus2 == false)
    {
        if (s1 == s2)
        {
            cout << 0;
            return;
        }
        string bolche = Raznost_Stb(s1, s2);
        if (bolche[0] == '-')
        {
            changed = true;
            bolche = s1;
            s1 = s2;
            s2 = bolche;
        }
    }
    if (minus2 == true && minus1 == false)
    {
        if (s1 == s2)
        {
            cout << 0;
            return;
        }
        string bolche = Raznost_Stb(s2, s1);
        if (bolche[0] == '-')
        {
            changed = true;
            bolche = s1;
            s1 = s2;
            s2 = bolche;
        }
    }
    if (minus1 == true && minus2 == true)
    {
        both_less_zero = true;
        string bolche = s1;
        s1 = s2;
        s2 = bolche;
        minus1 = false;
        minus2 = false;
    }
    s1 = To_The_Bin(s1);
    s2 = To_The_Bin(s2);
    int size1 = s1.size();
    int size2 = s2.size();
    if (minus1 == true)
    {
        if (size1 < size2)
        {
            s1.insert(0, size2 - size1, '0');
        }
        s1 = Reverse(s1);
        s1 = Bin_Sum(s1, "1");
    }
    if (minus2 == true)
    {
        if (size2 < size1)
        {
            s2.insert(0, size1 - size2, '0');
        }
        s2 = Reverse(s2);
        s2 = Bin_Sum(s2, "1");
    }
    string ans, s_cpy;
    if (minus2 == false && minus1 == false)
    {
        ans = Bin_Sum(s1, s2);
    }
    if (minus1 == true && minus2 == true)
    {
        ans = Bin_Sum(s1, s2);
    }
    if (minus1 == true && minus2 == false)
    {
        ans = Bin_Sum(s2, s1);
        if (changed == false)
        {
            ans.insert(0, 1, '-');
        }
    }
    if (minus1 == false && minus2 == true)
    {
        ans = Bin_Sum(s1, s2);
        if (changed == false)
        {
            ans.insert(0, 1, '-');
        }
    }
    if (ans[0] == '-' && ans[1] == '-')
    {
        ans.erase(0, 1);
    }

    string ans1;
    string f;
    if (ans[0] == '-')
    {
        cout << '-';
        if (ans[0] == '-')
        {
            ans.erase(0, 1);
        }
        string per = ans;
        ans = Reverse(per);
        ans1 = Answer(ans);
        ans1 = Sum_Stb(ans1, "1");
    }
    else
    {
        if (changed == true)
        {
            string per = ans;
            ans = Reverse(per);
            ans1 = Answer(ans);
            ans1 = Sum_Stb(ans1, "1");
            cout << ans1;
            return;
        }
        if (both_less_zero == true)
        {
            cout << '-';
        }
        ans1 = Answer(ans);
    }
    cout << "Ответ" << '\n';
    cout << ans1;
}

bool To11(string s)
{
    string sum_ch = "0", sum_nech = "0", per;
    int size = s.size();
    bool ch = false;
    bool nech = true;
    for (int i = 0; i < size; i++)
    {
        if (nech == true)
        {
            per.push_back(s[i]);
            sum_ch = Sum_Stb(sum_ch, per);
            per.clear();
        }
        if (ch == true)
        {
            per.push_back(s[i]);
            sum_nech = Sum_Stb(sum_nech, per);
            per.clear();
        }
        if (nech == true)
        {
            nech = false;
            ch = true;
            continue;
        }
        if (ch == true)
        {
            nech = true;
            ch = false;
        }
    }
    if (sum_nech == sum_ch)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool To43(string s)
{
    int size = s.size();
    string f_part = "", s_part = "", sum = "0";
    while (size > 3)
    {
        s_part.push_back(s[size - 1]);
        s.erase(size - 1, 1);
        f_part = s;
        for (int i = 0; i < 13; i++)
        {
            if (sum == "0" && s_part == "0")
            {
                sum = "0";
                break;
            }
            sum = Sum_Stb(sum, s_part);
        }
        s = Sum_Stb(f_part, sum);
        f_part.clear();
        s_part.clear();
        sum.clear();
        size = s.size();
    }
    string h = "43";
    while (h.size() <= 3)
    {
        if (h == s)
        {
            return 1;
        }
        else
        {
            h = Sum_Stb(h, "43");
        }
    }
    return 0;
}

bool To179(string s)
{
    int size = s.size();
    string f_part = "", s_part = "", sum = "0";
    while (size > 3)
    {
        s_part.push_back(s[size - 1]);
        s.erase(size - 1, 1);
        f_part = s;
        for (int i = 0; i < 18; i++)
        {
            if (sum == "0" && s_part == "0")
            {
                sum = "0";
                break;
            }
            sum = Sum_Stb(sum, s_part);
        }
        s = Sum_Stb(f_part, sum);
        f_part.clear();
        s_part.clear();
        sum.clear();
        size = s.size();
    }
    string h = "179";
    while (h.size() <= 3)
    {
        if (h == s)
        {
            return 1;
        }
        else
        {
            h = Sum_Stb(h, "179");
        }
    }
    return 0;
}

void Task_4()
{
    string s;
    getline(cin, s);
    if (To11(s) == 1)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }
    if (To43(s) == true)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }
    if (To179(s) == true)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }
}

void Task_5()
{
    BOCHHKI();
}

string Any_Sum(string s1, string s2, int n)
{
    int s11_s = s1.size();
    int s22_s = s2.size();
    int s11 = s11_s;
    int s22 = s22_s;
    if (s11 == 0)
    {
        return s2;
    }
    if (s22 == 0)
    {
        return s1;
    }
    int promezhytok = 0, res, l;
    string s3, per;
    bool minus = false;
    if (s22 > s11)
    {
        minus = true;
        per = s2;
        s2 = s1;
        s1 = per;
        int u = s22;
        s22 = s11;
        s11 = u;
        u = s22_s;
        s22_s = s11_s;
        s11_s = u;
    }
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
    l = s11;
    string rez;
    if (n <= 10)
    {
        for (int i = s11_s - 1; i >= 0; i--)
        {
            s11 = s1[i] - '0';
            s22 = s3[i] - '0';
            res = s11 + s22;
            if (promezhytok == 1)
            {
                res++;
            }
            promezhytok = 0;
            if (res > n - 1)
            {
                res -= n;
                promezhytok++;
            }
            char t = res;
            rez.push_back(t + '0');
            if (i == 0 && res == 0)
            {
                rez.push_back('1');
            }
        }
    }
    else
    {
        for (int i = s11_s - 1; i >= 0; i--)
        {
            bool k1 = isupper(s1[i]);
            bool k2 = isupper(s3[i]);
            if (k1 == true)
            {
                s11 = s1[i] - '7';
            }
            if (k2 == true)
            {
                s22 = s3[i] - '7';
            }
            if (k1 == false)
            {
                s11 = s1[i] - '0';
            }
            if (k2 == false)
            {
                s22 = s3[i] - '0';
            }
            res = s11 + s22;
            if (promezhytok == 1)
            {
                res++;
            }
            promezhytok = 0;
            if (res > n - 1)
            {
                promezhytok++;
                res -= n;
            }
            char t = res;
            if (res > 36)
            {
                rez.push_back('[');
                while (res > 10)
                {
                    t = res % 10;
                    rez.push_back(t + '0');
                    res /= 10;
                }
                t = res;
                rez.push_back(t + '0');
                rez.push_back(']');
                continue;
            }
            if (res >= 10)
            {
                t = res + 55;
                rez.push_back(t);
            }
            if (res < 10)
            {
                rez.push_back(t + '0');
            }
        }
    }

    string ans;
    for (int i = rez.size() - 1; i >= 0; i--)
    {
        bool k1 = isupper(rez[i]);
        bool k2 = isalnum(rez[i]);
        if (k1 == true || k2 == true || rez[i] == '[' || rez[i] == ']')
        {
            if (rez[i] == ']')
            {
                ans.push_back('[');
                continue;
            }
            if (rez[i] == '[')
            {
                ans.push_back(']');
                continue;
            }
            ans.push_back(rez[i]);
        }
    }
    return ans;
}

string Any_Raz(string s1, string s2, int n)
{
    int s11_s = s1.size();
    int s22_s = s2.size();
    s11_s = s1.size();
    s22_s = s2.size();
    int s11 = s11_s;
    int s22 = s22_s;
    if (s11 == 0)
    {
        return s2;
    }
    if (s22 == 0)
    {
        return s1;
    }
    int promezhytok = 0, res, l;
    string s3, per;
    bool minus = false;
    if (s22 > s11)
    {
        minus = true;
        per = s2;
        s2 = s1;
        s1 = per;
        int u = s22;
        s22 = s11;
        s11 = u;
        u = s22_s;
        s22_s = s11_s;
        s11_s = u;
    }
    int t;
    if (s11 == s22)
    {
        for (int i = 0; i < s11; i++)
        {
            if (s1[i] != s2[i])
            {
                int y = int(s1[i]) - '0';
                int g = int(s2[i]) - '0';
                t = y - g;
                break;
            }
        }
        if (t < 0)
        {
            minus = true;
            per = s2;
            s2 = s1;
            s1 = per;
            int u = s22;
            s22 = s11;
            s11 = u;
            u = s22_s;
            s22_s = s11_s;
            s11_s = u;
        }
    }
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
    string rez;
    if (n <= 10)
    {
        int y = int(s1[0]) - '0';
        int g = int(s2[0]) - '0';
        t = y - g;
        l = s11 + 1;
        for (int i = s11 - 1; i >= 0; i--)
        {
            s11 = s1[i] - '0';
            s22 = s3[i] - '0';
            res = s11 - s22;
            if (promezhytok == 1)
            {
                res--;
            }
            if (res < 0)
            {
                res += n;
                char t = res;
                rez.push_back(t + '0');
                promezhytok = 1;
                continue;
            }
            promezhytok = 0;
            char t = res;
            rez.push_back(t + '0');
        }
    }
    else
    {
        if (minus == true)
        {
            string per = s1;
            s1 = s3;
            s3 = per;
        }
        int y = int(s1[0]) - '0';
        int g = int(s2[0]) - '0';
        t = y - g;
        l = s11 + 1;
        for (int i = s11 - 1; i >= 0; i--)
        {
            bool k1 = isupper(s1[i]);
            bool k2 = isupper(s3[i]);
            if (k1 == true)
            {
                s11 = s1[i] - '7';
            }
            if (k2 == true)
            {
                s22 = s3[i] - '7';
            }
            if (k1 == false)
            {
                s11 = s1[i] - '0';
            }
            if (k2 == false)
            {
                s22 = s3[i] - '0';
            }
            res = s11 - s22;
            if (promezhytok == 1)
            {
                res--;
            }
            promezhytok = 0;
            char t = res;
            if (res < 0)
            {
                res += n;
                promezhytok = 1;
            }
            if (res > 36)
            {
                rez.push_back('[');
                while (res > 10)
                {
                    t = res % 10;
                    rez.push_back(t + '0');
                    res /= 10;
                }
                t = res;
                rez.push_back(t + '0');
                rez.push_back(']');
                continue;
            }
            if (res >= 10)
            {
                t = res + 55;
                rez.push_back(t);
            }
            if (res < 10)
            {
                rez.push_back(t + '0');
            }
            if (i == 0 && promezhytok == 1)
            {
                res = n - 1;
                t = res + 55;
                rez.push_back(t);
            }
        }
    }
    string ans;
    bool p = 0;
    if (minus == true)
    {
        ans.push_back('-');
    }
    for (int i = rez.size() - 1; i >= 0; i--)
    {
        if (rez[i] != '0' && p == 0)
        {
            p = 1;
        }
        bool k1 = isupper(rez[i]);
        bool k2 = isalnum(rez[i]);
        if ((k1 == true || k2 == true || rez[i] == '[' || rez[i] == ']') && p == 1)
        {
            if (rez[i] == ']')
            {
                ans.push_back('[');
                continue;
            }
            if (rez[i] == '[')
            {
                ans.push_back(']');
                continue;
            }
            ans.push_back(rez[i]);
        }
        //}
    }
    return ans;
}

int N_Checker2()
{
    int n;
    while (1)
    {
        cin >> n;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Неверный ввод" << '\n';
            continue;
        }
        else
        {
            return n;
        }
    }
}

string Is_Int_Char(int n)
{
    bool alpha, digit, alnum;
    string s;
    char t = n + '0';
    while (1)
    {
        getline(cin, s);
        for (int i = 0; i < s.size(); i++)
        {
            alnum = isalnum(s[i]);
            digit = isdigit(s[i]);
            alpha = isupper(s[i]);
            if (n < 10 && alpha == true)
            {
                cin.clear();
                cout << "Неверный ввод" << '\n';
                alnum = false;
                break;
            }
            if (n >= 10 && alpha == true)
            {
                char t = n + 55;
                if (s[i] > t)
                {
                    cin.clear();
                    cout << "Неверный ввод" << '\n';
                    alnum = false;
                    break;
                }
            }
            if (s[i] >= t && digit == true)
            {
                cin.clear();
                cout << "Неверный ввод" << '\n';
                alnum = false;
                break;
            }
            if (alnum == false)
            {
                cin.clear();
                cout << "Неверный ввод" << '\n';
                break;
            }
        }
        if (alnum == true)
        {
            for (int j = 0; j < s.size(); j++)
            {
                s[j] = toupper(s[j]);
            }
            return s;
        }
    }
}

void Task_3()
{
    int n;
    cout << "Введите систему счисления" << '\n';
    n = N_Checker2();
    string s1, s2;
    cin.ignore();
    cout << "Введите первое число" << '\n';
    s1 = Is_Int_Char(n);
    cout << "Введите второе число" << '\n';
    s2 = Is_Int_Char(n);
    cout << "Сумма: " << '\n';
    cout << Any_Sum(s1, s2, n) << '\n';
    cout << "Разность: " << '\n';
    cout << Any_Raz(s1, s2, n) << '\n';
    return;
}
int N_Checker()
{
    int n;
    while (1)
    {
        cin >> n;
        if (n < 1 || n > 5)
        {
            cout << "Неверный ввод" << '\n';
            cin.clear();
            cin.ignore();
        }
        else
        {
            return n;
        }
    }
}
int main()
{
    cout << "Введите номер задания,которое хотите вывполнить" << '\n';
    int n;
    n = N_Checker();
    cin.ignore();
    switch (n)
    {
    case 1:
        Task_1();
        break;
    case 2:
        Task_2();
        break;
    case 3:
        Task_3();
        break;
    case 4:
        Task_4();
        break;
    case 5:
        Task_5();
        break;
    }
    return 0;
}
