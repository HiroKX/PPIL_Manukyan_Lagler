public class ExpertRect extends ExpertFormes{

    public ExpertRect(ExpertFormes suivant) {
        super(suivant);
    }

    @Override
    public boolean dessinerForme(String s, WindowVisitor w) throws Erreur{
        if(s.startsWith("rect")){
            String[] coord= s.split("-");
            if(coord.length != 5)
                throw new Erreur("Pas assez d'argument passer");
            w.visit(new Rectangle(new Point(Double.parseDouble(coord[1]),
                                            Double.parseDouble(coord[2])),
                                            Integer.parseInt(coord[3]),
                                            Integer.parseInt(coord[4])));

            System.out.println("rectangle");
            return true;
        }
        else{
            return false;
        }
    }
}
