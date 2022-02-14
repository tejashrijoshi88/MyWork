package distributedSystem.keyvaluestore;

import java.io.IOException;
import java.net.DatagramSocket;
import java.util.Timer;

public class broadcast_server {

	private static class BroadCastMessageThread implements Runnable {

		public BroadCastMessageThread() {
			// this.sockt = udpServerSocket;
		}

		public void run() {
			Timer time = new Timer();
			UDPBroadCastMessage broeacast_message = new UDPBroadCastMessage();
			time.schedule(broeacast_message, 0, 1000);
		}
	}

	private static class NodeDiscoveryThread implements Runnable {
		private DatagramSocket sockt;

		public NodeDiscoveryThread(DatagramSocket udpServerSocket) {
			this.sockt = udpServerSocket;
		}

		public void run() {
			try {

				Timer time = new Timer();
				UDP_Listen broeacast_message = new UDP_Listen(this.sockt);
				time.schedule(broeacast_message, 0, 20000);

			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		}

	}

	public static void BroadCast() throws IOException {
		// Instantiate Timer Object
		// Instantiate SheduledTask class

		Thread t;
		DatagramSocket udpServerSocket = new DatagramSocket(4445);
		NodeDiscoveryThread usct = new NodeDiscoveryThread(udpServerSocket);
		BroadCastMessageThread Bt = new BroadCastMessageThread();
		try {

			t = new Thread(usct);
			Thread t1 = new Thread(Bt);
			t1.start();
			t.start();

		} catch (Exception e) {
			e.printStackTrace();
			System.out.println(e.getMessage());
		}
	}
}
