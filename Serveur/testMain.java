public class testMain {
    public static void main(String[] args){
        Cercle c = null;

        {
            try {
                c = new Cercle(new Point(10,10), 10,"yellow");
            } catch (Erreur erreur) {
                erreur.printStackTrace();
            }
        }
        System.out.println(c.toString());
    }
}
