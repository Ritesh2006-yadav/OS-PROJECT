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

    cout << "\nPage Faults:\n";
    cout << "FIFO: " << fifo(pages, n, framesCount) << endl;
}