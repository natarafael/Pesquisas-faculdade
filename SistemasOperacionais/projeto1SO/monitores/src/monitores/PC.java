package monitores;
import java.util.*;

// declaração e chamada de classes para simular o conceito de threads e monitors
public class PC
{
  public static void main(String [] args) {
     Buffer b = new Buffer(4);
     Produtor p = new Produtor(b);
     Consumidor c = new Consumidor(b);

     p.start();
     c.start();
  }
}

//classe para declarar variaveis e criar buffer
class Buffer {
   private char [] buffer;
   private int count = 0, in = 0, out = 0;

   Buffer(int size)
   {
      buffer = new char[size];
   }
 
   
 // metodo para adicionar informações na tela de saida simulando a produção de dados
   public synchronized void Put(char c) {
     while(count == buffer.length)  {
    	 // "wait()" função para suspender chamada de thread, liberando temporariamente a propriedade do monitor
         try { wait(); }
         catch (InterruptedException e) { } 
         finally { } 
    }
    	 
    	 
     System.out.println("Producing " + c + " ...");
     buffer[in] = c; 
     in = (in + 1) % buffer.length; 
     count++;
   //função de monitor para liberar acesso 
     notify(); 
   }
   
 // metodo para adicionar informações a tela de saida simulando o consumo de dados 
   public synchronized char Get() {
     while (count == 0)  {
         try { wait(); }
         catch (InterruptedException e) { } 
         finally { } 
    }
     char c = buffer[out]; 
     out = (out + 1) % buffer.length;
     count--;
     System.out.println("Consuming " + c + " ...");
     //função de monitor para despertar arbritariamente uma das threads que estão em wait() 
     notify(); 
     return c;
   }
}
     
//classe para representar o famoso algoritmo de produtor com uso de threads e monitors 
class Produtor extends Thread {
   private Buffer buffer;
     
   Produtor(Buffer b) { buffer = b; }
   public void run() {
     for(int i = 0; i < 10; i++) {
        buffer.Put((char)('A'+ i%26 )); }
   }
}    

//classe para representar o famoso algoritmo de produtor com uso de threads e monitors
class Consumidor extends Thread {
   private Buffer buffer;
   
   Consumidor(Buffer b) { buffer = b; }
   
   public void run() {
	  
	   
     for(int i = 0; i < 10; i++) {
        buffer.Get(); }
    
   }
} 
