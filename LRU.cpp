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

// ---------------- LRU Algorithm ----------------
int lru(int pages[], int n, int framesCount)
{
    int frames[50], lastUsed[50];
    int pageFaults = 0, time = 0;

    for (int i = 0; i < framesCount; i++)
    {
        frames[i] = -1;
        lastUsed[i] = -1;
    }

    cout << "\n--- LRU Page Replacement ---\n";

    for (int i = 0; i < n; i++)
    {
        int page = pages[i];
        time++;
        bool found = false;

        for (int j = 0; j < framesCount; j++)
        {
            if (frames[j] == page)
            {
                found = true;
                lastUsed[j] = time;
                break;
            }
        }

        if (!found)
        {
            int lruIndex = 0;

            for (int j = 1; j < framesCount; j++)
            {
                if (lastUsed[j] < lastUsed[lruIndex])
                {
                    lruIndex = j;
                }
            }

            frames[lruIndex] = page;
            lastUsed[lruIndex] = time;
            pageFaults++;
        }

        printFrames(frames, framesCount);
    }

    return pageFaults;
}
int main (){
    int n, framesCount;
    int pages[100];

    cout << "Enter number of pages: ";
    cin >> n;

    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> framesCount;

    cout << "\nPage Faults:\n";
    cout << "LRU: " << lru(pages, n, framesCount) << endl;
}