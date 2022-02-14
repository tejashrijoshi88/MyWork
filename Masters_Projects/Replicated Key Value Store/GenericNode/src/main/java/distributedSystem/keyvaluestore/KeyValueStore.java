package distributedSystem.keyvaluestore;

import java.io.IOException;
import java.util.Map;
import java.util.concurrent.locks.ReentrantReadWriteLock;
import java.util.concurrent.ConcurrentHashMap;

public class KeyValueStore {
	static Map<String, String> storedb = new ConcurrentHashMap<String, String>();
	private final ReentrantReadWriteLock[] lock;
	int numberoflocks = 100;
	static ReentrantReadWriteLock lock1;

	KeyValueStore() {
		lock = new ReentrantReadWriteLock[numberoflocks];
		for (int i = 0; i < numberoflocks; i++) {
			lock[i] = new ReentrantReadWriteLock();
		}

	}

	public void put(String in, String in2) {
		storedb.put(in, in2);
	}

	public String get(String key) {
		return storedb.get(key);
	}

	public void del(String key) {
		if (storedb.containsKey(key))
			storedb.remove(key);
	}

	public String store() {
		String stored_values = "";
		int maxLength = 65000;
		for (String i : storedb.keySet()) {
			stored_values += ("key:" + i + ":" + "value:" + storedb.get(i) + ";");
		}
		if (stored_values.length() == 0) {
			stored_values = "NULL";
		}
		stored_values = "Server Response:;" + stored_values;

		// if stored values length exceed 65000 characters it should truncate
		if (stored_values.length() > maxLength) {
			stored_values = "TRIMMED:" + stored_values.substring(0, maxLength);
		}
		return stored_values;

	}

	public void exit() throws IOException {
		TCPServer.serverSocket.close();
	}

	public String dput1(String in) {
		String response = "";
		int ascii = checkChValue(in);
		lock1 = lock[ascii % numberoflocks];
		if (lock1.isWriteLocked() == true)
			response = "Abort";
		else {
			response = "Commit";
			lock1.writeLock().lock();
		}
		return response;
	}

	public void dput2(String in, String in2) {
		try {
			put(in, in2);
		} finally {
			lock1.writeLock().unlock();

		}
	}

	public void dputabort(String in, String in2) {
		lock1.writeLock().unlock();
	}

	public String ddel1(String in) {
		String response = "";
		int ascii = checkChValue(in);
		lock1 = lock[ascii % numberoflocks];
		if (lock1.isWriteLocked() == true)
			response = "Abort";
		else {
			response = "Commit";
			lock1.writeLock().lock();
		}
		return response;
	}

	public void ddel2(String in) {
		// lock1.writeLock().lock();
		try {
			del(in);
		} finally {
			lock1.writeLock().unlock();
		}

	}

	public void ddelabort(String in, String in2) {
		lock1.writeLock().unlock();
	}

	public int checkChValue(String s) {
		int ascii = 0;
		for (int i = 0; i < s.length(); i++) {
			char character = s.charAt(i);
			ascii = (int) character;
		}
		return ascii;
	}

}
