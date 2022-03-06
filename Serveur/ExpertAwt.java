public class ExpertAwt extends ExpertLibGraphique {

    public ExpertAwt(ExpertLibGraphique suivant) {
        super(suivant);
    }

    /**
     * determine la fenetre à utilisé
     * @param s
     * @return la fenetre awt ou null si pas la bonne chaine
     * @throws Erreur
     */
    @Override
    public WindowVisitor comprendreDessins(String s) throws Erreur {
        if(s.startsWith("awt")){
            String[] coord= s.split("-");
            if(coord.length<3){
                throw new Erreur("Pas de taille donnée");
            }
            return new WindowAWT(Integer.parseInt(coord[1]),Integer.parseInt(coord[2]));
        }
        else{
            return null;
        }
    }
}
