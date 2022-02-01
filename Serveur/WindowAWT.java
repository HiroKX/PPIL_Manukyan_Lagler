import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferStrategy;

public class WindowAWT implements WindowVisitor {
    private Frame frame;
    private BufferStrategy strategie;
    private Graphics graphics;

    public WindowAWT() {
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
        BufferStrategy stratégie = frame.getBufferStrategy();
        Graphics graphics = stratégie.getDrawGraphics();
        graphics.drawRect((int) rectangle.getP().getX(), (int) rectangle.getP().getY()+rectangle.getHauteur(), rectangle.getHauteur(), rectangle.getLargeur());
        stratégie.show();
        graphics.dispose();
    }

    @Override
    public void visit(Cercle circle) {
        BufferStrategy stratégie = frame.getBufferStrategy();
        Graphics graphics = stratégie.getDrawGraphics();
        graphics.drawOval((int) circle.getP().getX()-(circle.getRayon()/2), (int) circle.getP().getY(), circle.getRayon(), circle.getRayon());
        stratégie.show();
        graphics.dispose();
    }
}
