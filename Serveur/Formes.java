import java.util.ArrayList;

public class Formes {
    String nom;
    ArrayList<Point> lCoords= new ArrayList<Point>();

    public Formes(int i,Point x) {
        this.nom = "Cercle";
        lCoords.add(x);
    }

    public Formes(int i, Point x, Point point) {
        this.nom = "Rectangle";
        lCoords.add(x);
        lCoords.add(point);
    }
}
