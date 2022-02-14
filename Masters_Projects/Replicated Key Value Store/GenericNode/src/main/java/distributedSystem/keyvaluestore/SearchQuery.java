package distributedSystem.keyvaluestore;

import java.io.IOException;
import java.rmi.RemoteException;

public class SearchQuery extends java.rmi.server.UnicastRemoteObject implements Search {

	protected SearchQuery() throws RemoteException {
		super();
	}
	private static final long serialVersionUID = 1L;

	public String query(String res) {
		String out = null;
		try {
			out = StoreData.response_check(res);
		} catch (IOException e) {
			e.printStackTrace();
		}
		return out;
	}
}
