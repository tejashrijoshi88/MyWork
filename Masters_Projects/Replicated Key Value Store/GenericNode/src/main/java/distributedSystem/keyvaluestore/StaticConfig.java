package distributedSystem.keyvaluestore;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.net.InetAddress;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Collections;
//import java.util.List;

public class StaticConfig {

	public static void config() throws Exception {

		Collections.emptyList();
		try {
			Files.readAllLines(Paths.get("/tmp/nodes.cfg"), StandardCharsets.UTF_8);
		} catch (IOException e) {
			e.printStackTrace();
		}
		// reading text file into ArrayList
		BufferedReader bufReader = new BufferedReader(new FileReader("/tmp/nodes.cfg"));
		// ArrayList<String> listOfLines = new ArrayList<String>();
		String line = bufReader.readLine();
		while (line != null) {
			String[] line_ip = line.split(":");
			if (!TCPServer.NodeList.contains(InetAddress.getByName(line_ip[0])))
				TCPServer.NodeList.add(InetAddress.getByName(line_ip[0]));
			line = bufReader.readLine();
		}
		bufReader.close();
	}
}