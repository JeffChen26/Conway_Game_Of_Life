# Conway_Game_Of_Life
Conway’s Game Of Life algorithm in C++. The Game Of Life is a cellular automaton algorithm. It runs on a universe, which is two-dimensional a grid of cells. Each cell can be in two states: alive or dead. There is an initial state for the universe, which defines alive cells and their positions in the universe. The automaton progresses one step at a time by applying a set of rules to each cell in the universe. There rules are the following: 
1. Any live cell with two or three live neighbors survives;
2. Any dead cell with exactly three live neighbors becomes a live cell;
3. All other live cells die in the next generation. Similarly, all other dead cells stay dead.

Running glider.exe runs the glider pattern, which continues indefinitely until it reaches the end of the grid.
Running conway.exe allows a universe to be loaded and saved to and from a .txt file, of which glider.txt and glidergun.txt have been provided as examples.
