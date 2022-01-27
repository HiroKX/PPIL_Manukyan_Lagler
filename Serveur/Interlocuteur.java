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

    public Interlocuteur(Socket socket, ThreadGroup groupe, ExpertFormes exp)throws IOException {
        super(groupe,"ReceveurEnvoyeur");
        this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.fluxSortant = new PrintStream(socket.getOutputStream());
        this.socket = socket;
        this.exp = exp;
    }

    @Override
    public void run() {
        try {
            while(!isInterrupted()){
                /*Lit le flux et le nettoye*/
                String requete = fluxEntrant.readLine();
                requete = requete.trim();

                /*Affiche la requête*/
                System.out.println("Le client a envoyé : " + requete);
                /**
                /*Traitement demandé
                String reponse = this.exp.resoudre(requete,w).toString();

                /*Affiche résultat et ré-envoie le flux traité
                System.out.println(reponse);
                this.fluxSortant.println(reponse);
                //sleep(5);  // est-ce utile ?*/
            }
        }
        //catch(InterruptedException erreur){}
        catch(IOException erreur) {
            System.err.println("On ne peut pas lire sur le socket provenant du client");
        }
        catch (NullPointerException erreur) {
            System.out.println("Le client s'est déconnecté.");
        }
    }
}
