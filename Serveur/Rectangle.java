public class Rectangle extends Formes{
    private int hauteur;
    private int largeur;

    public Rectangle(Point p, int hauteur, int largeur) throws Erreur{
        this.setP(p);
        this.setHauteur(hauteur);
        this.setLargeur(largeur);
    }

    public int getHauteur() {
        return hauteur;
    }

    public void setHauteur(int hauteur) throws Erreur{
        if(hauteur < 0)
            throw new Erreur("Hauteur inferieur à 0");
        this.hauteur = hauteur;
    }

    public int getLargeur() {
        return largeur;
    }

    public void setLargeur(int largeur) throws Erreur{
        if(largeur < 0)
            throw new Erreur("Largeur inferieur à 0");
        this.largeur = largeur;
    }
}
