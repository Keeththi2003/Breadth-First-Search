README.md

1. Student Information:
    - Name: K Keeththigan
    - Index No: 23000937
    - Registration Number: 2023cs093
    - Email: keeththi2003@gmail.com

2. Code Testing:
    - The code was tested on Linux.

3. How to Execute the Program:
    - Make sure the file `graph.txt` is available in the same directory as the program. 
    - The `graph.txt` file should contain the graph's data, including vertices, edges, and weights.
    - Compile the program using the following command:
      ```
      make build
      ```
    - Run the program using the following command:
      ```
      make run
      ```
    - Clean object files after excution using this following command:
      ```
      make clean
      ```

4. Special Notes:
    - This program implements a graph and performs a BFS traversal, calculates the total weight of the graph, and identifies unreachable nodes.
    - The graph is represented using an adjacency list, and the graph type (directed or undirected) is specified in the `graph.txt` file.
    - The program supports both directed and undirected graphs, as indicated by the input data in the file.
    - Ensure that the `graph.txt` file is correctly formatted as expected.
