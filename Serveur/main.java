import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class main {
    public static void main(String[] args) throws IOException {
        try {
            int portServeur = 9111;
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

            }
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}
