import java.io.File;

public class tcss543 {

    private static final int ITERATIONS = 10;

    public static void main(String[] args) {

        double maxFlow = 0.0;
        long startTime;
        File file = new File(args[0]);
        String filePath = file.getAbsolutePath();
        System.out.println("Opened " + filePath + " for input. \n");

        // Max-Flow using Ford-Fulkerson
        SimpleGraph graph1;
        startTime = System.nanoTime();
        for (int i = 0; i < ITERATIONS; i++) {
            graph1 = new SimpleGraph();
            GraphInput.LoadSimpleGraph(graph1, filePath);
            FordFulkerson fordFulkerson = new FordFulkerson(graph1);
            maxFlow = fordFulkerson.computeMaxFlow();
        }
        System.out.println("Max Flow using Ford-Fulkerson : " + maxFlow);
        System.out.println("Time taken : " + ((System.nanoTime() - startTime) / ITERATIONS) / 1000000 + "\n");


        // Max-Flow using Scaling Ford-Fulkerson
        SimpleGraph graph2;
        startTime = System.nanoTime();
        for (int i = 0; i < ITERATIONS; i++) {
            graph2 = new SimpleGraph();
            GraphInput.LoadSimpleGraph(graph2, filePath);
            ScalingFordFulkerson scalingFordFulkerson = new ScalingFordFulkerson(graph2);
            maxFlow = scalingFordFulkerson.computeMaxFlow();
        }
        System.out.println("Max flow using Scaling Ford-Fulkerson : " + maxFlow);
        System.out.println("Time taken : " + ((System.nanoTime() - startTime) / ITERATIONS) / 1000000 + "\n");


        // Max-Flow using Scaling Ford-Fulkerson
        SimpleGraph graph3;
        startTime = System.nanoTime();
        for (int i = 0; i < ITERATIONS; i++) {
            graph3 = new SimpleGraph();
            GraphInput.LoadSimpleGraph(graph3, filePath);
            PreflowPushRelabel pushRelabel = new PreflowPushRelabel(graph3);
            maxFlow = pushRelabel.computeMaxFlow();
        }
        System.out.println("Max flow using Preflow-PushRelabel : " + maxFlow);
        System.out.println("Time taken : " + ((System.nanoTime() - startTime) / ITERATIONS) / 1000000 + "\n");
    }
}
