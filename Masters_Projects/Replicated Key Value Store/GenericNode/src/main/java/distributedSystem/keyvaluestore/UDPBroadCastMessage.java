package distributedSystem.keyvaluestore;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.TimerTask;

public class UDPBroadCastMessage extends TimerTask {
	private static DatagramSocket socket = null;
	private String BroadCastMessage = "Hello";
	private static int BroadCastPort = 4445;
	private String BroadCastIP = "255.255.255.255";

	
	public static void broadcast(String broadcastMessage, InetAddress address) throws IOException {
		socket = new DatagramSocket();
		socket.setBroadcast(true);

		byte[] buffer = broadcastMessage.getBytes();

		DatagramPacket packet = new DatagramPacket(buffer, buffer.length, address, BroadCastPort);
		socket.send(packet);
	}

	public void run() {

		try {
			broadcast(BroadCastMessage, InetAddress.getByName(BroadCastIP));

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
