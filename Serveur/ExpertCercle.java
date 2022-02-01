public class ExpertCercle extends ExpertFormes{

    public ExpertCercle(ExpertFormes suivant) {
        super(suivant);
    }

    @Override
    public boolean comprendreFormes(String s, WindowVisitor w) throws Erreur{
        if(s.startsWith("Cercle")){
            String[] coord = s.split("-");
            if(coord.length != 4)
                throw new Erreur("Pas assez d'argument passer");
            w.visit(new Cercle(
                    new Point(Double.parseDouble(coord[1]),
                              Double.parseDouble(coord[2])),
                              Integer.parseInt(coord[3])
                              )
            );
            return true;
        }
        else{
            return false;
        }
    }
}
