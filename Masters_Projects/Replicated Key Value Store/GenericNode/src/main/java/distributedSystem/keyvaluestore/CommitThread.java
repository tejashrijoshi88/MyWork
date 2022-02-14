package distributedSystem.keyvaluestore;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;

public class CommitThread extends Thread {
	Socket participantSocket;
	String ip;
	String key = null;
	String value = null;
	String operation;

	OutputStream outputStream = null;
	PrintWriter printWriter = null;
	BufferedReader bufferedReader = null;

	String response = "";

	public CommitThread(String operation, String ip, String key, String value) throws IOException {
		this.ip = ip;
		this.participantSocket = new Socket(ip, 1234);
		this.operation = "COMMIT ".concat(operation + " " + key + " " + value);
		outputStream = participantSocket.getOutputStream();
		printWriter = new PrintWriter(outputStream, true);
		bufferedReader = new BufferedReader(new InputStreamReader(participantSocket.getInputStream()));
		this.key = key;
		this.value = value;
	}

	public String editMethod() {

		printWriter.println(operation);

		String response;
		try {
			response = bufferedReader.readLine();
			return response;
		} catch (IOException e) {

			return "";
		}
	}

	@Override
	public void run() {
		response = editMethod();
		try {
			outputStream.close();
			printWriter.close();
			bufferedReader.close();
		} catch (IOException e) {
			System.out.println("Error while close connections: " + e.getMessage());
		}
	}
}
