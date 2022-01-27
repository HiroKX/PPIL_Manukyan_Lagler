public class ExpertRect extends ExpertFormes{

    public ExpertRect(ExpertFormes suivant) {
        super(suivant);
    }

    @Override
    public Formes comprendreFormes(String s) {
        if(s.startsWith("rect")){
            System.out.println("rectangle");
            return new Formes(new Point(10.3,45.2),new Point(5.2,90.4));
        }
        else{
            return null;
        }
    }
}
