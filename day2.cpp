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

// ---------------- FIFO Algorithm ----------------
int fifo(int pages[], int n, int framesCount)
{
    int frames[50];
    int pageFaults = 0, pointer = 0;

    for (int i = 0; i < framesCount; i++)
        frames[i] = -1;

    cout << "\n--- FIFO Page Replacement ---\n";

    for (int i = 0; i < n; i++)
    {
        int page = pages[i];
        bool found = false;

        // Check if page already in frame
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
            frames[pointer] = page;
            pointer = (pointer + 1) % framesCount;
            pageFaults++;
        }

        printFrames(frames, framesCount);
    }

    return pageFaults;
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

// ---------------- Main Function ----------------
int main()
{
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
    cout << "FIFO: " << fifo(pages, n, framesCount) << endl;
    cout << "LRU: " << lru(pages, n, framesCount) << endl;
    cout << "Optimal: " << optimal(pages, n, framesCount) << endl;

    return 0;
}
