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
            String[] coord = s.split("_");
            if(coord.length != 4)
                throw new Erreur("Pas assez ou trop d'argument passer");
            String[] point = coord[1].replace("(","").replace(")","").replace(" ","").split(",");
            w.visit(new Cercle(new Point(Double.parseDouble(point[0]), Double.parseDouble(point[1])), (int) Double.parseDouble(coord[2]), coord[3]));
            return true;
        }
        else{
            return false;
        }
    }
}