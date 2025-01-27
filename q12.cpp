#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string intToRoman(int num)
{
    vector<pair<int, string>> symbols{
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
    };

    string ans = "";

    for (auto [value, sym] : symbols)
    {
        if (num == 0)
            break;

        while (num >= value)
        {
            ans += sym;
            num -= value;
        }
    }

    return ans;
}

int main()
{
    cout << "3749: " << intToRoman(3749) << endl;
    cout << "58: " << intToRoman(58) << endl;
    cout << "1994: " << intToRoman(1994) << endl;
    return 0;
}