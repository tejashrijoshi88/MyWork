package distributedSystem.keyvaluestore;

import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.List;

public class Coordinator {

	private static Socket clientSocket;
	static String key = null;
	static String value = null;
	static boolean inputFromAll = false;
	static List<String> response_check;
	static String[] response = null;
	static String command = null;
	OutputStream outputStream = null;
	PrintWriter printWriter = null;

	public Coordinator(Socket clientSocket) {
		Coordinator.clientSocket = clientSocket;
	}

	public void check_node(String command) throws Exception {
		Coordinator.command = command;
		// Reading command to get key and value
		response = command.split(" ");
		response_check = new ArrayList<String>();
		List<String> ips = new ArrayList<String>();
		outputStream = clientSocket.getOutputStream();
		printWriter = new PrintWriter(outputStream, true);
		try {
			// to start static configuration
			//StaticConfig.config();

			// Reading a list of IPs present in the network.
			for (int i = 0; i < TCPServer.NodeList.size(); i++) {
				String[] address = TCPServer.NodeList.get(i).toString().split("/");
				ips.add(address[1]);
			}
			MultithreadedKeyStoreCoordinator coordinator = new MultithreadedKeyStoreCoordinator();
			String operation = response[0];
			key = response[1];
			if (operation.equalsIgnoreCase("put"))
				value = response[2];
			if (!coordinator.checkIfLocked(operation, key, ips, value)) {
				printWriter.println(coordinator.editKey(operation, key, value, ips));
			} else {
				printWriter.println(coordinator.editKey("GLOBAL_ABORT".concat(" " + operation), key, value, ips));
			}
		} catch (IOException e) {
			System.err.println("IOException:  " + e);
			e.printStackTrace();
		} catch (InterruptedException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
			throw e;
		}

	}

}
