import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class main {
    public static void main(String[] args) throws IOException {


        ExpertFormes exp = null;
        exp = new ExpertCercle(exp);
        exp = new ExpertRect(exp);

        try {
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
        }

    }
}
