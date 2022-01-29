public abstract class ExpertDessins implements Expert{

    private ExpertDessins suivant;

    public ExpertDessins(ExpertDessins suivant){
        this.suivant = suivant;
    }

    @Override
    public WindowVisitor resoudre(String s) {
        WindowVisitor w = null;
        try {
            w = comprendreDessins(s);
        } catch (Erreur e) {
            e.printStackTrace();
        }

        if(w != null){
            return w;
        }
        else{
            if(this.suivant != null){
                return this.suivant.resoudre(s);
            }
            else{
                return w;
            }
        }
    }

    public abstract WindowVisitor comprendreDessins(String s) throws Erreur;

    @Override
    public boolean resoudre(String s, WindowVisitor w) {
        return false;
    }
}
