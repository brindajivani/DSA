#include <iostream>
using namespace std;

struct Team
{
    int id;
    int score;
    int rank;
};

void sortRank(Team a[], int n)
{
    int i, j;
    Team temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j].score < a[j + 1].score ||
              (a[j].score == a[j + 1].score &&
               a[j].id > a[j + 1].id))
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
        a[i].rank = i + 1;
}

void sortID(Team a[], int n)
{
    int i, j;
    Team temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j].id > a[j + 1].id)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int linearSearch(Team a[], int n, int id, int *count)
{
    int i;

    *count = 0;

    for(i = 0; i < n; i++)
    {
        (*count)++;

        if(a[i].id == id)
            return i;
    }

    return -1;
}

int binarySearch(Team a[], int n, int id, int *count)
{
    int low = 0;
    int high = n - 1;
    int mid;

    *count = 0;

    while(low <= high)
    {
        mid = (low + high) / 2;

        (*count)++;

        if(a[mid].id == id)
            return mid;

        if(id < a[mid].id)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    Team teams[100], search[100];

    int n, q;
    int i, j;
    int id;
    int pos1, pos2;
    int total1 = 0, total2 = 0;
    int c1, c2;

    cout << "Enter number of teams: ";
    cin >> n;

    if(n <= 0 || n > 100)
    {
        cout << "Invalid number of teams.\n";
        return 0;
    }

    cout << "Enter Team_ID and Score for each team:\n";

    for(i = 0; i < n; i++)
    {
        cin >> teams[i].id >> teams[i].score;
        search[i] = teams[i];
    }

    /* Create ranking */
    sortRank(teams, n);

    cout << "\nRanked List:\n";

    for(i = 0; i < n; i++)
    {
        cout << "Rank " << teams[i].rank
             << ": Team_ID " << teams[i].id
             << ", Score " << teams[i].score << endl;
    }

    cout << "\nRepeated Scores:\n";

    bool found = false;

    for(i = 0; i < n; i++)
    {
        int count = 1;

        for(j = i + 1; j < n; j++)
        {
            if(teams[i].score == teams[j].score)
                count++;
        }

        if(count > 1)
        {
            cout << "Score " << teams[i].score
                 << " -> " << count << " teams" << endl;

            found = true;
        }
        while(i + 1 < n &&
              teams[i].score == teams[i + 1].score)
        {
            i++;
        }
    }

    if(!found)
        cout << "No repeated scores.\n";

    sortID(search, n);

    cout << "\nEnter number of queries: ";
    cin >> q;

    for(i = 0; i < q; i++)
    {
        cout << "\nEnter Team_ID: ";
        cin >> id;

        pos1 = linearSearch(teams, n, id, &c1);
        pos2 = binarySearch(search, n, id, &c2);

        total1 += c1;
        total2 += c2;

        if(pos1 != -1)
        {
            cout << "Team_ID: " << id << endl;
            cout << "Score: " << teams[pos1].score << endl;
            cout << "Final Rank: " << teams[pos1].rank << endl;
        }
        else
        {
            cout << "Team_ID " << id << " not found.\n";
        }

        cout << "Linear Search Comparisons: "
             << c1 << endl;

        cout << "Binary Search Comparisons: "
             << c2 << endl;
    }

    cout << "\nTotal comparisons in Linear Search: "
         << total1 << endl;

    cout << "Total comparisons in Binary Search: "
         << total2 << endl;

    if(total1 < total2)
        cout << "Linear Search is better.\n";
    else if(total1 > total2)
        cout << "Binary Search is better.\n";
    else
        cout << "Both are equally efficient.\n";

    return 0;
}