public class ExpertAWT extends ExpertDessins{

    public ExpertAWT(ExpertDessins suivant) {
        super(suivant);
    }

    @Override
    public WindowVisitor comprendreDessins(String s) throws Erreur {
        if(s.startsWith("AWT")){
            System.out.println("AWT");
            return new WindowAWT();
        }
        else{
            return null;
        }
    }
}
