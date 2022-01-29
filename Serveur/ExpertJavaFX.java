public class ExpertJavaFX extends ExpertDessins{

    public ExpertJavaFX(ExpertDessins suivant) {
        super(suivant);
    }

    @Override
    public WindowVisitor comprendreDessins(String s) throws Erreur {
        if(s.startsWith("JavaFX")){
            System.out.println("JavaFX");
            return new WindowJavaFX();
        }
        else{
            return null;
        }
    }
}
