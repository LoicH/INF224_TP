import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.AbstractAction;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;


public class WindowManager {
	private static final long serialVersionUID = 1L;

	/** The text input box */
	private static JTextArea textArea;
	
	/** Panel printing the results of requests */
	private static JLabel results;

	/** Returns a the input text from the text input box */
	public static String getInputText(){
		return textArea.getText();
	}
	
	/** Display text into the result panel */
	public static void display(String result){
		results.setText(result);
	}
	
	/** Sets and displays the GUI */
	public static void prepareGUI(){
		JFrame frame = new JFrame("Télécommande");

		//Listener pour quitter
		frame.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});

		textArea = new JTextArea(3, 80);
		results = new JLabel();
		
		// Crée les 3 actions qui serviront pour les boutons et menus
		SearchAction searchAction = new SearchAction("Search");
		PlayAction playAction = new PlayAction("Play");
		QuitAction quitAction = new QuitAction("Quit");
		
		// Les 3 boutons à droite
		JButton searchBttn = new JButton(searchAction);
		JButton quitBttn = new JButton(quitAction);
		JButton playBttn = new JButton(playAction);
		
		
		JPanel buttonPanel = new JPanel(new BorderLayout());
		buttonPanel.add(searchBttn, BorderLayout.WEST);
		buttonPanel.add(playBttn, BorderLayout.EAST);
		buttonPanel.add(quitBttn, BorderLayout.SOUTH);
		
		// La barre de menu en haut
		JMenuBar menuBar= new JMenuBar();
		JMenu menu = new JMenu("Menu");

		menu.add(new JMenuItem(playAction));
		menu.add(new JMenuItem(searchAction));
		menu.add(new JMenuItem(quitAction));

		menuBar.add(new JMenuItem(playAction));
		menuBar.add(new JMenuItem(searchAction));
		menuBar.add(new JMenuItem(quitAction));

		
		menuBar.add(menu);

		
		frame.setJMenuBar(menuBar);
		frame.getContentPane().add(new JScrollPane(textArea), BorderLayout.CENTER);
		frame.getContentPane().add(buttonPanel, BorderLayout.EAST);
		frame.getContentPane().add(results, BorderLayout.SOUTH);
		frame.pack();
		frame.setVisible(true);
		
	}
	
}

/**
 * Action to send a Search request to the server
 */
class SearchAction extends AbstractAction {

	private static final long serialVersionUID = 6421607840255999181L;

	public SearchAction(String name) {
		super(name);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		WindowManager.display("Search results: \n"+
					Client.send("print "+WindowManager.getInputText()));
		
	}
	
}

/**
 * Action to send a Play request to the server
 */
class PlayAction extends AbstractAction {

	private static final long serialVersionUID = -3561039987947126794L;

	public PlayAction(String name) {
		super(name);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		System.out.println("Play action: "+WindowManager.getInputText());
		System.out.println(Client.send("play "+WindowManager.getInputText()));
		
	}
	
}

/**
 * Action to quit the applet
 */
class QuitAction extends AbstractAction {

	private static final long serialVersionUID = -1250491014299297851L;

	public QuitAction(String name) {
		super(name);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		System.out.println("Quit action");
		System.exit(0);
		
	}
	
}
