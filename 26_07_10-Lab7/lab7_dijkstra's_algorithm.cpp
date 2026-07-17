#include <iostream>
#include <climits>
using namespace std;

struct EdgeNode
{
    int dest;
    int weight;
    EdgeNode *next;
    EdgeNode(int d, int w) : dest(d), weight(w), next(nullptr) {}
};

struct VertexNode
{
    int id;
    EdgeNode *edgeHead; // points to the vertex's first edge
    VertexNode *next;
    VertexNode(int id) : id(id), edgeHead(nullptr), next(nullptr) {}
};

class Graph
{
public:
    VertexNode *vertexHead;
    int V;

    Graph(int V) : vertexHead(nullptr), V(V)
    {
        VertexNode *prev = nullptr;
        for (int i = 0; i < V; i++)
        {
            VertexNode *newVertex = new VertexNode(i);
            if (!vertexHead)
                vertexHead = newVertex;
            else
                prev->next = newVertex;
            prev = newVertex;
        }
    }

    VertexNode *findVertex(int id)
    {
        VertexNode *cur = vertexHead;
        while (cur)
        {
            if (cur->id == id)
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    void addEdge(int u, int v, int w)
    {
        VertexNode *uNode = findVertex(u);
        VertexNode *vNode = findVertex(v);

        EdgeNode *node1 = new EdgeNode(v, w);
        node1->next = uNode->edgeHead;
        uNode->edgeHead = node1;

        EdgeNode *node2 = new EdgeNode(u, w);
        node2->next = vNode->edgeHead;
        vNode->edgeHead = node2;
    }
};

// Function that computes shortest distances from src to every vertex in graph g
void dijkstra(Graph &g, int src)
{
    int V = g.V; // total number of verties
    int *dist = new int[V];
    bool *visited = new bool[V];

    // Initialize every distance to "infinity" (INT_MAX = unknown/unreachable) and every vertex as unvisited
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0; // seed value

    // Main loop - process each vertex once
    for (int count = 0; count < V; count++)
    {

        // find the unvisited vertex with the smallest dist (linear search)
        int minDist = INT_MAX;
        int u = -1;
        for (int i = 0; i < V; i++)
        { // vertex i hasn't been visited yet, AND it's closer than the best candidate found so far
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break; // remaining vertices are unreachable

        visited[u] = true;

        VertexNode *uNode = g.findVertex(u);
        for (EdgeNode *edge = uNode->edgeHead; edge != nullptr; edge = edge->next)
        {
            int v = edge->dest;
            int w = edge->weight;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 0; i < V; i++)
        cout << dist[i] << " ";
    cout << "\n";

    delete[] dist;
    delete[] visited;
}

int main()
{
    Graph g(5);         // 5 vertices
    g.addEdge(0, 1, 4); // edge between vertex 0 and vertex 1, weight 4
    g.addEdge(0, 2, 8);
    g.addEdge(1, 4, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 10);

    /*
               (0)
               /  \
              4    8
             /      \
          (1)----3----(2)
           |            |
           6            2
           |            |
          (4)----------(3)
                 10
    */

    dijkstra(g, 0);
    return 0;
}