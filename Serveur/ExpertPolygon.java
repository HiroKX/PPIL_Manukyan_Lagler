import java.awt.Polygon;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;

public class ExpertPolygon extends ExpertFormes{

    public ExpertPolygon(ExpertFormes suivant) {
        super(suivant);
    }

    @Override
    public boolean dessinerForme(String s, WindowVisitor w) throws Erreur{
        if(s.startsWith("Polygone") || s.startsWith("Segment") || s.startsWith("Triangle")){
            String[] coord= s.split("-");
            if(coord.length < 2)
                throw new Erreur("Pas assez d'argument passer");
            ArrayList<Integer> lX = new ArrayList<Integer>();
            ArrayList<Integer> lY = new ArrayList<Integer>();
            for (int i = 1 ; i < coord.length-1 ; i++) {
                String[] point = coord[i].replace("(","").replace(")","").replace(" ","").split(",");
                if(point.length < 2){
                    throw new Erreur("Nombre d'argument incorrect");
                }
                lX.add((int)Double.parseDouble(point[0]));
                lY.add((int) Double.parseDouble(point[1]));
            }
            int[] tabX = lX.stream().mapToInt(i -> i).toArray();
            int[] tabY = lY.stream().mapToInt(i -> i).toArray();
            w.visit(new Polygone(tabX,tabY,coord[coord.length-1]));
            return true;
        } 
        else{
            return false;
        }
    }
}
