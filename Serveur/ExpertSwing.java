public class ExpertSwing extends ExpertLibGraphique {

    public ExpertSwing(ExpertLibGraphique suivant) {
        super(suivant);
    }

    @Override
    public WindowVisitor comprendreDessins(String s) throws Erreur {
        if(s.startsWith("Swing")){
            System.out.println("Swing");
            return new WindowAWT();
        }
        else{
            return null;
        }
    }
}
