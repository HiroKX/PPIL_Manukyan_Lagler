import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class main {
    public static void main(String[] args) throws IOException {

        ExpertFormes exp = null;
        exp = new ExpertCercle(exp);
        exp = new ExpertPolygon(exp);
        exp = new ExpertDessine(exp);

        ExpertLibGraphique expD = null;
        expD = new ExpertAwt(expD);

        Serveur server = new Serveur();
        ThreadGroup groupe = server.getGroupe();
        ServerSocket serveurSocket= server.getServer();
        int noClient = 0;
        while (true) {
            Socket socket = serveurSocket.accept();
            noClient++;
            System.out.println("--Connexion réussie avec le client " + noClient + "--");
            Interlocuteur interlocuteur = new Interlocuteur(socket, groupe, exp, expD);
            interlocuteur.start();
        }
    }
}
