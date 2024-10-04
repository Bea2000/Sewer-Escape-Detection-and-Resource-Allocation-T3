# Sewer Escape Detection and Resource Allocation

## Overview

This project consists of two missions related to graph-based problems and dynamic programming, designed for the Data Structures and Algorithms course at the Pontifical Catholic University of Chile (2021, 1st semester). The goal is to model and solve problems involving graph traversal, optimization strategies, and resource allocation.

## Mission 1: Sewer Escape Detection

### Problem Context

Stuart Little is attempting to escape through a network of sewer tunnels, represented as a complete graph. The first mission is to reduce Stuart's mobility by determining the minimum cost to connect all sewer intersections (nodes) without isolating any locations. Additionally, balance the number of outgoing connections from each node to avoid issues in critical locations.

### Objectives

- Build a Minimum Spanning Tree (MST) for the graph.
- Minimize the number of outgoing connections (edges) from each node while maintaining the minimum total cost.

### How to Run the Program

1. Compile the program using:

   ```bash
   make
    ```

2. Run the executable with the following command:

    ```bash
    ./sewerrat input.txt output.txt
    ```

    - `input.txt`: The file containing the node locations.
    - `ouput.txt`: The file where the MST results will be stored.
  
### Input Format

The input file should have the following structure:

- The first line contains an integer `N`, representing the number of nodes.
- The next `N` lines contain two integers each, representing the coordinates of the nodes.

#### Example

```bash
6
1 5
2 5
7 7
1 1
3 3
7 3
```

### Output Format

The output file will contain:

- The total cost of the MST.
- `N-1` lines representing the edges between connected nodes, in the format: `x1 y1 x2 y2`, indicating an edge between points (`x1, y1)` and `(x2, y2)`.

#### Example

```bash
16
1 5 2 5
2 5 3 3
1 1 3 3
7 7 7 3
3 3 7 3
```

### Requirements

- Implement sorting and MST algorithms from scratch (no external libraries like qsort).
- The distance between nodes is the Manhattan distance: `d(a,b)=∣a1−b1∣+∣a2−b2∣`

## Mission 2: Resource Allocation for Agents

### Problem Context

In this mission, the program allocates a set of items, each with a specific weight, to the minimum number of agents, ensuring no agent carries more than their maximum capacity.

### Objectives

Use dynamic programming to distribute the items across agents, minimizing the number of agents used.
How to Run the Program

1. Compile the program using:

    ```bash
    make
    ```

2. Run the executable with the following command:

    ```bash
    ./agentbin input.txt output.txt
    ```

    - `input.txt`: The file containing the capacity of agents and the weight of items.
    - `ouput.txt`: The file where the allocation results will be stored.

### Input Format

The input file should have the following structure:

- The first line contains the integer `C`, representing the capacity of each agent.
- The second line contains the integer `N`, representing the number of items.
- The next `N` lines contain the weight of each item.

#### Example

```bash
4
9
2
1
2
1
1
2
3
2
1
```

### Output Format

The output file will contain:

An integer `Q`, representing the number of agents used.
`Q` lines, each listing the IDs of the items carried by each agent.

#### Example

```bash
5
0 1
2 3 4
5
6
7 8
```
