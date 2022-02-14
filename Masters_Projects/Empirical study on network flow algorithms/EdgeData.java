public class EdgeData {

    private double capacity;
    private double flow;

    public EdgeData(double capacity) {
        this.flow = 0.0;
        this.capacity = capacity;
    }

    /**
     * Return the data associated with this edge.
     *
     * @return the data of this edge
     */
    public double getCapacity() {

        return this.capacity;
    }

    /**
     * Set the data associated with this edge.
     *
     */
    public void setCapacity(double capacity) {

        this.capacity = capacity;
    }

    /**
     * Return the flow associated with this edge.
     *
     * @return the flow of this edge
     */
    public double getFlow() {

        return this.flow;
    }

    /**
     * Set the flow associated with this edge.
     *
     */
    public void setFlow(double flow) {

        this.flow = flow;
    }

}
