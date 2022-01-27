public class ExpertCercle extends ExpertFormes{

    public ExpertCercle(ExpertFormes suivant) {
        super(suivant);
    }

    @Override
    public Formes comprendreFormes(String s) throws Erreur{
        if(s.startsWith("Cercle")){
            System.out.println("Cercle");
            return new Cercle(new Point(10.3,45.2), 10);
        }
        else{
            return null;
        }
    }
}
