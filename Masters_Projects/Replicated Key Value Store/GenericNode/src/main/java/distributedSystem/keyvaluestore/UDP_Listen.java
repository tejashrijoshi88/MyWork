package distributedSystem.keyvaluestore;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.util.TimerTask;

public class UDP_Listen extends TimerTask {
	private static DatagramSocket socket;

	public UDP_Listen(DatagramSocket udpServerSocket) throws IOException {
		socket = udpServerSocket;
	}

	public static void Create_Node_List() throws IOException {
		byte[] receive = new byte[65535];

		InetAddress ServerAddress;
		LocalDateTime then = LocalDateTime.now();
		DatagramPacket DpReceive = null;
		for (int i = 0; i < TCPServer.NodeList.size(); i++) {
			TCPServer.NodeList.remove(i);
		}
		while (true) {

			// Step 2 : create a DatgramPacket to receive the data.
			DpReceive = new DatagramPacket(receive, receive.length);

			// Step 3 : receive the data in byte buffer.
			socket.receive(DpReceive);

			// get server address
			ServerAddress = DpReceive.getAddress();
			if (!TCPServer.NodeList.contains(ServerAddress)) {
				TCPServer.NodeList.add(ServerAddress);
			}

			// Clear the buffer after every message.
			if (ChronoUnit.SECONDS.between(then, LocalDateTime.now()) >= 10)
				break;
			receive = new byte[65535];
		}
	}

	public static StringBuilder convert_data(byte[] a) {
		if (a == null)
			return null;
		StringBuilder ret = new StringBuilder();
		int i = 0;
		while (a[i] != 0) {
			ret.append((char) a[i]);
			i++;
		}
		return ret;
	}

	public void run() {

		try {
			// broadcast("Hello", InetAddress.getByName("255.255.255.255"));
			Create_Node_List();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
