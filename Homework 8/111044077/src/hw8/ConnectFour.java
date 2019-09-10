/*
===============================================================================
        

        ConnectFour Game 
        Homework 8

        Mesut BUNALDI
        111044077


===============================================================================        
 */
package hw8;

import java.util.Vector;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.*;

/**
 * MainFrame of ConnectFour
 * @author mesut
 * 
 *
 */
public final class ConnectFour extends JFrame implements KeyListener {
/**
 * Key listener for move
 * @param e 
 */
    @Override
    public void keyTyped(KeyEvent e) {
        char c = e.getKeyChar();
        repaint();
    }
/**
 * 
 * @param e 
 */
    @Override
    public void keyPressed(KeyEvent e) {
        int col = Character.getNumericValue(e.getKeyChar()) - 10;
        playGame(col);
    }
/**
 * 
 * @param e 
 */
    @Override
    public void keyReleased(KeyEvent e
    ) {
        char c = e.getKeyChar();
        repaint();
    }
    //inner class
/**
 * Inner Class
 */
    private final class Cell extends JLabel {

        //constructors
        /**
         * Default Constructor of Cell
         */
        public Cell() {

            setBackground(Color.BLACK);

            this.setText("  .  ");
            this.setLayout(new BorderLayout());
            this.setBounds(2, 2, 240, 240);
            this.setBorder(BorderFactory.createLineBorder(Color.BLACK));
            setVisible(true);

        }

        //copy constructor 
        /**
         * Copy Constructor for Cell
         * 
         * @param other 
         */
        public Cell(Cell other) {
            setText(other.getText());

            setBackground(other.getBackground());

        }

    }

    //ConnectFour fields
    /**
     * Data fields for ConnectFour
     */
    private char gameType; // p : PVP , c: PVC 
    private Vector<Vector<Cell>> board;
    private int size;
    private int playerRank = 1;
    private JPanel panel;

