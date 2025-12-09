# OS-PROJECT
We are working on Efficient page replacement algorithm simulator

This project is a simulation tool designed to demonstrate how different Page Replacement Algorithms work in an operating system’s virtual memory management.The simulator visualizes page faults, frame updates, and the overall performance of each algorithm, helping students and developers clearly understand the internal workings of paging.

FIFO Page Replacement Algorithm

The program simulates the FIFO page replacement algorithm. It loads pages into memory frames in the order they arrive. When a new page must be inserted, the oldest page is replaced using a circular pointer. After each request, frame status is printed, and total page faults are counted and displayed.

Least Recently Used Algorithm

The program implements the LRU page replacement algorithm. It tracks how recently each frame was used using a time counter. When a page fault occurs, the page with the oldest last-used time is replaced. Each step prints the current frames, and the total number of page faults is displayed.
