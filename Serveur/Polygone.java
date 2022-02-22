public class Polygone {

    private int[] xCoord;
    private int[] yCoord;

    public Polygone(int[] xP, int[] yP) {
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
