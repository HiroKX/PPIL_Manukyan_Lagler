public class ExpertCercle extends ExpertFormes{

    public ExpertCercle(ExpertFormes suivant) {
        super(suivant);
    }

    @Override
    public Formes comprendreFormes(String s) {
        if(s.startsWith("Cercle")){
            System.out.println("Cercle");
            return new Formes(10,new Point(10.3,45.2));
        }
        else{
            return null;
        }
    }
}
