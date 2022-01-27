public class ExpertRect extends ExpertFormes{

    public ExpertRect(ExpertFormes suivant) {
        super(suivant);
    }

    @Override
    public boolean comprendreFormes(String s, WindowVisitor w) throws Erreur{
        if(s.startsWith("rect")){
            w.visit(new Rectangle(new Point(10,10),10,10));
            System.out.println("rectangle");
            return true;
        }
        else{
            return false;
        }
    }
}
