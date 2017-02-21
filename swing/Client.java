//
// Client Java pour communiquer avec le Serveur C++ 
//  - telecom paristech - 2015
//

import java.io.*;
import java.net.*;

/**
 * Client communicating with the C++ server
 * @author Eric Lecolinet
 */
public class Client
{
  private static final long serialVersionUID = 1L;
  static final String DEFAULT_HOST = "localhost";
  static final int DEFAULT_PORT = 3331;
  private static Socket sock;
  private static BufferedReader input;
  private static BufferedWriter output;

	/** Connects the client to the server
	 * @param argv The array of commands: [host, port]
	 */
  public static void start(String argv[]) {
    String host = DEFAULT_HOST;
    int port = DEFAULT_PORT;
    if (argv.length >=1) host = argv[0];
    if (argv.length >=2) port = Integer.parseInt(argv[1]);
    
    Client client = null;
    
    try {
      client = new Client(host, port);
    }
    catch (Exception e) {
      System.err.println("Client: Couldn't connect to "+host+":"+port);
      System.exit(1);
    }
    
    System.out.println("Client connected to "+host+":"+port);

  }

  /**
   * Inits the connection with the server
   * @throws Exception if there is an error
   */
  public Client(String host, int port) throws UnknownHostException, IOException {
    try {
      sock = new java.net.Socket(host, port);
    }
    catch (java.net.UnknownHostException e) {
      System.err.println("Client: Couldn't find host "+host+":"+port);
      throw e;
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't reach host "+host+":"+port);
      throw e;
    }
    
    try {
      input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
      output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't open input or output streams");
      throw e;
    }
  }
  
	/**
	 * Sends a request to the server
	 * @return The response from the server
	 */
  public static String send(String request) {
    // Envoyer la requete au serveur
    try {
      request += "\n";  // ajouter le separateur de lignes
      output.write(request, 0, request.length());
      output.flush();
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't send message: " + e);
      return null;
    }
    
    // Recuperer le resultat envoye par le serveur
    try {
      return input.readLine();
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't receive message: " + e);
      return null;
    }
  }
}

