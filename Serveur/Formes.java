import java.awt.Color ;

public abstract class Formes {
    String nom;
    Point p;
    String color;

    public Formes(String s) {
        this.nom = "forme";
        this.color = s;
        this.p = new Point(0,0);
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public String getNom() {
        return nom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public Point getP() {
        return p;
    }

    public void setP(Point p) {
        this.p = p;
    }

    @Override
    public String toString() {
        return "Formes{" +
                "nom='" + nom + '\'' +
                ", couleur=" + color.toString() +
                '}';
    }

}
