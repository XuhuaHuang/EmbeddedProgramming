package TouchJFrame;

import javax.swing.JFrame; // import package
import java.awt.Color;
import javax.swing.ImageIcon;

public class TouchJFrameMain {

	public static void main(String[] args) {
		
		JFrame frame = new JFrame(); // creating an instance with default constructor
		
		// set visuals
		frame.setVisible(true); // set the frame to visible
		frame.setTitle("JFrame Title"); // set title of the frame
		frame.setSize(720, 1080); // set the size of the window
		frame.setResizable(false); // set the window to non-resizable
		frame.getContentPane().setBackground(new Color(0x123456)); // set the background color to navy blue
		
		// set a logo as the icon
		ImageIcon image = new ImageIcon("logo.png");
		frame.setIconImage(image.getImage()); // change icon of frame with getter of the image object
		
		// set close action
		// EXIT/HIDE/DONOTHING_ON_CLOSE
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // close on the exit button

		return;
	} // end main method

} // end file class
