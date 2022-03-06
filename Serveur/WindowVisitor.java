import java.awt.Polygon;

public interface WindowVisitor {
    /**
     * dessine un polygone
     * @param polygon
     */
    public void visit(Polygone polygon);

    /**
     * dessine un cercle
     * @param circle
     */
    public void visit(Cercle circle);

    void visit();

}
