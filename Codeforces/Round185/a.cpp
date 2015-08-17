#include <iostream>

#include <string>
using namespace std;

int main()
{
    int ncase;

    cin >> ncase;
    cin.get();
    string sen;

    for(int i = 0;i < ncase;i++)
    {
        getline(cin, sen, '\n');
        if (sen.size() < 5)
            cout << "OMG>.< I don't know!" << endl;
        else
        {
            int r = 0, f = 0;
            if (sen.substr(0, 5) == "miao.")
                r = 1;
            if (sen.substr(sen.size() - 5, 5) == "lala.")
                f = 1;

            if (r == f)
                cout << "OMG>.< I don't know!" << endl;
            else
            {
                if (r == 1)
                    cout << "Rainbow's" << endl;
                else
                    cout << "Freda's" << endl;
            }
        }
    }
    return 0;
}
