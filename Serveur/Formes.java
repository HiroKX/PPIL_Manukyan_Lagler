import javafx.scene.paint.Color;

import java.util.ArrayList;

public abstract class Formes {
    String nom;
    Point p;

    public Formes(String s) {
        this.color = Color.valueOf(s);
    }

    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    Color color;

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
