package distributedSystem.keyvaluestore;

import java.io.*;
import java.net.*;
import java.util.ArrayList;

public class TCPServer {
	static ServerSocket serverSocket;
	private Socket tcpClientSocket;
	private int port;
	static ArrayList<InetAddress> NodeList = new ArrayList<InetAddress>();

	public TCPServer(int port) throws Exception {
		this.port = port;
		TCPServer.serverSocket = new ServerSocket(0, 1, InetAddress.getLocalHost());
	}

	public void tcpListen() throws Exception {

		try {
			serverSocket = new ServerSocket(this.port);
			System.out.println("Server is listening on port: " + this.port);
			/*
			 * for (int i = 0; i < NodeList.size(); i++) {
			 * System.out.println(NodeList.get(i)); }
			 */
			while (true) {
				tcpClientSocket = serverSocket.accept();
				//String clientIpAddress = tcpClientSocket.getInetAddress().getHostAddress();
				
				// multithreading
				ServerClientThread sct = new ServerClientThread(tcpClientSocket);
				Thread t = new Thread(sct);
				t.start();
			}
		} catch (IOException e) {
			System.out.println("Server exception: " + e.getMessage());
			e.printStackTrace();
		} finally {
			if (serverSocket != null)
				try {
					serverSocket.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
		}

	}

	private static class ServerClientThread extends Thread {
		private final Socket clientSocket;
		String data = null;
		OutputStream output = null;
		PrintWriter writer = null;
		BufferedReader input = null;
		static Coordinator node = null;

		public ServerClientThread(Socket clientSocket) {
			this.clientSocket = clientSocket;
		}

		public void run() {
			try {

				output = clientSocket.getOutputStream();
				writer = new PrintWriter(output, true); // send data to client.
				input = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

				while (true) {
					data = input.readLine();
					
					// String operation = data;
					node = new Coordinator(this.clientSocket);

					// Calling StoreData class to parse the received input from client.
					String serverResponse = StoreData.response_check(data);
					if (serverResponse.equals("exit")) {
						writer.println("Bye");
						serverSocket.close();
					}
					// calling coordinator class for put and delete commands.
					if ((serverResponse.equalsIgnoreCase("Call Coordinator"))) {
						node.check_node(data);
					}
					writer.println(serverResponse);
				}

			} catch (IOException e) {
				System.err.println("IOException:  " + e);
			} catch (Exception e) {
				System.out.println("check-node throwed Exception");
				e.printStackTrace();
			}
		}

	}
}
