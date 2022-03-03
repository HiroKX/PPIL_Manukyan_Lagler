public class ExpertCercle extends ExpertFormes{

    public ExpertCercle(ExpertFormes suivant) {
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
        if(s.startsWith("Cercle")){
            String[] coord = s.split("-");
            if(coord.length != 5)
                throw new Erreur("Pas assez ou trop d'argument passer");
            w.visit(new Cercle(
                    new Point(Double.parseDouble(coord[1]),
                              Double.parseDouble(coord[2])),
                              Integer.parseInt(coord[3]),
                    coord[4])
            );
            return true;
        }
        else{
            return false;
        }
    }
}