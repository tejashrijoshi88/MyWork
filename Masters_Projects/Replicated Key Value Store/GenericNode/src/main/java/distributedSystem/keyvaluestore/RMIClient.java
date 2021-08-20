package distributedSystem.keyvaluestore;


import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class RMIClient {

	private String serverAddress;
	private int port = 5009;

	public RMIClient(String serverAddress) {
		this.serverAddress = serverAddress;
		
	}

	public void start(String s) {
		System.out.println("Sending data " + s + " to server " + this.serverAddress + ":" +this.port);
		try {
			Registry registry = LocateRegistry.getRegistry(this.serverAddress,this.port);
			Search stub = (Search) registry.lookup("rmiServer");
			new Thread(new RmiClientThread(s, stub)).start();
		} catch (RemoteException e) {
			System.err.println("Client RemoteException: " + e.toString());
			e.printStackTrace();
		} catch (NotBoundException ex) {
			System.err.println(ex);
		}
	}

	private class RmiClientThread implements Runnable {
		private final Search search;
		private String message = null;

		RmiClientThread(String message, Search stub) throws RemoteException {
			this.search = stub;
			this.message = message;
		}

		public void run() {
			try {
				String response = this.search.query(message);
				if (response.equals("exit")) {
					System.out.println("Closing Client...");
					response = "Bye";
				}
				System.out.println("Server Response: " + response);
			} catch (RemoteException e) {
				e.printStackTrace();
			}
		}
	}

}
