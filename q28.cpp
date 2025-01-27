#include "helpers.h"

int strStr(string haystack, string needle)
{
    if (haystack.length() == 0 || needle.length() == 0 || needle.length() > haystack.length())
    {
        return -1;
    }

    int i = 0, j = needle.length() - 1;

    while (j < haystack.length())
    {
        if (haystack[i] == needle[0] && haystack[j] == needle[needle.length() - 1])
        {
            // check in-between letters
            int start = i;
            int k = i + 1;

            while (k < j)
            {
                if (haystack[k] != needle[k - start])
                {
                    start = -1;
                    break;
                }
                k++;
            }

            if (start != -1)
                return start;
        }
        i++;
        j++;
    }

    return -1;
}

int main()
{
    cout << strStr("babba", "bbb") << endl;
}