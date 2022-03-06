import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class Serveur {
    private ServerSocket server;
    private ThreadGroup groupe;
    private static Serveur instance;
    private Serveur() throws IOException {
        int portServeur = 9112;
        server = new ServerSocket(portServeur);

        System.out.println("--Serveur créé--");
        int noClient = 0;

        InetAddress cetteMachine= InetAddress.getLocalHost();
        int portLocal= server.getLocalPort();
        groupe = new ThreadGroup("socketsClients");

        System.out.println("IP du serveur : "+cetteMachine.getHostAddress());
        System.out.println("Port du serveur : "+portLocal);
    }

    public static Serveur getInstance(){
        if(instance == null){
            try {
                return new Serveur();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return instance;
    }

    public ServerSocket getServer() {
        return server;
    }

    public void setServer(ServerSocket server) {
        this.server = server;
    }

    public ThreadGroup getGroupe() {
        return groupe;
    }

    public void setGroupe(ThreadGroup groupe) {
        this.groupe = groupe;
    }
}
