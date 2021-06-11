import java.util.Scanner;

/**
 * classe que implementa thread usada para simular o teclado do usuario
 */
public class TTeclado implements Runnable{

    private String nome1="teclado"; /* declaracao do nome da thread  */
    private Thread teclado; /* criacao da thread teclado */

    /**
     * metodo que simula interacao de usuario com o teclado
     */
    synchronized public void run(){

        while(true){

            Scanner s= new Scanner(System.in);
            String mensagem=s.nextLine();

            if(mensagem!=null){ /* se usuario interagiu com teclado*/
            System.out.println("Thread "+Thread.currentThread().getName()+": Usuario digitou algo");
            }

        }

    }

    /**
     * metodo que inicializa construtor da thread que simula o teclado
     */
    public void start(){
        Thread teclado =new Thread(this, nome1);
        teclado.start();
    }

}
