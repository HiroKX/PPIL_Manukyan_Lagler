import java.awt.*;
import java.awt.Polygon;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferStrategy;
import java.util.Arrays;

public class WindowAWT implements WindowVisitor {
    private Frame frame;
    private BufferStrategy strategy;
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
                strategy.dispose();
                graphics.dispose();
            }
        });

        this.strategy = this.frame.getBufferStrategy();
        this.graphics = this.strategy.getDrawGraphics();

    }

    @Override
    public void visit(Polygone polygon) {
        graphics.drawPolygon(polygon.getxCoord(), polygon.getyCoord(), polygon.getxCoord().length);
    }

    @Override
    public void visit(Cercle circle) {
        graphics.drawOval((int) circle.getP().getX()-(circle.getRayon()/4),(int) circle.getP().getY()+(circle.getRayon()/2), circle.getRayon(), circle.getRayon());
    }

    @Override
    public void visit() {
        strategy.show();
    }
}
