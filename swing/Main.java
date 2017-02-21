
public class Main {
	
	
	/**
	 * Starts the connection and displays the GUI */
	public static void main(String argv[]) {
		System.out.println("Start");
		WindowManager.prepareGUI();
		Client.start(argv);
		
	}
}


