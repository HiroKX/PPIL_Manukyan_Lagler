import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferStrategy;

public class Window extends JFrame {
    public Window() {
            /*super("Window");
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            setVisible(true);
            setSize(1000, 1000);*/
            super("Window");
            addWindowListener(new WindowAdapter() {
                @Override
                public void windowClosing(WindowEvent e) {
                    dispose();
                    System.exit(0);
                }
            });
            setBounds(30, 60, 400, 400);
            setVisible(true);
            setIgnoreRepaint(true);
            int numBuffers = 2;
            createBufferStrategy(numBuffers);
            try {
                Thread.sleep(150);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            BufferStrategy stratégie = getBufferStrategy();
            Graphics graphics = stratégie.getDrawGraphics();
            // le graphics sert à dessiner sur le tampon

            System.out.println("ouiiiii");

            DrawClick mListener = new DrawClick(this);
            //f1AR.addMouseListener(mListener);

            addMouseListener( mListener);
            stratégie.show();       // place le tampon sur l'écran : la technique utilisée dépend du type de stratégie utilisé : blitting, pointeur vidéo, etc.
            graphics.dispose();

    }

    public void DessinerCercle(Cercle cercle){

    }
}
