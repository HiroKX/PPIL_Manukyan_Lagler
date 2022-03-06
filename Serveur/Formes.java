import java.awt.Color ;

/**
 * Classe de forme abstraites
 */
public abstract class Formes {
    String nom;
    Point p;
    String color;

    /**
     * Constructeur d'une forme
     * @param s
     */
    public Formes(String s) {
        this.nom = "forme";
        this.color = s;
        this.p = new Point(0,0);
    }

    /**
     * retourne la couleur
     * @return couleur
     */
    public String getColor() {
        return color;
    }

    /**
     * modifie la couleur
     * @param color
     */
    public void setColor(String color) {
        this.color = color;
    }

    /**
     * retourne le nom de la forme
     * @return
     */
    public String getNom() {
        return nom;
    }

    /**
     * set le nom
     * @param nom
     */
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
