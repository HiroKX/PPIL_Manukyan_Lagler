import java.awt.*;
import java.io.IOException;

public class main {
    public static void main(String[] args) throws IOException {

        ExpertFormes exp = null;
        exp = new ExpertCercle(exp);
        exp = new ExpertRect(exp);
        ExpertDessins expD = null;
        expD = new ExpertSwing(expD);

        WindowVisitor w = expD.resoudre("Swing");
        exp.resoudre("Cercle-0-0-50",w);
        exp.resoudre("rect-0-0-30-30",w);


        /*try {
            int portServeur = 9112;
            ServerSocket serveur = new ServerSocket(portServeur);

            System.out.println("--Serveur Majuscule créé--");
            int noClient = 0;

            InetAddress cetteMachine= InetAddress.getLocalHost();
            int portLocal= serveur.getLocalPort();
            ThreadGroup groupe = new ThreadGroup("socketsClients");

            System.out.println("IP du serveur de majuscule : "+cetteMachine.getHostAddress());
            System.out.println("Port du serveur : "+portLocal);

            while (true) {
                Socket socket = serveur.accept();
                noClient++;
                System.out.println("--Connexion réussie avec le client " + noClient + "--");
                Interlocuteur interlocuteur = new Interlocuteur(socket, groupe, exp);

                interlocuteur.start();
            }
        }
        catch (IOException e) {
            e.printStackTrace();
        }*/

    }
}
