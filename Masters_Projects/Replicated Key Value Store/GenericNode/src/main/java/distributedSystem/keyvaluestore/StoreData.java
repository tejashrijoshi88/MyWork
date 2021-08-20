package distributedSystem.keyvaluestore;

import java.io.IOException;

public class StoreData {

	static KeyValueStore store = new KeyValueStore();

	public static String response_check(String res) throws IOException {
		String[] response = res.split(" ");
		if ((response[0].equalsIgnoreCase("PUT") || response[0].equalsIgnoreCase("DEL"))) {
			return "Call Coordinator";
		} else if (response[0].equalsIgnoreCase("get")) {
			String result = store.get(response[1]);
			return "Server Response:" + "get key = " + response[1] + " get val = " + result;
		} else if (response[0].equalsIgnoreCase("del") && TCPServer.NodeList.size() == 0) {
			store.del(response[1]);
			return "Server Response:" + "del key = " + response[1];
		} else if (response[0].equalsIgnoreCase("store")) {
			return store.store();
		} else if (response[0].equalsIgnoreCase("exit"))
			return "exit";
		else if (response[0].equalsIgnoreCase("dput1")) {
			String output = store.dput1(response[1]);
			return output;
		} else if (response[0].equalsIgnoreCase("ddel1")) {
			String output = store.ddel1(response[1]);
			return output;
		} else if (response[0].equalsIgnoreCase("COMMIT") && response[1].equalsIgnoreCase("PUT")) {
			store.dput2(response[2], response[3]);
			return "Server Response:" + "put key = " + response[2];
		} else if (response[0].equalsIgnoreCase("GLOBAL_ABORT") && response[1].equalsIgnoreCase("PUT")) {
			store.dputabort(response[1], response[2]);
			return "Aborted";
		} else if (response[0].equalsIgnoreCase("COMMIT") && response[1].equalsIgnoreCase("DEL")) {
			store.ddel2(response[2]);
			return "Server Response:" + "del key = " + response[2];
		} else if (response[0].equalsIgnoreCase("GLOBAL_ABORT") && response[1].equalsIgnoreCase("DEL")) {
			store.ddelabort(response[1], response[2]);
			return "Server Response:" + "Aborted";
		} else
			return null;
	}

}
