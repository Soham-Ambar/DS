#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define SIZE 11

// ===== Graph using Adjacency Matrix =====
class Graph
{
public:
    int numVertices;
    vector<vector<int>> adjMatrix;
    vector<bool> visited;

    Graph(int vertices)
    {
        numVertices = vertices;
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
        visited.resize(vertices, false);
    }

    void addEdge(int src, int dest)
    {
        if (src >= 0 && dest >= 0 && src < numVertices && dest < numVertices)
        {
            adjMatrix[src][dest] = 1;
            adjMatrix[dest][src] = 1;
        }
    }

    void DFS(int vertex)
    {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int i = 0; i < numVertices; i++)
        {
            if (adjMatrix[vertex][i] == 1 && !visited[i])
                DFS(i);
        }
    }

    void BFS(int startVertex)
    {
        fill(visited.begin(), visited.end(), false);
        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty())
        {
            int currentVertex = q.front();
            q.pop();
            cout << currentVertex << " ";

            for (int i = 0; i < numVertices; i++)
            {
                if (adjMatrix[currentVertex][i] == 1 && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void resetVisited()
    {
        fill(visited.begin(), visited.end(), false);
    }
};

// ===== HashTable (No changes needed) =====
class HashTable
{
private:
    int table[SIZE][2];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i][0] = -1;
            table[i][1] = -1;
        }
    }

    int hashFunction(int key)
    {
        return key % SIZE;
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        int i = index;
        int attempts = 0;

        while (attempts < SIZE)
        {
            if (table[i][0] == -1)
            {
                table[i][0] = key;
                cout << "Key " << key << " inserted at row " << i << ", column 0.\n";
                return;
            }
            else if (table[i][1] == -1)
            {
                table[i][1] = key;
                cout << "Key " << key << " inserted at row " << i << ", column 1.\n";
                return;
            }
            i = (i + 1) % SIZE;
            attempts++;
        }
        cout << "Hash Table Overflow\n";
    }

    void display()
    {
        cout << "Hash Table:\n";
        for (int i = 0; i < SIZE; i++)
        {
            cout << "Row " << i << ": [" << table[i][0] << ", " << table[i][1] << "]\n";
        }
    }
};

// ===== Main Menu (Same) =====
int main()
{
    Graph *graph = nullptr;
    HashTable hashTable;
    int choice, v, src, dest, start;

    while (true)
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Create Graph\n";
        cout << "2. Add Edge\n";
        cout << "3. DFS\n";
        cout << "4. BFS\n";
        cout << "5. Insert in Hash Table (2 Columns)\n";
        cout << "6. Display Hash Table\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number of vertices: ";
            cin >> v;
            delete graph;
            graph = new Graph(v);
            cout << "Graph created with " << v << " vertices.\n";
            break;
        case 2:
            if (!graph)
            {
                cout << "Create a graph first!\n";
                break;
            }
            cout << "Enter source and destination: ";
            cin >> src >> dest;
            graph->addEdge(src, dest);
            cout << "Edge added!\n";
            break;
        case 3:
            if (!graph)
            {
                cout << "Create a graph first!\n";
                break;
            }
            graph->resetVisited();
            cout << "Enter starting vertex for DFS: ";
            cin >> start;
            cout << "DFS: ";
            graph->DFS(start);
            cout << "\n";
            break;
        case 4:
            if (!graph)
            {
                cout << "Create a graph first!\n";
                break;
            }
            cout << "Enter starting vertex for BFS: ";
            cin >> start;
            cout << "BFS: ";
            graph->BFS(start);
            cout << "\n";
            break;
        case 5:
            cout << "Enter element to insert in hash table: ";
            cin >> src;
            hashTable.insert(src);
            break;
        case 6:
            hashTable.display();
            break;
        case 0:
            delete graph;
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}
