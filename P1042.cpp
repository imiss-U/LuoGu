#include <iostream>
#include <cstdio>
using namespace std;
int length = 0;
void Elevent(string str)
{
    int i = 0;
    int a = 0, b = 0;
    while (i <= length)
    {
        if (str[i] == 'W')
            a++;
        else if(str[i] == 'L')
        {
            b++;
        }
        if (((a - b >= 2) || (b - a >= 2)) && (a >= 11 || b >= 11))
        {
            printf("%d:%d\n", a, b);
            a = 0;
            b = 0;
        }
        i++;
    }
    printf("%d:%d", a, b);
}
void Twenty_one(string str)
{
    int i = 0;
    int a = 0, b = 0;
    while (i <= length)
    {
        if (str[i] == 'W')
            a++;
        else if(str[i] == 'L')
            b++;
        if (((a - b >= 2) || (b - a >= 2)) && (a >= 21 || b >= 21))
        {
            printf("%d:%d\n", a, b);
            a = 0;
            b = 0;
        }
        i++;
    }
    printf("%d:%d", a, b);
}
string getstr()
{
    string result;
    char ch;
    while (cin >> ch && ch != 'E')
    {
        result += ch;
        length++;
    }
    return result;
}
int main()
{
    string str = getstr();
    Elevent(str);
    printf("\n\n");
    Twenty_one(str);
    return 0;
}