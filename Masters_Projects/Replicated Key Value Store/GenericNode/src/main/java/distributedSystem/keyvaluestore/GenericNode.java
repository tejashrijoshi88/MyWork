package distributedSystem.keyvaluestore;

import java.io.IOException;

public class GenericNode {

	static String help_message = "Client:\r\n"
			+ "uc/tc <address> <port> put <key> <msg> UDP/TCP CLIENT: Put an object into\r\n" + "store\r\n"
			+ "uc/tc <address> <port> get <key> UDP/TCP CLIENT: Get an object from store by\r\n" + "key\r\n"
			+ "uc/tc <address> <port> del <key> UDP/TCP CLIENT: Delete an object from store\r\n" + "by key\r\n"
			+ "uc/tc <address> <port> store UDP/TCP CLIENT: Display object store\r\n"
			+ "uc/tc <address> <port> exit UDP/TCP CLIENT: Shutdown server \r\n" + "Server:\r\n"
			+ "us/ts <port> UDP/TCP/TCP-and-UDP SERVER: run server on <port>.\r\n"
			+ "tus <tcpport> <udpport> TCP-and-UDP SERVER: run servers on <tcpport> and\r\n"
			+ "<udpport> sharing same key-value store.\r\n"
			+ "alls <tcpport> <udpport> TCP, UDP, and RMI SERVER: run servers on <tcpport>\r\n"
			+ "and <udpport> sharing same key-value store.";

	public static void main(String[] args) throws Exception {

		String service = null;

		if (args.length < 1)
			System.out.println(help_message);
		else
			service = args[0].toString();

		// read command line input
		if (service.equalsIgnoreCase("ts")) {
			TCPServer server = new TCPServer(Integer.parseInt(args[1]));
			// to start UDP Broadcast Membership Tracking System

			try {
				broadcast_server.BroadCast();
			} catch (IOException e) {
				e.printStackTrace();
			}

			server.tcpListen();

		} else if (service.equalsIgnoreCase("tc")) {
			TCPClient client = new TCPClient(args[1], Integer.parseInt(args[2]));
			client.start(mkString(args));
		} else if (service.equalsIgnoreCase("us")) {
			UDPServer server = new UDPServer(Integer.parseInt(args[1]));
			server.udpListen();
		} else if (service.equalsIgnoreCase("uc")) {
			UDPClient client = new UDPClient(args[1], Integer.parseInt(args[2]));
			client.start(mkString(args));
		} else if (service.equalsIgnoreCase("rmis")) {
			RMIServer rmiserver = new RMIServer();
			rmiserver.listen(5009);
		} else if (service.equalsIgnoreCase("rmic")) {
			RMIClient rmiclient = new RMIClient(args[1]);
			rmiclient.start(mkString(args));
		} else
			System.out.println("Invalid input : " + help_message);

	}

	private static String mkString(String[] arr) {
		String s = "";
		if (arr[0].equals("rmic")) {
			for (int i = 2; i < arr.length; i++) {
				s = s + arr[i] + " ";
			}
		} else if (arr.length > 3) {
			if (arr[3].equalsIgnoreCase("put") || arr[3].equals("get") || arr[3].equals("exit")
					|| arr[3].equalsIgnoreCase("store") || arr[3].equals("del")) {
				for (int i = 3; i < arr.length; i++) {
					s = s + arr[i] + " ";
				}
			}
		}
		if (s.isEmpty()) {
			System.out.println(help_message);
		}
		return s;
	}
}
