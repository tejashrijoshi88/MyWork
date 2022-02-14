import java.util.*;

public class PreflowPushRelabel {

    private static final String INVALID_EDGE_CAPACITY = "Capacity on an edge cannot be negative";

    private Queue<Vertex> excessQueue;
    private Vertex s, t;
    private SimpleGraph graph;

    public PreflowPushRelabel(SimpleGraph graph) {

        this.graph = graph;
    }

    public double computeMaxFlow() {
        s = graph.getSourceVertex();
        t = graph.getSinkVertex();

        validateGraph(graph);

        initialize(graph);

        while (!excessQueue.isEmpty()) {

            Vertex vertex = excessQueue.poll();
            assert vertex != null;
            VertexData vertexData = (VertexData) vertex.getData();

            while (vertexData.getExcess() > 0 && vertex != t) {
                if (!pushFlowIfApplicable(vertex, graph)) {

                    relabelVertexHeight(vertex, graph);
                }
            }
        }
        VertexData sinkVertexData = (VertexData) t.getData();
        return sinkVertexData.getExcess();
    }

    private void initialize(SimpleGraph graph) {

        // Initialize height for source
        VertexData vertexData = (VertexData) s.getData();
        vertexData.setHeight(graph.numVertices());

        // Initialize edge flows on edges incident on s, excess flows for adjacent nodes
        excessQueue = new LinkedList<>();
        for (Edge edge : s.incidentEdgeList) {

            EdgeData edgeData = (EdgeData) edge.getData();
            edgeData.setFlow(edgeData.getCapacity());

            Vertex otherVertex = graph.opposite(s, edge);
            VertexData otherVertexData = (VertexData) otherVertex.getData();
            otherVertexData.setExcess(edgeData.getCapacity());

            excessQueue.add(otherVertex);
        }
    }

    private boolean pushFlowIfApplicable(Vertex vertex, SimpleGraph graph) {
        boolean isPushApplicable = false;
        VertexData vertexData = (VertexData) vertex.getData();

        for (Edge edge : vertex.incidentEdgeList) {
            isPushApplicable = false;
            Vertex otherVertex = graph.opposite(vertex, edge);
            VertexData otherVertexData = (VertexData) otherVertex.getData();

            /*
             * Checks if the edge exists in residual graph
             *
             * Possible Cases:
             *  1. Edges with partial flow in original graph
             *  2. Edges with zero flow in original graph
             *  3. Edges with flow = capacity in original graph do not appear in residual graph
             */
            if (computeResidualCapacityToVertex(edge, otherVertex) > 0) {

                if (vertexData.getHeight() > otherVertexData.getHeight()) {

                    double deltaFlow = Math.min(vertexData.getExcess(),
                            computeResidualCapacityToVertex(edge, otherVertex));
                    addResidualFlowToVertex(edge, otherVertex, deltaFlow);

                    // adjust excess on vertices of the edge
                    vertexData.setExcess(vertexData.getExcess() - deltaFlow);
                    otherVertexData.setExcess(otherVertexData.getExcess() + deltaFlow);

                    if (otherVertex != t && otherVertex != s) {
                        excessQueue.add(otherVertex);
                    }

                    isPushApplicable = true;
                }
            }
        }
        return isPushApplicable;
    }

    private void relabelVertexHeight(Vertex vertex, SimpleGraph graph) {
        VertexData vertexData = (VertexData) vertex.getData();

        for (Edge edge : vertex.incidentEdgeList) {
            Vertex otherVertex = graph.opposite(vertex, edge);
            VertexData otherVertexData = (VertexData) otherVertex.getData();

            // Checks if the edge from vertex to otherVertex exists in residual graph
            if (computeResidualCapacityToVertex(edge, otherVertex) > 0) {

                if (otherVertexData.getHeight() < vertexData.getHeight()) {
                    return;
                }
            }
        }
        vertexData.setHeight(vertexData.getHeight() + 1);
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

}
