import java.util.Scanner;

/**
 * classe principal que chama construtores e inicializa thrads que simulam
 * teclado, processador e disco de um computador
 */
public class TThread {

    /**
     * metodo principal, onde se inicializa o programa simulador assim que excutado
     * @param args
     */
    public static void main(String[] args){

        TTeclado teclado = new TTeclado();
        TProcessador processador = new TProcessador();
        TDisco disco=new TDisco();


        teclado.start();
        processador.start(disco.getSemaphore()); /* chamador do processador com semaforo de disco como parametro*/
        disco.start();

    }

}
