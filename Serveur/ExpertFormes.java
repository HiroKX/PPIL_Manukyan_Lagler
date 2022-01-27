public abstract class ExpertFormes implements Expert{

    private ExpertFormes suivant;

    public ExpertFormes(ExpertFormes suivant){
        this.suivant = suivant;
    }

    @Override
    public Formes resoudre(String s) {
        Formes formes = null;
        try {
            formes = comprendreFormes(s);
        } catch (Erreur e) {
            e.printStackTrace();
        }

        if(formes != null){
            return formes;
        }
        else{
            if(this.suivant !=null){
                return this.suivant.resoudre(s);
            }
            else{
                return null;
            }
        }
    }

    public abstract Formes comprendreFormes(String s) throws Erreur;
}
