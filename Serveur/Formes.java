import java.util.ArrayList;

public abstract class Formes {
    String nom;
    Point p;

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
                ", p=" + p +
                '}';
    }
}
