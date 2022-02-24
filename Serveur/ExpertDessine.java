public class ExpertDessine extends ExpertFormes{

    public ExpertDessine(ExpertFormes suivant) {
        super(suivant);
    }

    /**
     * Dessine un Cercle
     * @param s
     * @param w
     * @return
     * @throws Erreur
     */
    @Override
    public boolean dessinerForme(String s, WindowVisitor w) throws Erreur{
        if(s.startsWith("dessin")){
            w.visit();
            return true;
        }
        else{
            return false;
        }
    }


}