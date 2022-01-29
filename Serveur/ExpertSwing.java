public class ExpertSwing extends ExpertDessins{

    public ExpertSwing(ExpertDessins suivant) {
        super(suivant);
    }

    @Override
    public WindowVisitor comprendreDessins(String s) throws Erreur {
        if(s.startsWith("Swing")){
            System.out.println("Swing");
            return new WindowSwing();
        }
        else{
            return null;
        }
    }
}
