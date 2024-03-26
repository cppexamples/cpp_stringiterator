#include <string>
#include <iostream>

using namespace std;

bool isNumber(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}


bool myless(string a, string b)
{
    auto aux = [&](const string::iterator ai, const string::iterator bi, int prev, auto &aux_ref) -> bool
    {
        const string::iterator &aend = a.end();
        const string::iterator &bend = b.end();

        if (ai == aend && bi == bend)
            return (prev == -1) ? true : false;
        if (ai == aend && bi < bend)
            return true;
        if (ai < aend && bi == bend)
            return false;

        const string::iterator anxt = std::next(ai);
        const string::iterator bnxt = std::next(bi);
        bool anm = isNumber(*ai);
        bool bnm = isNumber(*bi);

        if (anm && bnm && *ai < *bi)  return aux_ref(anxt, bnxt, (prev == 0) ? -1 : prev, aux_ref);
        if (anm && bnm && *ai > *bi)  return aux_ref(anxt, bnxt, (prev == 0) ? 1 : prev, aux_ref);
        if (anm && bnm && *ai == *bi) return aux_ref(anxt, bnxt, prev, aux_ref);
        if (anm && !bnm) return false; // 1234 123b
        if (!anm && bnm) return true; // 123b 1234
        if (*ai < *bi) return true;
        if (*ai > *bi) return false;
        return aux_ref(anxt, bnxt, prev, aux_ref);
    };
    return aux(a.begin(), b.begin(), 0, aux);
}


int main(int argc, char *argv[])
{
    std::cout << boolalpha << endl
              << myless("123", "1234") << endl;
}