import java.util.Arrays;

public class Polygone extends Formes {

    private int[] xCoord;
    private int[] yCoord;

    @Override
    public String toString() {
        return "Polygone{" +
                "xCoord=" + Arrays.toString(xCoord) +
                ", yCoord=" + Arrays.toString(yCoord) +
                '}';
    }

    public Polygone(int[] xP, int[] yP, String s) {
        super(s);
        this.setxCoord(xP);
        this.setyCoord(yP);
    }

    public int[] getxCoord() {
        return xCoord;
    }

    public void setxCoord(int[] xCoord) {
        this.xCoord = xCoord;
    }

    public int[] getyCoord() {
        return yCoord;
    }

    public void setyCoord(int[] yCoord) {
        this.yCoord = yCoord;
    }

}
