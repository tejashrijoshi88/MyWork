package distributedSystem.keyvaluestore;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;

public class CheckLockedThread extends Thread {
	Socket participantSocket;
	String ip;
	String operation;
	String key = null;
	String value = null;

	OutputStream outputStream = null;
	PrintWriter printWriter = null;
	BufferedReader bufferedReader = null;

	String response = "Locked";

	public CheckLockedThread(String operation, String ip, String key, String value) throws IOException {
		this.ip = ip;
		this.participantSocket = new Socket(ip, 1234);
		this.operation = operation;// (operation.equals("put") ? "dput1" : "ddel1" );
		outputStream = participantSocket.getOutputStream();
		printWriter = new PrintWriter(outputStream, true);
		bufferedReader = new BufferedReader(new InputStreamReader(participantSocket.getInputStream()));
		this.key = key;
		this.value = value;
	}

	public String checkIfLocked(int retry) {
		if (retry <= 0) {
			return "Locked";
		}
		String op = (operation.equals("put") ? "dput1" : "ddel1");
		printWriter.println(op.concat(" " + key));
		String response;
		try {
			response = bufferedReader.readLine();
			if (response.equalsIgnoreCase("COMMIT")) {
				return "Not_Locked";
			} else { // "Received ABORT"
				return checkIfLocked(retry--);
			}
		} catch (IOException e) {
			return "Locked";
		}
	}

	public String editMethod() throws IOException {
		String op;
		if(operation.equalsIgnoreCase("PUT") || operation.equalsIgnoreCase("DEL"))
			op = "COMMIT ".concat(operation + " " + key + " " + value);
		else
			op = operation;
		//System.out.println("DEBUG: Commit Command: " + op);
		printWriter.println(op);
		
		String response;
		try {
			response = bufferedReader.readLine();
			return response;
		} catch (IOException e) {
			return "";
		} finally {
			outputStream.close();
			printWriter.close();
			bufferedReader.close();
		}

	}

	@Override
	public void run() {
		response = checkIfLocked(10);
	}
}
