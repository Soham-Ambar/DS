#include <iostream>
using namespace std;

#define MAX 100
#define INF 9999

class Graph
{
    int adjMatrix[MAX][MAX];
    int numVertices;

public:
    Graph()
    {
        numVertices = 0;
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                adjMatrix[i][j] = 0;
    }

    void createGraph(int v)
    {
        numVertices = v;
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
                adjMatrix[i][j] = 0;
    }

    void addEdge(int src, int dest, int weight)
    {
        if (src >= numVertices || dest >= numVertices || src < 0 || dest < 0)
        {
            cout << "Invalid edge!\n";
            return;
        }
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight; // For undirected graph
    }

    void dijkstra(int startVertex)
    {
        int distance[MAX];
        bool visited[MAX];

        for (int i = 0; i < numVertices; i++)
        {
            distance[i] = INF;
            visited[i] = false;
        }

        distance[startVertex] = 0;

        for (int count = 0; count < numVertices - 1; count++)
        {
            int minDistance = INF, minIndex;

            for (int v = 0; v < numVertices; v++)
            {
                if (!visited[v] && distance[v] <= minDistance)
                {
                    minDistance = distance[v];
                    minIndex = v;
                }
            }

            int u = minIndex;
            visited[u] = true;

            for (int v = 0; v < numVertices; v++)
            {
                if (!visited[v] && adjMatrix[u][v] &&
                    distance[u] != INF &&
                    distance[u] + adjMatrix[u][v] < distance[v])
                {
                    distance[v] = distance[u] + adjMatrix[u][v];
                }
            }
        }

        // Print shortest distances
        cout << "Vertex\tDistance from Source " << startVertex << "\n";
        for (int i = 0; i < numVertices; i++)
            cout << i << "\t" << distance[i] << "\n";
    }
};

// ===== Menu Driven Main Function =====
int main()
{
    Graph g;
    int choice, v, src, dest, weight, start;

    while (true)
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Create Graph\n";
        cout << "2. Add Edge\n";
        cout << "3. Find Shortest Path (Dijkstra)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number of vertices: ";
            cin >> v;
            g.createGraph(v);
            cout << "Graph created with " << v << " vertices.\n";
            break;

        case 2:
            cout << "Enter source, destination and weight: ";
            cin >> src >> dest >> weight;
            g.addEdge(src, dest, weight);
            cout << "Edge added.\n";
            break;

        case 3:
            cout << "Enter starting vertex: ";
            cin >> start;
            g.dijkstra(start);
            break;

        case 0:
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}