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

	private static JTextArea textArea;
	private static JLabel results;

	public static String getInputText(){
		return textArea.getText();
	}
	
	public static void display(String result){
		results.setText(result);
	}
	
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
		
		SearchAction searchAction = new SearchAction("Search");
		PlayAction playAction = new PlayAction("Play");
		QuitAction quitAction = new QuitAction("Quit");
		
		
		JButton searchBttn = new JButton(searchAction);
		JButton quitBttn = new JButton(quitAction);
		JButton playBttn = new JButton(playAction);
		
		
		JPanel buttonPanel = new JPanel(new BorderLayout());
		buttonPanel.add(searchBttn, BorderLayout.WEST);
		buttonPanel.add(playBttn, BorderLayout.EAST);
		buttonPanel.add(quitBttn, BorderLayout.SOUTH);
		

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
