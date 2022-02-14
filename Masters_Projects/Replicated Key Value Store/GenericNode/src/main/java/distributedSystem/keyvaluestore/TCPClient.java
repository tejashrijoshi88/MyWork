package distributedSystem.keyvaluestore;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;

public class TCPClient {
	private InetAddress serverAddress;
	private Socket tcpSocket;
	private int serverPort;
	static boolean closed = false;
	static BufferedReader data = null;
	static InputStream input = null;
	static PrintWriter writer = null;
	static OutputStream output = null;

	public TCPClient(String destinationAddr, int port) throws IOException {
		this.serverAddress = InetAddress.getByName(destinationAddr);
		this.serverPort = port;
	}

	public void start(String s) throws IOException {
		String str = null;
		try {
			this.tcpSocket = new Socket(this.serverAddress, this.serverPort);

			// send data to server
			output = this.tcpSocket.getOutputStream();
			writer = new PrintWriter(output, true);
			writer.println(String.valueOf(s));
			// Receive data from server
			input = this.tcpSocket.getInputStream();
			data = new BufferedReader(new InputStreamReader(input));

			try {
				str = data.readLine();
				String[] arrOfResponse = str.split(";");
				for (String line : arrOfResponse) 
		            System.out.println(line);
				input.close();
				writer.close();
				output.close();
			} catch (IOException e) {
				System.err.println("IOException:  " + e);
			}

		} catch (Exception e) {
			System.out.println("Exception occurred : " + e.getMessage());
			e.printStackTrace();
		} finally {
			input.close();
			writer.close();
			output.close();
			this.tcpSocket.close();
		}
	}

}