    //no parameter constructor /// 
    /**
     * Default Constructor for ConnectFour
     */
    public ConnectFour() {
        setBounds(300, 300, 800, 800);
        chooseGameType();
        setSizeBoard();
        fillBoard();
        setLayout(new FlowLayout());
        this.setSize(getBoardSize() * 40, getBoardSize() * 32);
        showBoard();

        setVisible(true);
        addKeyListener(this);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    //one parameter constructor  
    /**
     * One Parameter Constructor for ConnectFour
     * @param sizeVal 
     */
    public ConnectFour(int sizeVal) {
        size = sizeVal;
        gameType='P';
        setBounds(300, 300, 800, 800);
        fillBoard();
        setLayout(new FlowLayout());
        this.setSize(getBoardSize() * 40, getBoardSize() * 32);
        showBoard();
        setVisible(true);
        addKeyListener(this);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
/**
 * Reset GameBoard for ConnectFour
 */
    public void resetBoard() {
        for (int i = 0; i < getBoardSize(); i++) {
            for (int j = 0; j < getBoardSize(); j++) {
                board.elementAt(i).elementAt(j).setText("  .  ");
            }
        }
        panel.revalidate();
    }
/**
 * Initialize GameBoard for ConnectFour
 */
    public void fillBoard() {

        Cell tmpCell;
        Vector<Cell> tmpVector;
        board = new Vector<>();
        for (int i = 0; i < getBoardSize(); i++) {
            tmpVector = new Vector<>();
            for (int j = 0; j < getBoardSize(); j++) {
                tmpCell = new Cell();
                tmpVector.add(tmpCell);
            }
            board.add(tmpVector);

        }
    }
/**
 * General Play Function for Game
 * @param colVal 
 * colVal is position of column
 */
    public void playGame(int colVal) {

        play(colVal);
        play();
        int result = checkWin();
        if (result == 1) {
            JOptionPane.showMessageDialog(null, "user1 kazandı!");
            resetBoard();
        } else if (result == 2 && (getGameType() == 'P' || getGameType() == 'p')) {
            JOptionPane.showMessageDialog(null, "user 2 kazandı!   Game mode : " + getGameType());
            resetBoard();
        } else if (result == 2 && (getGameType() == 'C' || getGameType() == 'c')) {
            JOptionPane.showMessageDialog(null, "user 2 kazandı!   Game mode : " + getGameType());
            resetBoard();
        }

        panel.revalidate();
    }
/**
 * Play Function for User1 and User2
 * @param colVal 
 * colVal is position of column
 */
    public void play(int colVal) {

        if (colVal >= getBoardSize()) {
            JOptionPane.showMessageDialog(null, "Lütfen oyun alanı içerisinde hamle yapınız!");
        }

        if (colVal >= 0 && colVal < getBoardSize()) {

            if (getPlayerRank() == 1) {
                for (int rowVal = getBoardSize() - 1; rowVal >= 0; rowVal--) {
                    if ("  .  ".equals(board.elementAt(rowVal).elementAt(colVal).getText()) && getPlayerRank() == 1) {
                        board.elementAt(rowVal).elementAt(colVal).setText(" X  ");
                        board.elementAt(rowVal).elementAt(colVal).setBackground(Color.white);
                        if (getGameType() == 'P' || getGameType() == 'p') {
                            setPlayerRank(2);
                        } else if (getGameType() == 'C' || getGameType() == 'c') {
                            setPlayerRank(3);
                        }
                    }
                }
            } else if (getPlayerRank() == 2) {
                for (int rowVal = getBoardSize() - 1; rowVal >= 0; rowVal--) {
                    if ("  .  ".equals(board.elementAt(rowVal).elementAt(colVal).getText()) && getPlayerRank() == 2) {
                        board.elementAt(rowVal).elementAt(colVal).setText(" O  ");
                        setPlayerRank(1);
                    }
                }
            }

        }

    }
/**
 * Play Function for Computer (Smart Move)
 * @return 
 */
    public int play() {
        if (getPlayerRank() == 3 && (getGameType() == 'C' || getGameType() == 'c')) {
            setPlayerRank(1);
            for (int row = getBoardSize() - 1; row >= 0; --row) {
                for (int col = 0; col < getBoardSize(); ++col) {

                    if ("  .  ".equals(board.elementAt(row).elementAt(col).getText())) {
                        board.elementAt(row).elementAt(col).setText(" O  ");
                        return 1;
                    } else if (row - 3 > 0
                            && " X  ".equals(board.elementAt(row).elementAt(col).getText())
                            && " X  ".equals(board.elementAt(row - 1).elementAt(col).getText())
                            && " X  ".equals(board.elementAt(row - 2).elementAt(col).getText())
                            && "  .  ".equals(board.elementAt(row - 3).elementAt(col).getText())) {
                        board.elementAt(row - 3).elementAt(col).setText(" O  ");
                        return 1;
                    } else if (col - 3 > 0
                            && " X  ".equals(board.elementAt(row).elementAt(col).getText())
                            && " X  ".equals(board.elementAt(row).elementAt(col - 1).getText())
                            && " X  ".equals(board.elementAt(row).elementAt(col - 2).getText())
                            && "  .  ".equals(board.elementAt(row).elementAt(col - 3).getText())) {
                        board.elementAt(row).elementAt(col - 3).setText(" O  ");
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
/**
 * Show Function for ConnectFour Gameboard
 */
    public void showBoard() {

        panel = new JPanel();
        panel.setSize(getBoardSize(), getBoardSize() * 3);
        panel.setLayout(new GridLayout(getBoardSize() + 2, getBoardSize(), 1, 1));
        add(panel);
        JPanel letters = new JPanel();
        letters.setLayout(new FlowLayout());
        for (int j = 0; j < getBoardSize(); j++) {
            Cell letter = new Cell();
            letter.setLayout(new BorderLayout());
            letter.setText(" " + (char) (j + 65) + "  ");
            letters.add(letter, BorderLayout.WEST);
        }
        panel.add(letters);
        for (int i = 0; i < getBoardSize(); i++) {
            JPanel row = new JPanel();
            row.setLayout(new FlowLayout());
            row.setBackground(Color.LIGHT_GRAY);
            for (int j = 0; j < getBoardSize(); j++) {
                row.add(board.elementAt(i).elementAt(j));
            }
            panel.add(row, BorderLayout.WEST);

            panel.setVisible(true);
            add(panel);
            setVisible(true);
        }
    }
/**
 * Check Winner for ConnectFour
 * @return winnerType (User1 or User2 or Computer)
 */
    public int checkWin() {
        int counter = 0;//fullBoard?
        for (int row = 0; row < getBoardSize(); ++row) {
            for (int col = 0; col < getBoardSize(); ++col) {

                if ("  .  ".equals(board.elementAt(row).elementAt(col).getText())) {
                    ++counter;
                }
                if ((row < size - 3 && row >= 0)
                        && " X  ".equals(board.elementAt(row).elementAt(col).getText())
                        && " X  ".equals(board.elementAt(row + 1).elementAt(col).getText())
                        && " X  ".equals(board.elementAt(row + 2).elementAt(col).getText())
                        && " X  ".equals(board.elementAt(row + 3).elementAt(col).getText())) {
                    board.elementAt(row).elementAt(col).setText(" x  ");
                    board.elementAt(row + 1).elementAt(col).setText(" x  ");
                    board.elementAt(row + 2).elementAt(col).setText(" x  ");
                    board.elementAt(row + 3).elementAt(col).setText(" x  ");

                    return 1;
                }
                if ((col < size - 3 && col >= 0)
                        && (" X  ".equals(board.elementAt(row).elementAt(col).getText())
                        && " X  ".equals(board.elementAt(row).elementAt(col + 1).getText())
                        && " X  ".equals(board.elementAt(row).elementAt(col + 2).getText())
                        && " X  ".equals(board.elementAt(row).elementAt(col + 3).getText()))) {
                    board.elementAt(row).elementAt(col).setText(" x  ");
                    board.elementAt(row).elementAt(col + 1).setText(" x  ");
                    board.elementAt(row).elementAt(col + 2).setText(" x  ");
                    board.elementAt(row).elementAt(col + 3).setText(" x  ");

                    return 1;
                }

                if ((col >= 3 && row < size - 3)
                        && (" X  ".equals(board.elementAt(row).elementAt(col).getText())
                        && " X  ".equals(board.elementAt(row + 1).elementAt(col - 1).getText())
                        && " X  ".equals(board.elementAt(row + 2).elementAt(col - 2).getText()))
                        && " X  ".equals(board.elementAt(row + 3).elementAt(col - 3).getText())) {
                    board.elementAt(row).elementAt(col).setText(" x  ");
                    board.elementAt(row + 1).elementAt(col - 1).setText(" x  ");
                    board.elementAt(row + 2).elementAt(col - 2).setText(" x  ");
                    board.elementAt(row + 3).elementAt(col - 3).setText(" x  ");

                    return 1;
                }
                if ((col < size - 3 && row < size - 3)
                        && (" X  ".equals(board.elementAt(row).elementAt(col).getText())
                        && " X  ".equals(board.elementAt(row + 1).elementAt(col + 1).getText())
                        && " X  ".equals(board.elementAt(row + 2).elementAt(col + 2).getText()))
                        && " X  ".equals(board.elementAt(row + 3).elementAt(col + 3).getText())) {
                    board.elementAt(row).elementAt(col).setText(" x  ");
                    board.elementAt(row + 1).elementAt(col + 1).setText(" x  ");
                    board.elementAt(row + 2).elementAt(col + 2).setText(" x  ");
                    board.elementAt(row + 3).elementAt(col + 3).setText(" x  ");

                    return 1;
                }
                if ((row < size - 3 && row >= 0)
                        && " O  ".equals(board.elementAt(row).elementAt(col).getText())
                        && " O  ".equals(board.elementAt(row + 1).elementAt(col).getText())
                        && " O  ".equals(board.elementAt(row + 2).elementAt(col).getText())
                        && " O  ".equals(board.elementAt(row + 3).elementAt(col).getText())) {
                    board.elementAt(row).elementAt(col).setText(" o  ");
                    board.elementAt(row + 1).elementAt(col).setText(" o  ");
                    board.elementAt(row + 2).elementAt(col).setText(" o  ");
                    board.elementAt(row + 3).elementAt(col).setText(" o  ");

                    return 2;
                }
                if ((col < size - 3 && col >= 0)
                        && (" O  ".equals(board.elementAt(row).elementAt(col).getText())
                        && " O  ".equals(board.elementAt(row).elementAt(col + 1).getText())
                        && " O  ".equals(board.elementAt(row).elementAt(col + 2).getText())
                        && " O  ".equals(board.elementAt(row).elementAt(col + 3).getText()))) {
                    board.elementAt(row).elementAt(col).setText(" o  ");
                    board.elementAt(row).elementAt(col + 1).setText(" o  ");
                    board.elementAt(row).elementAt(col + 2).setText(" o  ");
                    board.elementAt(row).elementAt(col + 3).setText(" o  ");

                    return 2;
                }
                if ((col >= 3 && row < size - 3)
                        && (" O  ".equals(board.elementAt(row).elementAt(col).getText())
                        && " O  ".equals(board.elementAt(row + 1).elementAt(col - 1).getText())
                        && " O  ".equals(board.elementAt(row + 2).elementAt(col - 2).getText()))
                        && " O  ".equals(board.elementAt(row + 3).elementAt(col - 3).getText())) {
                    board.elementAt(row).elementAt(col).setText(" o  ");
                    board.elementAt(row + 1).elementAt(col - 1).setText(" o  ");
                    board.elementAt(row + 2).elementAt(col - 2).setText(" o  ");
                    board.elementAt(row + 3).elementAt(col - 3).setText(" o  ");

                    return 2;
                }
                if ((col < size - 3 && row < size - 3)
                        && (" O  ".equals(board.elementAt(row).elementAt(col).getText())
                        && " O  ".equals(board.elementAt(row + 1).elementAt(col + 1).getText())
                        && " O  ".equals(board.elementAt(row + 2).elementAt(col + 2).getText()))
                        && " O  ".equals(board.elementAt(row + 3).elementAt(col + 3).getText())) {
                    board.elementAt(row).elementAt(col).setText(" o  ");
                    board.elementAt(row + 1).elementAt(col + 1).setText(" o  ");
                    board.elementAt(row + 2).elementAt(col + 2).setText(" o  ");
                    board.elementAt(row + 3).elementAt(col + 3).setText(" o  ");

                    return 2;
                }
            }
        }
        if (counter == 0) {
            JOptionPane.showMessageDialog(null, "Board is full. You can not move. You can start new game...");
            return -1;
        }
        return 0;
    }
/**
 * Set Size of Gameboard for ConnectFour
 */
    public void setSizeBoard() {
        int sizeVal;
        do {
            sizeVal = Integer.parseInt(JOptionPane.showInputDialog("Give to me size of game board :\nMax = 26 \nMin=1 :"));

        } while ((sizeVal >= 27 || sizeVal <= 0));

        size = sizeVal;
    }
/**
 * Set Game Type for ConnectFour ( P or C )
 * @param typeVal 
 */
    public void setGameType(char typeVal) {
        gameType = typeVal;
    }
/**
 * Set Rank of Player for ConnectFour
 * @param rankVal 
 */
    public void setPlayerRank(int rankVal) {
        playerRank = rankVal;
    }
/**
 * Get Game Type for ConnectFour
 * @return Game Type
 */
    public char getGameType() {
        return gameType;
    }
/**
 * Get Board Size for ConnectFour
 * @return Board Size
 */
    public int getBoardSize() {
        return size;
    }
/**
 * Get Rank of Player for ConnectFour
 * @return Rank of Player
 */
    public int getPlayerRank() {
        return playerRank;
    }
/**
 * Choose Game Type for ConnectFour 
 * Its can be P or C (p or c)
 */
    public void chooseGameType() {
        char myGameType;
        do {
            myGameType= (JOptionPane.showInputDialog("Choose game type : \nP (User vs User) \nC (User vs Computer)")).toCharArray()[0];
        } while (myGameType != 'P' && myGameType != 'p' &&myGameType != 'C' && myGameType != 'c');
        setGameType(myGameType);
    }
}
