import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MainWindow {
	
	public static void main(String s[]) {
		JFrame frame = new JFrame("Télécommande");

		//Listener pour quitter
		frame.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});

		JTextArea textArea = new JTextArea(3, 80);
		
		frame.getContentPane().add(textArea, BorderLayout.CENTER);
		frame.pack();
		frame.setVisible(true);
	}
}
