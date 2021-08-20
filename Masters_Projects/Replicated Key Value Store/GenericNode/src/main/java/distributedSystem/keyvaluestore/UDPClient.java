package distributedSystem.keyvaluestore;

import java.io.*;
import java.net.*;

public class UDPClient {

	private DatagramSocket udpSocket;
	private InetAddress serverAddress;
	private int serverPort;

	public UDPClient(String destinationAddr, int port) throws IOException {
		this.serverAddress = InetAddress.getByName(destinationAddr);
		this.serverPort = port;
	}

	public void start(String s) throws IOException {
		try {
			byte[] data = new byte[1024];
			this.udpSocket = new DatagramSocket();
			//	this.udpSocketRecieve = new DatagramSocket(this.serverPort+1);
			//while (true) {
				// Send Data packets to server
				System.out.println(this.serverAddress);
				DatagramPacket packet = new DatagramPacket(s.getBytes(), s.getBytes().length, this.serverAddress,
						this.serverPort);
				this.udpSocket.send(packet);
				System.out.println("Sent data,waiting for data to recieve");
			
				// Receive packet from Server
				DatagramPacket response = new DatagramPacket(data, data.length);
				this.udpSocket.receive(response);

				String quote = new String(response.getData(), 0, response.getLength());
				System.out.println("recieved packet " + quote);
				data = new byte[1024];
			//}
		} catch (SocketTimeoutException e) {
			System.out.println("Timeout error: " + e.getMessage());
			e.printStackTrace();
		}

	}

}
