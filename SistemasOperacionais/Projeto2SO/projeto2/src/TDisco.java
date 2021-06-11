import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.concurrent.Semaphore;

/**
 * classe que implementa thread que simula o Disco
 */
public class TDisco implements Runnable{

    private Thread disco; /* criacao da variavel pra thread disco*/
    private String nome3 = "disco"; /* nomeando thread disco */
    public Semaphore semaphore= new Semaphore(1); /* criacao do semaforo para controle de acesso*/

    /**
     * metodo para obter estado atual do semaforo e compartilhar com o processador
     * @return semaphore
     */
    public Semaphore getSemaphore() {
        return semaphore;
    }

    /**
     * metodos para simulacao do backup do disco
     */
    synchronized public void run(){
        int i=1;
        BufferedWriter bw= null;

        while(true){

            try {
                semaphore.acquire();
                bw = new BufferedWriter(new FileWriter("D:\\Natã Rafael\\Faculdade\\Faculdade\\SO\\saida.txt", true));

                System.out.println("Thread "+Thread.currentThread().getName()+": Dei uma volta");
                LocalDateTime ldt = LocalDateTime.now();

                DateTimeFormatter formatandoData= DateTimeFormatter.ofPattern("dd/MM/yyyy");
                String formatadaData = formatandoData.format(ldt);

                DateTimeFormatter formatandoHora= DateTimeFormatter.ofPattern("HH:mm:ss");
                String formatadaHora = formatandoHora.format(ldt);

                bw.append(formatadaData+" "+formatadaHora+"\n");

                File file=new File("D:\\Natã Rafael\\Faculdade\\Faculdade\\SO\\backup");
                File[] arquivos = file.listFiles();

                for(File arquivo: arquivos) {

                    bw.append(arquivo.getName()+"\n");
                    System.out.println(arquivo.getName());
                }
                bw.append("\n------------------\n");

                if(arquivos.length==3) {
                    File deletandoFile=new File("D:\\Natã Rafael\\Faculdade\\Faculdade\\SO\\backup\\arquivo"+(i-3)+".txt");
                    deletandoFile.delete();
                }

                BufferedWriter arqs=new
                        BufferedWriter(new FileWriter("D:\\Natã Rafael\\Faculdade\\Faculdade\\SO\\backup\\arquivo"+i+".txt"));
                arqs.append("Boom");
                arqs.close();


                System.out.println("Disco entrou em modo sleep");
                Thread.sleep(11000);
                System.out.println("Disco saiu do modo sleep");

                i++;

                bw.close();

            } catch (InterruptedException | IOException e) {
                e.printStackTrace();
            }

        }


    }

    /**
     * metodo que inicializa construtor da thread referente ao disco
     */
    public void start(){

        Thread disco =new Thread(this, nome3);
        disco.start();
    }

}
