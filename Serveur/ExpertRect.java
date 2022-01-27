public class ExpertRect extends ExpertFormes{

    public ExpertRect(ExpertFormes suivant) {
        super(suivant);
    }

    @Override
    public Formes comprendreFormes(String s) throws Erreur{
        if(s.startsWith("rect")){
            System.out.println("rectangle");
            return new Rectangle(new Point(10.3,45.2),50, 60);
        }
        else{
            return null;
        }
    }
}
