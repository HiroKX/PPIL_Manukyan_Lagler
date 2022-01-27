import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.image.BufferStrategy;

class DrawClick implements MouseListener
{
    Frame frame;
    public DrawClick(Frame frame){
        this.frame = frame;
    }

    public void mousePressed(MouseEvent event)
    {
        int x = event.getX() ;
        int y = event.getY() ;

        System.out.println("oui");

        BufferStrategy stratégie = frame.getBufferStrategy();
        Graphics graphics = stratégie.getDrawGraphics();


        graphics.drawOval(x-50, y-50, 100, 100);    // dessine sur le tampon vidéo. coordonnées en dur : très maladroit
        stratégie.show();       // place le tampon sur l'écran : la technique utilisée dépend du type de stratégie utilisé : blitting, pointeur vidéo, etc.

        graphics.dispose();

    }

    public void mouseReleased(MouseEvent event){}
    public void mouseClicked(MouseEvent event){}
    public void mouseEntered(MouseEvent event){}
    public void mouseExited(MouseEvent event){}
}