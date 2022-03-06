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

    private int width, height;

    public WindowAWT(int s, int s1) {
        width = s;
        height=s1;
        this.frame = new Frame("Frame toute simple");
        this.frame.setBounds(300, 300, width, height+40);
        this.frame.setVisible(true);
        this.frame.setResizable(false);
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
        try {
            graphics.setColor((Color) Color.class.getField(polygon.getColor()).get(null));
        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }
        int[] tabY = polygon.getyCoord();
        for(int i = 0 ; i< tabY.length;i++ ){
            tabY[i] = tabY[i]+getInsetHeight();
        }
        int[] tabX = polygon.getxCoord();
        for(int i = 0 ; i< tabX.length;i++ ){
            tabX[i] = tabX[i]+getInsetMargin();
        }

        graphics.drawPolygon(tabX, tabY, polygon.getxCoord().length);
    }

    @Override
    public void visit(Cercle circle) {
        graphics.drawOval((int) circle.getP().getX()-(circle.getRayon()/2),(int) circle.getP().getY()-(circle.getRayon()/2)+this.frame.getInsets().top, circle.getRayon(), circle.getRayon());
    }

    @Override
    public void visit() {
        strategy.show();
    }

    public int getHeight() {
        return height;
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int getInsetHeight(){
        return this.frame.getInsets().top;
    }
    public int getInsetMargin(){
        return this.frame.getInsets().left;
    }

}
