#include <iostream>
#include <limits.h>
using namespace std;

// Function to print current frames
void printFrames(int frames[], int framesCount)
{
    for (int i = 0; i < framesCount; i++)
    {
        if (frames[i] == -1)
            cout << "- ";
        else
            cout << frames[i] << " ";
    }
    cout << endl;
}

// ---------------- Optimal Algorithm ----------------
int optimal(int pages[], int n, int framesCount)
{
    int frames[50];
    int pageFaults = 0;

    for (int i = 0; i < framesCount; i++)
        frames[i] = -1;

    cout << "\n--- Optimal Page Replacement ---\n";

    for (int i = 0; i < n; i++)
    {
        int page = pages[i];
        bool found = false;

        for (int j = 0; j < framesCount; j++)
        {
            if (frames[j] == page)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            int replaceIndex = -1, farthest = -1;

            for (int j = 0; j < framesCount; j++)
            {
                int nextUse = INT_MAX;

                for (int k = i + 1; k < n; k++)
                {
                    if (frames[j] == pages[k])
                    {
                        nextUse = k;
                        break;
                    }
                }

                if (nextUse > farthest)
                {
                    farthest = nextUse;
                    replaceIndex = j;
                }
            }

            frames[replaceIndex] = page;
            pageFaults++;
        }

        printFrames(frames, framesCount);
    }

    return pageFaults;
}
int main(){
    int n, framesCount;
    int pages[100];

    cout << "Enter number of pages: ";
    cin >> n;

    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> framesCount;
    cout << "Optimal: " << optimal(pages, n, framesCount) << endl;
}