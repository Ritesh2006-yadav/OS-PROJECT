# OS-PROJECT
We are working on Efficient page replacement algorithm simulator

This project is a simulation tool designed to demonstrate how different Page Replacement Algorithms work in an operating system’s virtual memory management.The simulator visualizes page faults, frame updates, and the overall performance of each algorithm, helping students and developers clearly understand the internal workings of paging.

FIFO Page Replacement Algorithm

The program simulates the FIFO page replacement algorithm. It loads pages into memory frames in the order they arrive. When a new page must be inserted, the oldest page is replaced using a circular pointer. After each request, frame status is printed, and total page faults are counted and displayed.
