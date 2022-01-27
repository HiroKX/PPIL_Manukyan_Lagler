public class ExpertCercle extends ExpertFormes{

    public ExpertCercle(ExpertFormes suivant) {
        super(suivant);
    }

    @Override
    public boolean comprendreFormes(String s, WindowVisitor w) throws Erreur{
        if(s.startsWith("Cercle")){
            w.visit(new Cercle(new Point(10,10),10));
            System.out.println("Cercle");
            return true;
        }
        else{
            return false;
        }
    }
}
