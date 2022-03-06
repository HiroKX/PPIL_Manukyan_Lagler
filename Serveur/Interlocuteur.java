import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

public class Interlocuteur extends  Thread{
    /*Traitement du flux envoyé par le client, reçu par le serveur*/
    BufferedReader fluxEntrant;
    PrintStream fluxSortant;
    Socket socket;
    ExpertFormes exp;
    ExpertLibGraphique expD;
    int nbRequete;
    WindowVisitor w;

    public Interlocuteur(Socket socket, ThreadGroup groupe, ExpertFormes exp,ExpertLibGraphique expD)throws IOException {
        super(groupe,"ReceveurEnvoyeur");
        this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.fluxSortant = new PrintStream(socket.getOutputStream());
        this.expD = expD;
        this.socket = socket;
        this.exp = exp;
        this.nbRequete = 0;
    }

    @Override
    public void run() {
        try {
            String requete = fluxEntrant.readLine();
            requete = requete.trim();
            w = expD.resoudre(requete);
            while(!isInterrupted()){
                /*Lit le flux et le nettoye*/
                requete = fluxEntrant.readLine();
                requete = requete.trim();
                exp.resoudre(requete, w);
                nbRequete++;
            }
        }
        catch (NullPointerException erreur) {
            erreur.printStackTrace();
            System.out.println("Le client s'est déconnecté.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}