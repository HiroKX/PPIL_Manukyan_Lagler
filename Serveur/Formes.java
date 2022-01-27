import java.util.ArrayList;

public class Formes {
    String nom;
    ArrayList<Point> lCoords= new ArrayList<Point>();
    private int rayon;

    @Override
    public String toString() {
        return "Formes de" +
                "nom='" + nom + '\'' +
                ", lCoords=" + lCoords +
                ", rayon=" + rayon +
                '}';
    }

    public Formes(int r, Point x) {
        this.nom = "Cercle";
        lCoords.add(x);
        rayon=r;
    }

    public Formes( Point x, Point point) {
        this.nom = "Rectangle";
        lCoords.add(x);
        lCoords.add(point);
    }
}
