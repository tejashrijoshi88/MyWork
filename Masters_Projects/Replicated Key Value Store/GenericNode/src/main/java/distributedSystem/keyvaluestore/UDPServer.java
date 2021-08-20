package distributedSystem.keyvaluestore;

import java.io.IOException;
import java.net.*;

public class UDPServer {

	private DatagramSocket udpServerSocket;
	private int port;
	static StoreData database = new StoreData();

	public UDPServer(int port) throws SocketException, IOException {
		this.port = port;
		this.udpServerSocket = new DatagramSocket(this.port);
	}

	public void udpListen() throws Exception {

		try {
			System.out.println(" Running Server at " + InetAddress.getLocalHost() + "--");

			byte[] bytes = new byte[65535];
			DatagramPacket packet = null;
			Thread t;
			while (true) {
				// Receive packets
				packet = new DatagramPacket(bytes, bytes.length);
				this.udpServerSocket.receive(packet);
				UDPServerClientThread usct = new UDPServerClientThread(this.udpServerSocket, packet);
				try {
					System.out.println("Thread test");
					t = new Thread(usct);
					t.start();
				} catch (Exception e) {
					e.printStackTrace();
					System.out.println(e.getMessage());
				}
			}
		} catch (IOException e) {
			System.out.println("Server exception: " + e.getMessage());
			e.printStackTrace();
		}
	}

	private static class UDPServerClientThread implements Runnable {
		private DatagramSocket sockt;
		private DatagramPacket recievePacket;

		public UDPServerClientThread(DatagramSocket udpServerSocket, DatagramPacket recievePacket) {
			this.sockt = udpServerSocket;
			this.recievePacket = recievePacket;
		}

		public void run() {
			// send response to client
			String data;

			try {
				// Convert it to string
				while (true) {
					String quote = new String(recievePacket.getData());// bytes, 0, packet.getLength()
					System.out.println("Client: " + quote);
					data = StoreData.response_check(quote);
					if (data.equals("exit")) {
						System.out.println("Bye");
						this.sockt.close();
					}
					// send packets
					byte[] serverResponse = data.getBytes();
					DatagramPacket response = new DatagramPacket(serverResponse, serverResponse.length,
							recievePacket.getAddress(), recievePacket.getPort());
					this.sockt.send(response);
				}
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				if(this.sockt!=null)
					this.sockt.close();
			}

		}

	}

}
