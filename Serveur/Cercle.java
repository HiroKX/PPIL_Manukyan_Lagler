public class Cercle extends Formes{

    private int rayon;

    public Cercle(Point p, int rayon,String s) throws Erreur {
        super(s);
        this.setP(p);
        this.setRayon(rayon);
    }

    public int getRayon() {
        return rayon;
    }

    public void setRayon(int rayon) throws Erreur {
        if(rayon < 0)
            throw new Erreur("Rayon inferieur à 0");
        this.rayon = rayon;
    }


    @Override
    public String toString() {
        return "Cercle{" +
                "rayon=" + rayon +
                ", nom='" + nom + '\'' +
                ", p=" + p +
                ", color =" + color +
                '}';
    }
}
