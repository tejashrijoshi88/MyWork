JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	Edge.java \
	EdgeData.java \
	FordFulkerson.java \
	GraphInput.java \
	InputLib.java \
	KeyboardReader.java \
	PreflowPushRelabel.java \
	ScalingFordFulkerson.java \
	SimpleGraph.java \
	Vertex.java \
	VertexData.java \
	tcss543.java

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class
