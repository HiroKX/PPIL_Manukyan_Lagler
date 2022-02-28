public class ExpertAwt extends ExpertLibGraphique {

    public ExpertAwt(ExpertLibGraphique suivant) {
        super(suivant);
    }

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
