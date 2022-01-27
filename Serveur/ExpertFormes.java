public abstract class ExpertFormes implements Expert{

    private ExpertFormes suivant;

    public ExpertFormes(ExpertFormes suivant){
        this.suivant = suivant;
    }

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
}
