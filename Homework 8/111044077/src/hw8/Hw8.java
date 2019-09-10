/*
===============================================================================
        

        ConnectFour Game 
        Homework 8

        Mesut BUNALDI
        111044077


===============================================================================        
 */
package hw8;

import javax.swing.JOptionPane;

/**
 *
 * @author mesut
 */
public class Hw8 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        try {
             ConnectFour game=new ConnectFour();
        } catch ( Exception ex)
            {
                JOptionPane.showMessageDialog(null,ex.toString());
            }
       
        
      
      
    }
    
}
