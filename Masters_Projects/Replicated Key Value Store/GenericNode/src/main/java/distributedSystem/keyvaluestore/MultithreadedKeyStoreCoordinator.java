package distributedSystem.keyvaluestore;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MultithreadedKeyStoreCoordinator {
	List<CheckLockedThread> threads = new ArrayList<CheckLockedThread>();

	public boolean checkIfLocked(String operation, String key, List<String> ips, String value)
			throws IOException, InterruptedException {

		for (String ip : ips) {
			CheckLockedThread thread = new CheckLockedThread(operation, ip, key, value);
			threads.add(thread);
		}
		for (CheckLockedThread thread : threads) {
			thread.start();
		}
		for (CheckLockedThread thread : threads) {
			thread.join();
		}
		return isLocked(threads);
	}

	public String editKey(String operation, String key, String value, List<String> ips)
			throws IOException, InterruptedException {

		String response = "";
		for (CheckLockedThread thread : threads) {
			response = thread.editMethod();
		}
		return response;
	}

	private boolean isLocked(List<CheckLockedThread> threads) {
		Map<String, String> res = getResponsesFromCheckLockedThread(threads);
		boolean response = false;
		boolean res1 = false;
		for (String ip : res.keySet()) {
			if (res.get(ip).equals("Locked"))
				res1 = true;
			else
				res1 = false;
			response = response || res1;
		}
		//System.out.println("DEBUG: Is key Locked Response: " + response);
		return response;
	}

	private Map<String, String> getResponsesFromCheckLockedThread(List<CheckLockedThread> threads) {
		Map<String, String> responses = new HashMap<String, String>();
		for (CheckLockedThread thread : threads) {
			responses.put(thread.ip, thread.response);
		}
		//System.out.println("DEBUG: getResponsesFromCheckLockedThread:: Responses From All IPs: " + responses);
		return responses;
	}

}
