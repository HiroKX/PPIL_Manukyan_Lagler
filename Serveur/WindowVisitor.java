import java.awt.Polygon;

public interface WindowVisitor {
    public void visit(Polygone polygon);

    public void visit(Cercle circle);

}
