public interface Expert {
    /**
     * dessine
     * @param s
     * @param w
     * @return
     */
    boolean resoudre(String s, WindowVisitor w) ;

    /**
     * Retourne la lib graphique
     * @param s
     * @return
     */
    WindowVisitor resoudre(String s);//TODO: à éliminer ?
}
