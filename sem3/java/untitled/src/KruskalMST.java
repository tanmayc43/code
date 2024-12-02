import java.util.*;

class Edge implements Comparable<Edge> {
    int src, dest, weight;

    public int compareTo(Edge other) {
        return this.weight - other.weight;
    }
}

class Node {
    Node parent;
    int rank;

    Node() {
        this.parent = this;
        this.rank = 0;
    }
}

public class KruskalMST {
    private int V;
    private List<Edge> edges;

    public KruskalMST(int V) {
        this.V = V;
        edges = new ArrayList<>();
    }

    public void addEdge(int src, int dest, int weight) {
        Edge edge = new Edge();
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.add(edge);
    }

    private Node find(Node node) {
        if (node.parent != node) {
            node.parent = find(node.parent);
        }
        return node.parent;
    }

    private void union(Node node1, Node node2) {
        Node root1 = find(node1);
        Node root2 = find(node2);

        if (root1 != root2) {
            if (root1.rank < root2.rank) {
                root1.parent = root2;
            } else if (root1.rank > root2.rank) {
                root2.parent = root1;
            } else {
                root2.parent = root1;
                root1.rank++;
            }
        }
    }

    public List<Edge> kruskalMST() {
        Collections.sort(edges);

        List<Edge> mst = new ArrayList<>();

        Node[] subsets = new Node[V];
        for (int i = 0; i < V; i++) {
            subsets[i] = new Node();
        }

        for (Edge edge : edges) {
            Node root1 = find(subsets[edge.src]);
            Node root2 = find(subsets[edge.dest]);

            if (root1 != root2) {
                mst.add(edge);
                union(root1, root2);
            }
        }

        return mst;
    }

    public void printMST(List<Edge> mst) {
        for (Edge edge : mst) {
            System.out.println("Edge: " + edge.src + " - " + edge.dest + " weight: " + edge.weight);
        }
    }

    public static void main(String[] args) {
        int V = 4;
        KruskalMST graph = new KruskalMST(V);

        graph.addEdge(0, 1, 57);
        graph.addEdge(0, 2, 61);
        graph.addEdge(0, 3, 55);
        graph.addEdge(1, 3, 15);
        graph.addEdge(2, 3, 40);

        List<Edge> mst = graph.kruskalMST();

        System.out.println("Minimum Spanning Tree:");
        graph.printMST(mst);
    }
}
