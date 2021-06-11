import java.util.concurrent.Semaphore;


/**
 * Classe que implementa a thread que simula o processador
 */
public class TProcessador implements Runnable{


    private String nome2="processador";  /* nome da Thread */
    private Thread processador;  /* declaração da Trhead processador */
    private Semaphore sema = null;  /*semaforo usado pela Thread correspondente ao semaforo do "disco"*/

    int vetor[]= new int[51];   //representa  memoria
    int i=0;

    synchronized public void run(){

        for (i=0;i<vetor.length;i++){  /* loop para preencher vetor que representa memória */
            vetor[i]+=i;
        }

    i=0;
        while(true){

            try {
                System.out.print("Thread "+Thread.currentThread().getName()+": Executei uma instrução ");


                processa();
                System.out.println();

                Thread.sleep(2000);

            }catch (InterruptedException e){
                e.printStackTrace();
            }

        }
    }

    /**
     * função que imprime valor do processo atual e da up() no semaforo, ate o fim do vetor depois retorna
     * para o laço do processo
     * @return null;
     */
    public void processa(){

                if (i<vetor.length){
                    System.out.println(vetor[i]);
                    if (vetor[i] % 4 == 0) {
                        System.out.println("to dando release: " + vetor[i]);
                        sema.release();
                    }
                }


                i++;
                if(i == (vetor.length-1)) return;


    }

    /**
     * metoto que inicializa construtor da thread e obtem valor do semaforo já inilializado no Disco
     * @param semaphore
     */
    public void start(Semaphore semaphore){
        sema=semaphore;
        Thread processador =new Thread(this, nome2);
        processador.start();
    }

}
