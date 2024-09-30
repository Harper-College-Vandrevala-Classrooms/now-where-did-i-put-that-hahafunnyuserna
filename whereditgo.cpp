#include <iostream>
#include <string>

using namespace std;

bool checkCase(string input)
{
    while (input != "Y" && input != "y" && input != "N" && input != "n")
    {
        cout << "Do you want to check for casing? (Y/N)\n";
        cin >> input;
        if (input != "Y" && input != "y" && input != "N" && input != "n")
        {
            cout << "ERROR: Must be a valid Y/N answer.\n";
        }
    }

    if (input == "Y" || input == "y")
    {
        return true;
    }

    return false;
}

int startPos(int input, int l1, int l2)
{
    input = 2147483647;
    while (input < 0 || input > l1 || input > l2)
    {
        cout << "Please enter the number position you want to start from:\n";
        cin >> input;
        if (input < 0 || input > l1 || input > l2)
        {
            cout << "ERROR: Must be a valid position.\n";
        } else if (input > 0 && input < l1 && input < l2) {
            break;
        }
    }

    return input;
}

void findThing(int start, string big, string small)
{
    for (int i = start; i < big.length(); i++)
    {
        int j;
        for (j = 0; j < small.length(); j++)
        {
            if (big[i + j] != small[j])
            {
                break;
            }
        }

        if (j == small.length())
        {
            start = i;
        }
    }

    cout << "The string returns at position " << start << ".\n";
}

void findThing(int start, string big, char small)
{
    for (int i = start; i < big.length(); i++)
    {
        if (big[i] = small)
        {
            break;
        }

        start = i;
    }

    cout << "The char returns at position " << start << ".\n";
}

int main(void)
{
    string toSearch;
    string searchStr;
    char searchCar;
    int beginning;

    int smalLength = searchStr.length();
    int hugeLength = toSearch.length();
    
    bool checkCap;
    string capTemp;

    cout << "Please enter phrase you want to search:\n";
    getline(cin, toSearch);
    cout << "Please enter a phrase to search for:\n";
    getline(cin, searchStr);
    
    beginning = startPos(beginning, hugeLength, smalLength);

    bool caseSense = checkCase(capTemp);

    if (caseSense == 0)
    {
        for (int i = 0; i < hugeLength; i++)
        {
            toupper(toSearch[i]);
        }

        for (int i = 0; i < smalLength; i++)
        {
            toupper(searchStr[i]);
        }
    }

    if (searchStr.length() == 1)
    {
        searchCar = searchStr[0];
        findThing(beginning, toSearch, searchCar);
    } else {
        findThing(beginning, toSearch, searchStr);
    }
}