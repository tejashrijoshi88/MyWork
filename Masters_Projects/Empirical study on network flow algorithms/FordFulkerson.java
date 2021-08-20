import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

public class FordFulkerson {

    private static final String INVALID_EDGE_CAPACITY = "Capacity on an edge cannot be negative";

    private Map<Vertex, Boolean> visitedMap;
    private Map<Vertex, Edge> destinationVertexEdgeMap;
    private SimpleGraph graph;

    public FordFulkerson(SimpleGraph graph) {

        this.graph = graph;
    }

    public double computeMaxFlow() {
        Vertex s = graph.getSourceVertex();
        Vertex t = graph.getSinkVertex();
        validateGraph(graph);
        double maxFlow = computeNetFlowInGraph(t);

        while (doesAugmentingPathExists(graph, s, t)) {

            // compute minimum capacity in augmenting path
            double minimumCapacity = computeMinimumCapacityInAugmentedPath(graph, s, t);

            // augment flow in original graph along the augmenting path
            augmentFlowInGraph(graph, s, t, minimumCapacity);

            maxFlow = maxFlow + minimumCapacity;
        }

        return maxFlow;
    }

    private void validateGraph(SimpleGraph graph) {
        for (Edge edge : graph.edgeList) {
            EdgeData edgeData = (EdgeData) edge.getData();
            if (edgeData.getCapacity() < 0) {
                System.out.println(INVALID_EDGE_CAPACITY);
                throw new IllegalArgumentException(INVALID_EDGE_CAPACITY);
            }
        }
    }

    private double computeNetFlowInGraph(Vertex t) {
        double netFlow = 0.0;
        for (Edge edge : t.incidentEdgeList) {
            EdgeData edgeData = (EdgeData) edge.getData();
            if (edge.getFirstEndpoint() == t) {
                netFlow = netFlow - edgeData.getFlow();
            } else {
                netFlow = netFlow + edgeData.getFlow();
            }
        }
        return netFlow;
    }

    private double computeMinimumCapacityInAugmentedPath(SimpleGraph graph, Vertex s, Vertex t) {
        double minimumCapacity = Double.MAX_VALUE;
        Vertex toVertex = t;
        while (toVertex != s) {
            Edge edge = destinationVertexEdgeMap.get(toVertex);
            minimumCapacity = Math.min(minimumCapacity, computeResidualCapacityToVertex(edge, toVertex));
            toVertex = getOppositeVertexForEdge(edge, toVertex, graph);
        }
        return minimumCapacity;
    }

    private void augmentFlowInGraph(SimpleGraph graph, Vertex s, Vertex t, double minimumCapacity) {
        Vertex toVertex = t;
        while (toVertex != s) {
            Edge edge = destinationVertexEdgeMap.get(toVertex);
            addResidualFlowToVertex(edge, toVertex, minimumCapacity);
            toVertex = getOppositeVertexForEdge(edge, toVertex, graph);
        }
    }

    private Vertex getOppositeVertexForEdge(Edge edge, Vertex vertex, SimpleGraph graph) {
        return graph.opposite(vertex, edge);
    }

    private boolean doesAugmentingPathExists(SimpleGraph graph, Vertex s, Vertex t) {
        visitedMap = new HashMap<>();
        destinationVertexEdgeMap = new HashMap<>();
        Queue<Vertex> queue = new LinkedList<>();
        queue.add(s);
        visitedMap.put(s, Boolean.TRUE);

        while (!queue.isEmpty() && !isVisited(t)) {
            Vertex fromVertex = queue.poll();
            assert fromVertex != null;
            for (Edge edge : fromVertex.incidentEdgeList) {
                Vertex toVertex = graph.opposite(fromVertex, edge);
                if (computeResidualCapacityToVertex(edge, toVertex) > 0) {
                    if (!isVisited(toVertex)) {
                        visitedMap.put(toVertex, Boolean.TRUE);
                        destinationVertexEdgeMap.put(toVertex, edge);
                        queue.add(toVertex);
                    }
                }
            }
        }
        return isVisited(t);
    }

    private double computeResidualCapacityToVertex(Edge edge, Vertex vertex) {
        EdgeData edgeData = (EdgeData) edge.getData();

        if (vertex == edge.getFirstEndpoint()) {
            return edgeData.getFlow();
        }
        return edgeData.getCapacity() - edgeData.getFlow();
    }

    private void addResidualFlowToVertex(Edge edge, Vertex vertex, double residualFlow) {
        EdgeData edgeData = (EdgeData) edge.getData();

        if (vertex == edge.getFirstEndpoint()) {
            edgeData.setFlow(edgeData.getFlow() - residualFlow);
        } else {
            edgeData.setFlow(edgeData.getFlow() + residualFlow);
        }
    }

    private boolean isVisited(Vertex vertex) {

        return visitedMap.getOrDefault(vertex, false);

    }
}
