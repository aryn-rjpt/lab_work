#include <iostream>
#include <string>

using namespace std;

bool isPal(string s)
{
    bool ans = true;
    int len = s.length(), i = 0, j = len - 1;

    while (i < j)
    {
        if (s[i] != s[j])
        {
            ans = false;
            return ans;
        }
        i++, j--;
    }
    return ans;
}

int main()
{

    string s;
    cout << "Enter a string: ";
    cin >> s;

    bool ans = isPal(s);
    if (ans == true)
    {
        (cout << "Yes, it is a Palindrome" << endl);
    }
    else
    {
        (cout << "No, it is not a Palindrome" << endl);
    }
    return 0;
}