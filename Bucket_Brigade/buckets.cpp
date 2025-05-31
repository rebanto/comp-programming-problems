#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("buckets.in");
    ofstream fout("buckets.out");

    pair<int, int> barn, lake, rock;

    char farm[10][10];
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            fin >> farm[i][j];
        }
    }

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (farm[i][j] == 'B')
                barn = {i, j};
            else if (farm[i][j] == 'L')
                lake = {i, j};
            else if (farm[i][j] == 'R')
                rock = {i, j};
        }
    }

    int dist = abs(barn.first - lake.first) + abs(barn.second - lake.second) - 1;

    if ((barn.first == lake.first && barn.first == rock.first &&
         ((rock.second > min(barn.second, lake.second)) && (rock.second < max(barn.second, lake.second)))) ||
        (barn.second == lake.second && barn.second == rock.second &&
         ((rock.first > min(barn.first, lake.first)) && (rock.first < max(barn.first, lake.first)))))
    {
        dist += 2;
    }

    fout << dist;

    return 0;
}