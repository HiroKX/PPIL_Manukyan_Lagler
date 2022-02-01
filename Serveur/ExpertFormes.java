public abstract class ExpertFormes implements Expert{

    private ExpertFormes suivant;

    public ExpertFormes(ExpertFormes suivant){
        this.suivant = suivant;
    }

    /**
     * Dessine une forme en fonction de la lib graphique en paramètre
     * @param s
     * @param w
     * @return true si dessiné
     */
    @Override
    public boolean resoudre(String s, WindowVisitor w) {
        boolean res = false;
        try {
            res = comprendreFormes(s, w);
        } catch (Erreur e) {
            e.printStackTrace();
        }

        if(res){
            return true;
        }
        else{
            if(this.suivant !=null){
                return this.suivant.resoudre(s,w);
            }
            else{
                return false;
            }
        }
    }

    public abstract boolean comprendreFormes(String s, WindowVisitor w) throws Erreur;

    /**
     * Méthode non utilisé (hérité de Expert)
     * Qui sert dans ExpertDessin pour retourner une lib graphique
     * @param s
     * @return
     */
    @Override
    public WindowVisitor resoudre(String s) {
        return null;
    }
}
