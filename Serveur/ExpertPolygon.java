import java.awt.Polygon;
import java.util.ArrayList;

public class ExpertPolygon extends ExpertFormes{

    public ExpertPolygon(ExpertFormes suivant) {
        super(suivant);
    }

    @Override
    public boolean dessinerForme(String s, WindowVisitor w) throws Erreur{
        if(s.startsWith("polygon")){
            String[] coord= s.split("-");
            if(coord.length < 2)
                throw new Erreur("Pas assez d'argument passer");
            int[] tabX ={};
            int[] tabY ={};
            ArrayList<Integer> yP = new ArrayList<Integer>();
            for (int i = 1 ; i < coord.length-1 ; i+=2) {
                tabX[i] = Integer.parseInt(coord[i]);
                tabY[i] = Integer.parseInt(coord[i + 1]);
            }
            w.visit(new Polygone(tabX,tabY));

            System.out.println("rectangle");
            return true;
        }
        else{
            return false;
        }
    }
}
