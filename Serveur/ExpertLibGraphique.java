public abstract class ExpertLibGraphique implements Expert{

    private ExpertLibGraphique suivant;

    public ExpertLibGraphique(ExpertLibGraphique suivant){
        this.suivant = suivant;
    }

    /**
     * Retourne la librairie graphique dans laquelle dessiné
     * @param s
     * @return Lib graphique
     */
    @Override
    public WindowVisitor resoudre(String s) {
        WindowVisitor w = null;
        try {
            w = comprendreDessins(s);
        } catch (Erreur e) { //TODO: à déplacer plus haut / un throw?
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

    /**
     * Fonction non utilisé qui dessine dans Expert Formes
     * @param s
     * @param w
     * @return
     */
    @Override
    public boolean resoudre(String s, WindowVisitor w) {
        return false;
    }
}
