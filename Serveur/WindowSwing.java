import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferStrategy;

public class WindowSwing implements WindowVisitor {
    private Frame frame;
    private BufferStrategy strategie;
    private Graphics graphics;

    public WindowSwing() {
        this.frame = new Frame("Frame toute simple");
        this.frame.setBounds(0, 0, 400, 400);
        this.frame.setVisible(true);
        this.frame.createBufferStrategy(2);
        try {
            Thread.sleep(150);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        this.frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent event) {
                frame.dispose();
                strategie.dispose();
                graphics.dispose();
            }
        });

        this.strategie = this.frame.getBufferStrategy();
        this.graphics = this.strategie.getDrawGraphics();
    }

    @Override
    public void visit(Rectangle rectangle) {
        System.out.println(" dessin Rect");
        BufferStrategy stratégie = frame.getBufferStrategy();
        Graphics graphics = stratégie.getDrawGraphics();
        graphics.drawRect(50, 50, 100, 100);
        stratégie.show();

        graphics.dispose();
    }

    @Override
    public void visit(Cercle circle) {
        System.out.println("dessin cercle");
        BufferStrategy stratégie = frame.getBufferStrategy();
        Graphics graphics = stratégie.getDrawGraphics();
        graphics.drawOval(50, 50, 100, 100);
        stratégie.show();
        graphics.dispose();
    }
}
