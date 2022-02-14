package distributedSystem.keyvaluestore;

import java.rmi.registry.Registry;
import java.net.InetAddress;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;

public class RMIServer {

	String address;
	Registry registry;

	public RMIServer() throws RemoteException {
		try {
			address = (InetAddress.getLocalHost()).toString();
		} catch (Exception e) {
			System.out.println("can't get inet address.");
			e.printStackTrace();
		}
	}

	public void listen(int port) throws Exception {
		try {
			registry = LocateRegistry.createRegistry(port);
		} catch (Exception e) {
			System.err.println("Server exception: " + e.toString());
			e.printStackTrace();
		}
		registry.rebind("rmiServer", new SearchQuery());
		System.err.println("Server ready");
	}
	

	
}
